//
//  temperature.swift
//  MacStatApp
//
//  Created by alex haidar on 2/26/24.
//

import Foundation
import IOKit




public class getTemperature {
    
    public struct SMCVal_t {
        var datasize: UInt32
        var datatype: UInt32
        var data: [UInt8]
    }
        
        
       
        func readSMC(smcKeys:UnsafePointer<CChar>, val:UnsafeMutablePointer<SMCVal_t> ) {
            
            let openSM = openSMC()
            guard openSM == 0 else {
                print("Failed to open SMC: \(openSM)")
                   return
               
            }
            
                 var smcVal = SMCVal_t( datasize: 0, datatype: 0 , data:[0])
                 let getTemp = getTemperature()
                
            let readSM = getTemp.readSMC(smcKeys: smcKeys, val: &smcVal)
            
        }
        
        func convertAndPrintTempValue(key:UnsafePointer<CChar>?,scale: Character, showTemp: Bool ) -> kern_return_t {
            
            
            func convertAndPrint(val: SMCVal_t) -> Double {
                if val.datatype == (UInt32("f".utf8.first!) << 24 | UInt32("l".utf8.first!) << 16 | UInt32("t".utf8.first!) << 8)  {
                    let extractedTemp = Double(val.data[0])
                    return(extractedTemp * 9.0 / 5.0 + 32.0)
                }
                return 0.0
            }
            
            let smcValue = SMCVal_t(datasize: 0, datatype: 0, data: [0])
            let convertedVal = convertAndPrint(val: smcValue)
            
            print("Temperarure:\(convertedVal)F°")
            
            
            
            let closeSM = closeSMC()
            guard closeSM == 0 else {
                print("could not close SMC: \(closeSM)")
                exit(0)
                
            }
               return kern_return_t()
        }
   
        
    }



