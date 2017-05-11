/**
 * Copyright (c) 2017. The WRENCH Team.
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 */

#ifndef WRENCH_SIMPLEDYNAMICOPTIMIZATION_H
#define WRENCH_SIMPLEDYNAMICOPTIMIZATION_H

#include "wms/optimizations/dynamic/DynamicOptimization.h"

namespace wrench {

    /***********************/
    /** \cond DEVELOPER    */
    /***********************/

    /**
     *  @brief A simple task clustering algorithm to group tasks in a pipeline
     */
    class SimpleDynamicClusteringForFailures : public DynamicOptimization {
    public:
        void process(Workflow *workflow);

    };

    /***********************/
    /** \endcond           */
    /***********************/
}

#endif //WRENCH_SIMPLEDYNAMICOPTIMIZATION_H
