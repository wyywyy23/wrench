/**
 * Copyright (c) 2017. The WRENCH Team.
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *
 *  @brief WRENCH::MulticoreTaskExecutorDaemon implements the daemon for the
 *  MultucoreTaskExecutor  Compute Service abstraction.
 */

#include "compute_services/multicore_task_executor/MulticoreTaskExecutorDaemon.h"
#include "exception/WRENCHException.h"
#include "simgrid_S4U_util/S4U_Mailbox.h"
#include "simgrid_S4U_util/S4U_Simulation.h"

XBT_LOG_NEW_DEFAULT_CATEGORY(multicore_task_executor_daemon, "Log category for Multicore Task Executor Daemon");

namespace wrench {

	/**
	 * @brief Constructor
	 *
	 * @param executors is a vector of sequential task executor compute services
	 * @param cs is a pointer to the compute service for this daemon
	 */
	MulticoreTaskExecutorDaemon::MulticoreTaskExecutorDaemon(
			std::vector<SequentialTaskExecutor *> executors,
			ComputeService *cs) : S4U_DaemonWithMailbox("multicore_task_executor", "multicore_task_executor") {

		// Initialize the set of idle executors (cores)
		this->idle_sequential_task_executors = {};
		for (int i = 0; i < executors.size(); i++) {
			this->idle_sequential_task_executors.insert(executors[i]);
		}

		// Initialize the set of busy executors (cores)
		this->busy_sequential_task_executors = {};

		// Set the pointer to the corresponding compute service
		this->compute_service = cs;

		// Initialize the task queues
		this->waiting_task_queue = {};
		this->running_task_set = {};
	}

	/**
	 * @brief Whether the executor has at least an idle core
	 *
	 * @return True when idle
	 */
	bool MulticoreTaskExecutorDaemon::hasIdleCore() {
		return this->idle_sequential_task_executors.size() > 0;
	}

	/**
	 * @brief Main method of the daemon
	 *
	 * @return 0 on termination
	 */
	int MulticoreTaskExecutorDaemon::main() {
		XBT_INFO("New Multicore Task Executor starting (%s) with %ld cores ",
		         this->mailbox_name.c_str(), this->idle_sequential_task_executors.size());

		bool keep_going = true;
		while (keep_going) {

			// Wait for a message
			std::unique_ptr<SimulationMessage> message = S4U_Mailbox::get(this->mailbox_name);

			// Process the message
			switch (message->type) {

				case SimulationMessage::STOP_DAEMON: {

					XBT_INFO("Asked to terminate");

					// Kill all running sequential executors
					for (auto executor : this->busy_sequential_task_executors) {
						XBT_INFO("Killing a sequential task executor");
						executor->kill();
					}

					// Cleanly terminate all idle sequential executors
					for (auto executor : this->idle_sequential_task_executors) {
						executor->stop();
					}

					// Update task states and send all appropriate "task failed" messages
					for (auto failed_task : this->running_task_set) {
						failed_task->state = WorkflowTask::READY; // Make the task ready again
						S4U_Mailbox::put(failed_task->getCallbackMailbox(),
						                 new TaskFailedMessage(failed_task, this->compute_service));
					}

					// Break out of the mail loop
					keep_going = false;
					break;
				}

				case SimulationMessage::RUN_TASK: {
					std::unique_ptr<RunTaskMessage> m(static_cast<RunTaskMessage *>(message.release()));

					XBT_INFO("Asked to run task %s", m->task->id.c_str());

					// Just add the task to the task queue
					this->waiting_task_queue.push(m->task);

					break;
				}

				case SimulationMessage::TASK_DONE: {
					std::unique_ptr<TaskDoneMessage> m(static_cast<TaskDoneMessage *>(message.release()));

					XBT_INFO("One of my cores completed task %s", m->task->id.c_str());

					// Remove the task from the running task queue
					this->running_task_set.erase(m->task);

					// Put that core's executor back into the pull of idle cores
					SequentialTaskExecutor *executor = (SequentialTaskExecutor *) (m->compute_service);
					this->busy_sequential_task_executors.erase(executor);
					this->idle_sequential_task_executors.insert(executor);

					// Send the callback to the originator
					S4U_Mailbox::put(m->task->getCallbackMailbox(),
					                 new TaskDoneMessage(m->task, this->compute_service));
					break;
				}

				default: {
					throw WRENCHException("Unknown message type");
				}
			}

			// Run tasks while possible
			while ((waiting_task_queue.size() > 0) && (idle_sequential_task_executors.size() > 0)) {
				// Get the task to run the first task on the first idle core
				WorkflowTask *to_run = waiting_task_queue.front();
				waiting_task_queue.pop();

				// Get an idle sequential task executor and mark it as busy
				SequentialTaskExecutor *executor = *(this->idle_sequential_task_executors.begin());
				this->idle_sequential_task_executors.erase(executor);
				this->busy_sequential_task_executors.insert(executor);

				// Start the task on the sequential task executor
				XBT_INFO("Running task %s on one of my cores", to_run->id.c_str());
				to_run->push_callback_mailbox(this->mailbox_name);
				executor->runTask(to_run);

				// Put the task in the running task set
				this->running_task_set.insert(to_run);
			}
		}

		XBT_INFO("Multicore Task Executor Daemon on host %s terminated!", S4U_Simulation::getHostName().c_str());
		return 0;
	}

};
