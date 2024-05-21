//
//  ramUsage.c
//  MacStatApp
//
//  Created by alex haidar on 3/1/24.
//

#include "ramUsage.h"
#include <mach/mach.h>
#include <stdio.h>
#include <IOKit/IOKitLib.h>
#include <mach/task_info.h>

uint32_t dataSize = sizeof(mach_task_basic_info_data_t);

kern_return_t kernMem(mach_task_basic_info_data_t * storeMemData) {
  return task_info(mach_task_self(), MACH_TASK_BASIC_INFO,(task_info_t) storeMemData, &dataSize);   //task_info method returns dta of current task passing parameters that get size of task, and current task
    
}



