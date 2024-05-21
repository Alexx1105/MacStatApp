//
//  smc.h
//  MacStatApp
//
//  Created by alex haidar on 2/27/24.
//

#ifndef smc_h
#define smc_h

#include <stdint.h>
#include <mach/mach.h>
#include <IOKit/IOKitLib.h>


    
    typedef struct {
        uint32_t datasize;
        uint32_t datatype;
        uint8_t data[8];
        
    } SMCVal_t;
    
    extern io_connect_t conn;
    
    kern_return_t openSMC(void);
    kern_return_t closeSMC(void);
    kern_return_t readSMC(char *smcKeys, SMCVal_t *val);
    
   
    
#endif /* smc_h */
