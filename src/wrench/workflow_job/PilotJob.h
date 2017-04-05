/**
 * Copyright (c) 2017. The WRENCH Team.
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *
 * @brief TBD
 */

#ifndef WRENCH_PILOTJOB_H
#define WRENCH_PILOTJOB_H


#include <compute_services/multicore_job_executor/MulticoreJobExecutorDaemon.h>
#include "WorkflowJob.h"

namespace wrench {

		class ComputeService;

		class PilotJob : public WorkflowJob {

		public:
				enum State {
						NOT_SUBMITTED,
						PENDING,
						RUNNING,
						EXPIRED,
						FAILED
				};

				int num_cores;
				double duration;

				ComputeService *getComputeService();

				// Should be excluded from documentation
				void setComputeService(ComputeService*);


		private:

				friend class JobManager;
				friend class JobManagerDaemon;

				PilotJob(Workflow *workflow, int, double);
				PilotJob::State getState();
				void stop();

				State state;
				ComputeService *compute_service; // Associated compute service
		};

};


#endif //WRENCH_PILOTJOB_H