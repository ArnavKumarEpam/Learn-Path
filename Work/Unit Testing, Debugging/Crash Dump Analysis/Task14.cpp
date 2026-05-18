// vtable_crash.cpp
#include <iostream>
class Base {
public:
    virtual void foo() { std::cout << "Base::foo" << std::endl; }
    virtual ~Base() {}
};
class Derived : public Base {
public:
    void foo() override { std::cout << "Derived::foo" << std::endl; }
};

int main() {
    Base* obj = new Derived();
    delete obj;
    obj->foo(); // CRASH: call virtual on deleted object
    return 0;
}


// arnavkumar@EPINHYDW182F:/mnt/c/Users/ArnavKumar/OneDrive - EPAM/Work/Unit Testing, Debugging/Crash Dump Analysis$ g++ -g -o T14 Task14.cpp
// arnavkumar@EPINHYDW182F:/mnt/c/Users/ArnavKumar/OneDrive - EPAM/Work/Unit Testing, Debugging/Crash Dump Analysis$ ./T14
// Segmentation fault         ./T14
// arnavkumar@EPINHYDW182F:/mnt/c/Users/ArnavKumar/OneDrive - EPAM/Work/Unit Testing, Debugging/Crash Dump Analysis$ gdb ./T14
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
// Reading symbols from ./T14...
// (gdb) run
// Starting program: /mnt/c/Users/ArnavKumar/OneDrive - EPAM/Work/Unit Testing, Debugging/Crash Dump Analysis/T14 

// This GDB supports auto-downloading debuginfo from the following URLs:
//   <https://debuginfod.ubuntu.com>
// Enable debuginfod for this session? (y or [n]) y
// Debuginfod has been enabled.
// To make this setting permanent, add 'set debuginfod enabled on' to .gdbinit.
// [Thread debugging using libthread_db enabled]
// Using host libthread_db library "/usr/lib/x86_64-linux-gnu/libthread_db.so.1".

// Program received signal SIGSEGV, Segmentation fault.
// 0x000055555555520b in main () at Task14.cpp:16
// 16          obj->foo(); // CRASH: call virtual on deleted object
// (gdb) bt
// #0  0x000055555555520b in main () at Task14.cpp:16
// (gdb) l
// 11      };
// 12
// 13      int main() {
// 14          Base* obj = new Derived();
// 15          delete obj;
// 16          obj->foo(); // CRASH: call virtual on deleted object
// 17          return 0;
// 18      }
// (gdb) 