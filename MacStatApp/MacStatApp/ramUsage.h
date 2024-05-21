//
//  ramUsage.h
//  MacStatApp
//
//  Created by alex haidar on 3/1/24.
//

#ifndef ramUsage_h
#define ramUsage_h

#include <stdio.h>
#include <mach/mach.h>
#include <IOKit/IOKitLib.h>
#include <mach/task_info.h>



struct mach_task_basic_info_data_t;
    
extern kern_return_t kernMem(mach_task_basic_info_data_t* storeMemData);  //kernMem function returns current task, the tasks info,and task size using task_info method



#endif /* ramUsage_h */
