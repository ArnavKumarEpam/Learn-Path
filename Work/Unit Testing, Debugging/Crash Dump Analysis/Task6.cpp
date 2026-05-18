// div_by_zero.cpp
#include <iostream>
int main() {
    int a = 10 / 0; // Division by zero
    std::cout << "Result: " << a << std::endl;
    return 0;
}

// Starting program: /mnt/c/Users/ArnavKumar/OneDrive - EPAM/Work/Unit Testing, Debugging/Crash Dump Analysis/T6 

// This GDB supports auto-downloading debuginfo from the following URLs:
//   <https://debuginfod.ubuntu.com>
// Enable debuginfod for this session? (y or [n]) y
// Debuginfod has been enabled.
// To make this setting permanent, add 'set debuginfod enabled on' to .gdbinit.
// [Thread debugging using libthread_db enabled]
// Using host libthread_db library "/usr/lib/x86_64-linux-gnu/libthread_db.so.1".

// Program received signal SIGFPE, Arithmetic exception.
// 0x00005555555551a0 in main () at Task6.cpp:4
// 4           int a = 10 / 0; // Division by zero
// (gdb) 