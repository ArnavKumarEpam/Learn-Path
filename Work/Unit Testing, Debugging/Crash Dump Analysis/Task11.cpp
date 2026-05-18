// mt_crash.cpp
#include <iostream>
#include <thread>
#include <chrono>

int* shared_ptr = nullptr;

void writer() {
    shared_ptr = new int(42);
    std::this_thread::sleep_for(std::chrono::milliseconds(50));
    delete shared_ptr;
    shared_ptr = nullptr;
}

void reader() {
    for (int i = 0; i < 10; ++i) {
        if (shared_ptr) {
            // Potentially dereferencing after delete!
            std::this_thread::sleep_for(std::chrono::milliseconds(20));
            std::cout << "Read value: " << *shared_ptr << std::endl;
        }
        std::this_thread::sleep_for(std::chrono::milliseconds(10));
    }
}

int main() {
    std::thread t1(writer);
    std::thread t2(reader);
    t1.join();
    t2.join();
    return 0;
}


// arnavkumar@EPINHYDW182F:/mnt/c/Users/ArnavKumar/OneDrive - EPAM/Work/Unit Testing, Debugging/Crash Dump Analysis$ g++ -g -o T11 Task11.cpp -pthread
// arnavkumar@EPINHYDW182F:/mnt/c/Users/ArnavKumar/OneDrive - EPAM/Work/Unit Testing, Debugging/Crash Dump Analysis$ ./T11
// Read value: 42
// Read value: 42
// Read value: 42
// Read value: 42
// Read value: 42
// arnavkumar@EPINHYDW182F:/mnt/c/Users/ArnavKumar/OneDrive - EPAM/Work/Unit Testing, Debugging/Crash Dump Analysis$ gdb ./T11
// GNU gdb (Ubuntu 17.1-2ubuntu1) 17.1
// Copyright (C) 2025 Free Software Foundation, Inc.
// License GPLv3+: GNU GPL version 3 or later <http://gnu.org/licenses/gpl.html>
// This is free software: you are free to change and redistribute it.
// There is NO WARRANTY, to the extent permitted by law.
// Type "show copying" and "show warranty" for details.
// This GDB was configured as "x86_64-linux-gnu".
// Type "show configuration" for configuration details.
// --Type <RET> for more, q to quit, c to continue without paging--c
// For bug reporting instructions, please see:
// <https://www.gnu.org/software/gdb/bugs/>.
// Find the GDB manual and other documentation resources online at:
//     <http://www.gnu.org/software/gdb/documentation/>.

// For help, type "help".
// Type "apropos word" to search for commands related to "word"...
// Reading symbols from ./T11...
// (gdb) run
// Starting program: /mnt/c/Users/ArnavKumar/OneDrive - EPAM/Work/Unit Testing, Debugging/Crash Dump Analysis/T11 

// This GDB supports auto-downloading debuginfo from the following URLs:
//   <https://debuginfod.ubuntu.com>
// Enable debuginfod for this session? (y or [n]) y
// Debuginfod has been enabled.
// To make this setting permanent, add 'set debuginfod enabled on' to .gdbinit.
// [Thread debugging using libthread_db enabled]
// Using host libthread_db library "/usr/lib/x86_64-linux-gnu/libthread_db.so.1".
// [New Thread 0x7ffff77ff6c0 (LWP 1860)]
// [New Thread 0x7ffff6ffe6c0 (LWP 1861)]
// Read value: 42
// Read value: 42
// Read value: 42
// Read value: 42
// Read value: 42
// [Thread 0x7ffff77ff6c0 (LWP 1860) exited]
// [Thread 0x7ffff6ffe6c0 (LWP 1861) exited]
// [Inferior 1 (process 1855) exited normally]
// (gdb) thread apply all bt
// (gdb) 