

This project has a CPU temperature tracking feature that is meant work by accessing the System Management Controller or "SMC" and cloning its dictionary, reading the data from the SMC, then returning the raw mutable data values to be converted and printed in human readable fahrenheight form.

I did much searching to find the specific SMC keys for the new 3nm M3 pro chips and came across a few Github forums that had all the SMC keys for the M3 pro and Max chips which I incorperated into my program. Dealing with low level memory was the hardest as there was no real documentation for what I am trying to accomplish,

and apple does not offer any sort of SDK for temp tracking a machine's CPU. This part of the project was done in C and obj-C and the general flow of accessing this data was to open the SMC, clone a matching dictionary using IOServiceMatching, reading the data from the smc,

converting the raw mutable data into a form swift could interact with it by using bridging headers to then convert the data to Fahrenheight, then closing the SMC. 



The second part of this project is the memory tracking feature, this was done using the mach library built into C.

right now the program only can return the memory usage of a current task rather than system wide memory usage as I am still troubleshooting some issues im having with the proc_allinfo method that should allow system wide memory usage to be shown.
