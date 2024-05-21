//
//  smc.c
//  MacStatApp
//
//  Created by alex haidar on 2/27/24.
//


#include <stdio.h>
#include "smc.h"
#include <mach/mach.h>
#include <IOKit/IOKitLib.h>




io_connect_t conn;

kern_return_t openSMC(void)  {
    
    kern_return_t result;
    kern_return_t service;
    io_iterator_t iterator;

    service = IOServiceGetMatchingServices(kIOMainPortDefault, IOServiceMatching("AppleSMC"), &iterator);
    if(service == 0) {
        printf("error: could not match dictionary");
        return 0;
    }
    result = IOServiceOpen(service, mach_task_self(), 0, &conn);
    IOObjectRelease(service);
    return 0;
}


kern_return_t readSMC(char *smcKeys, SMCVal_t *val) {
kern_return_t result;
uint32_t keyCode = *(uint32_t *)smcKeys;

SMCVal_t inputStruct;
SMCVal_t outputStruct;

inputStruct.datasize = sizeof(SMCVal_t);
inputStruct.datatype = 'I' << 24;         //a left shift operation. turning the I into an int by shifting the ASCII value 24 bits to the left

inputStruct.data[0] = keyCode;
result = IOConnectCallStructMethod(conn, 5, &inputStruct, sizeof(SMCVal_t), &outputStruct, (size_t*)&inputStruct.datasize);

if (result == kIOReturnSuccess) {
    if (val -> datasize > 0) {
        if (val -> datatype == ('f' << 24 | 'l' << 16 | 't' << 8 )) {    //bit shifting 32bit operation associated with the ASCII charecters'f', 'l', and 't', sets datatype field.
            double temp = *(double *)val -> data;
            return temp;
        }
    }
}
return 0.0;

}

kern_return_t closeSMC(void) {
    return IOServiceClose(conn);
}






