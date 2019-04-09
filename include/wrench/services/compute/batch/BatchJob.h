#ifndef WRENCH_BATCHJOB_H
#define WRENCH_BATCHJOB_H

#include "wrench/workflow/job/StandardJob.h"

namespace wrench {

    /***********************/
    /** \cond INTERNAL    */
    /***********************/

    /**
     * @brief A batch job, which encapsulates a WorkflowJob and additional information
     *        used by a BatchService
     */
    class BatchJob {
    public:
        //job, jobid, -t, -N, -c, ending s4u_timestamp (-1 as undetermined)
        BatchJob(WorkflowJob* job, unsigned long jobid, unsigned long time_in_minutes, unsigned long number_nodes,
                 unsigned long cores_per_node,double ending_time_stamp, double arrival_time_stamp);


        unsigned long getJobID();
        unsigned long getAllocatedTime();
        void setAllocatedTime(unsigned long time);
        unsigned long getAllocatedCoresPerNode();
        double getMemoryRequirement();
        double getBeginTimeStamp();
        void setBeginTimeStamp(double time_stamp);
        double getEndingTimeStamp();
        double getArrivalTimeStamp();
        unsigned long getNumNodes();
        WorkflowJob* getWorkflowJob();
        void setEndingTimeStamp(double time_stamp);
        std::map<std::string, std::tuple<unsigned long, double>> getResourcesAllocated();
        void setAllocatedResources(std::map<std::string, std::tuple<unsigned long, double>> resources);

    private:
        unsigned long jobid;
        unsigned long  allocated_time;
        WorkflowJob* job;
        unsigned long num_nodes;
        unsigned long cores_per_node;
        double begin_time_stamp;
        double ending_time_stamp;
        double arrival_time_stamp;
        std::map<std::string, std::tuple<unsigned long, double>> resources_allocated;

    public:
        // Variables below are for the BatSim-style CVS output log file (only ifdef ENABLED_BATSCHED)
        /** @brief The meta-data field for BatSim-style CSV output */
        std::string csv_metadata;
        /** @brief The allocated processors field for BatSim-style CSV output */
        std::string csv_allocated_processors; 
    };

    /***********************/
    /** \endcond           */
    /***********************/

}




#endif //WRENCH_BATCHJOB_H
