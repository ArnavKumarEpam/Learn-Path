// crash_nullptr.cpp
#include <iostream>
int main() {
    int* ptr = nullptr;
    *ptr = 10; // Deliberate null pointer dereference
    return 0;
}

// (gdb) run
// Starting program: C:\Users\ArnavKumar\OneDrive - EPAM\Work\Unit Testing, Debugging\Crash Dump Analysis\T1.exe 
// [New Thread 2420.0x91e0]
// [New Thread 2420.0x9660]
// [New Thread 2420.0xa238]

// Thread 1 received signal SIGSEGV, Segmentation fault.
// 0x00007ff69c191729 in main () at Task1.cpp:5
// 5           *ptr = 10; // Deliberate null pointer dereference
// (gdb) 