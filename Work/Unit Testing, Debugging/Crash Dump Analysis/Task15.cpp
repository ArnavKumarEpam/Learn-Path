 
    // signal_logger.cpp
#include <csignal>
#include <iostream>
#include <cstdlib>
void handler(int sig) {
    std::cerr << "Crash: received signal " << sig << std::endl;
    std::_Exit(1);
}
int main(int argc, char** argv) {
    signal(SIGSEGV, handler);
    signal(SIGFPE, handler);
    // ... call buggy logic here
    int* ptr = nullptr;
    *ptr = 100; // Trigger SIGSEGV
    return 0;
}


// arnavkumar@EPINHYDW182F:/mnt/c/Users/ArnavKumar/OneDrive - EPAM/Work/Unit Testing, Debugging/Crash Dump Analysis$ g++ -g -o T15 Task15.cpp
// arnavkumar@EPINHYDW182F:/mnt/c/Users/ArnavKumar/OneDrive - EPAM/Work/Unit Testing, Debugging/Crash Dump Analysis$ ./T15
// Crash: received signal 11
// arnavkumar@EPINHYDW182F:/mnt/c/Users/ArnavKumar/OneDrive - EPAM/Work/Unit Testing, Debugging/Crash Dump Analysis$ arnavkumar@EPINHYDW182F:/mnt/c/Users/ArnavKumar/OneDrive - EPAM/Work/Unit Testing, Debugging/Crash Dump Analysis$ gdb ./T15
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
// Reading symbols from ./T15...
// (gdb) run
// Starting program: /mnt/c/Users/ArnavKumar/OneDrive - EPAM/Work/Unit Testing, Debugging/Crash Dump Analysis/T15 

// This GDB supports auto-downloading debuginfo from the following URLs:
//   <https://debuginfod.ubuntu.com>
// Enable debuginfod for this session? (y or [n]) y
// Debuginfod has been enabled.
// To make this setting permanent, add 'set debuginfod enabled on' to .gdbinit.
// [Thread debugging using libthread_db enabled]
// Using host libthread_db library "/usr/lib/x86_64-linux-gnu/libthread_db.so.1".

// Program received signal SIGSEGV, Segmentation fault.
// 0x0000555555555264 in main (argc=1, argv=0x7fffffffdec8) at Task15.cpp:15
// 15          *ptr = 100; // Trigger SIGSEGV
// (gdb) bt
// #0  0x0000555555555264 in main (argc=1, argv=0x7fffffffdec8) at Task15.cpp:15
// (gdb) l
// 10      int main(int argc, char** argv) {
// 11          signal(SIGSEGV, handler);
// 12          signal(SIGFPE, handler);
// 13          // ... call buggy logic here
// 14          int* ptr = nullptr;
// 15          *ptr = 100; // Trigger SIGSEGV
// 16          return 0;
// 17      }
// (gdb) 