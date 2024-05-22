# CPU and Memory Temperature and Usage Tracking

This project provides a CPU temperature tracking feature and a memory usage tracking feature. It is designed to access the System Management Controller (SMC) to read and display the CPU temps in Fahrenheit aswell as memory usage in gb.

## Features

---

### CPU Temperature Tracking

- **Functionality**: Accesses the System Management Controller (SMC), reads raw data, and converts it to human-readable Fahrenheit.
- **Implementation**:
  - Access the SMC and clones its dictionary using service matching.
  - Reads the raw mutable data from the SMC.
  - Usages bridging headers to convert the C code that retrieved the data into "swift friendly" form.
  - Close the SMC.
  - Swift calls these C functions and preforms the data value conversion to F° to be displayed to the end user
- **Challenges**:
  - Finding specific SMC keys for the new 3nm M3 Pro chips.
  - Working with low-level memory without proper documentation for what I was trying to accomplish .
  - Lack of an SDK from Apple for temperature tracking, IOKit is the closest I had.

---

### Memory Tracking

- **Functionality**: Tracks memory usage of the current task using the mach library built into C.
- **Current Status**:
  - Can return memory usage of the current task.
  - Working on troubleshooting issues with `proc_allinfo` for system-wide memory usage.

---

## Implementation Details

### CPU Temperature Tracking

This feature was implemented in C and Objective-C. The process involves:

1. Opening the SMC.
2. Cloning a matching dictionary using `IOServiceMatching`.
3. Reading data from the SMC.
4. Converting raw mutable data into a form Swift can interact with.
5. Converting the data to Fahrenheit.
6. Closing the SMC.

---

### Memory Tracking

This feature uses the mach library in C to track memory usage. Currently, it can only return the memory usage of the current task. Further work is being done to enable system-wide memory usage tracking using `proc_allinfo`.

---

## Acknowledgements

Special thanks to various GitHub forums and communities for providing the necessary SMC keys for the M3 Pro and Max chips. The biggest help and inspo for at least giving me an idea of what i need to do is https://github.com/macmade/Hot

---


Feel free to contribute to this project by submitting issues or pull requests. I'm also all ears for advice regarding troubleshooting some of the mentioned challenges and invite more experienced devs to contact me.

---

For more information, contact me :3 alexh2877@gmail.com 

---

This README provides an overview of the project's features, implementation details, challenges faced, and how to contribute. If you have any questions or need further assistance, please don't hesitate to reach out.
