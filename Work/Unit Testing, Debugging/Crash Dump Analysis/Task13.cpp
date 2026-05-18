// rect_segfault.cpp
#include <iostream>
class Rectangle {
    int width, height;
public:
    Rectangle(int w, int h) : width(w), height(h) {}
    int area() const { return width * height; }
};

int main() {
    Rectangle* rect = new Rectangle(3, 4);
    delete rect;
    std::cout << "Area: " << rect->area() << std::endl; // Use after free – crash!
    return 0;
}


// arnavkumar@EPINHYDW182F:/mnt/c/Users/ArnavKumar/OneDrive - EPAM/Work/Unit Testing, Debugging/Crash Dump Analysis$ g++ -g -o T13 Task13.cpp
// arnavkumar@EPINHYDW182F:/mnt/c/Users/ArnavKumar/OneDrive - EPAM/Work/Unit Testing, Debugging/Crash Dump Analysis$ gdb ./T13
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
// Reading symbols from ./T13...
// (gdb) run
// Starting program: /mnt/c/Users/ArnavKumar/OneDrive - EPAM/Work/Unit Testing, Debugging/Crash Dump Analysis/T13 

// This GDB supports auto-downloading debuginfo from the following URLs:
//   <https://debuginfod.ubuntu.com>
// Enable debuginfod for this session? (y or [n]) y
// Debuginfod has been enabled.
// To make this setting permanent, add 'set debuginfod enabled on' to .gdbinit.
// [Thread debugging using libthread_db enabled]
// Using host libthread_db library "/usr/lib/x86_64-linux-gnu/libthread_db.so.1".
// Area: -1431655657
// [Inferior 1 (process 558) exited normally]
// (gdb) 