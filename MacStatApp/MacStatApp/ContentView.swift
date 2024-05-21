//
//  ContentView.swift
//  MacStatApp
//
//  Created by alex haidar on 2/26/24.
//

import SwiftUI
import Foundation


struct ContentView: View {

    @State public var displayMemoryData = ""
   
    
    var body: some View {
        

        
        VStack {
            Image("bar")
                .padding(4)
                .scaledToFit()
            
               Text(displayMemoryData)
                .offset(x: 190, y: -90)
                .font(Font.custom("arial", size: 13).weight(.bold))
            
            
                .onAppear() {
                          var storememData = mach_task_basic_info_data_t()
                    
                         let result = kernMem(&storememData)
                         if result == KERN_SUCCESS {
                        let residentSize = Double(storememData.resident_size) / (1024.0 * 1024.0 * 1024.0)
                            displayMemoryData = String(format: " %.2f GB", residentSize)
                         } else {
                             print("failed to obtain memory usage data:\(result)")
                         }
                    
                }
                
            }
        }
    }

