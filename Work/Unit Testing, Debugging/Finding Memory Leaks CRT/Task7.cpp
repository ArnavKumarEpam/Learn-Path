#ifdef _WIN32
#include <crtdbg.h>
#endif
#include <iostream>

int main() {
#ifdef _WIN32
    _CrtSetDbgFlag(_CRTDBG_ALLOC_MEM_DF | _CRTDBG_LEAK_CHECK_DF);
    // Let's assume allocation #45 is suspicious (from previous leak report)
    _CrtSetBreakAlloc(45); // BREAK at allocation #45
#endif

    int* a = new int(10);
    double* b = new double(3.14);
    char* c = new char[100];
    int* d = new int[20];

    std::cout << "Allocated several objects, running..." << std::endl;

    // Intentionally leak some pointers
    // delete a; // not deleted
    delete b;
    delete[] c;
    delete[] d;

    return 0;
}

// arnavkumar@EPINHYDW182F:/mnt/c/Users/ArnavKumar/OneDrive - EPAM/Work/Unit Testing, Debugging/Finding Memory Leaks CRT$ valgrind --leak-check=full ./T7
// ==4259== Memcheck, a memory error detector
// ==4259== Copyright (C) 2002-2024, and GNU GPL'd, by Julian Seward et al.
// ==4259== Using Valgrind-3.26.0 and LibVEX; rerun with -h for copyright info
// ==4259== Command: ./T7
// ==4259== 
// Allocated several objects, running...
// ==4259== 
// ==4259== HEAP SUMMARY:
// ==4259==     in use at exit: 4 bytes in 1 blocks
// ==4259==   total heap usage: 6 allocs, 5 frees, 74,944 bytes allocated
// ==4259== 
// ==4259== 4 bytes in 1 blocks are definitely lost in loss record 1 of 1
// ==4259==    at 0x4850FD3: operator new(unsigned long) (vg_replace_malloc.c:488)
// ==4259==    by 0x40011FE: main (Task7.cpp:13)
// ==4259== 
// ==4259== LEAK SUMMARY:
// ==4259==    definitely lost: 4 bytes in 1 blocks
// ==4259==    indirectly lost: 0 bytes in 0 blocks
// ==4259==      possibly lost: 0 bytes in 0 blocks
// ==4259==    still reachable: 0 bytes in 0 blocks
// ==4259==         suppressed: 0 bytes in 0 blocks
// ==4259== 
// ==4259== For lists of detected and suppressed errors, rerun with: -s
// ==4259== ERROR SUMMARY: 1 errors from 1 contexts (suppressed: 0 from 0)
// arnavkumar@EPINHYDW182F:/mnt/c/Users/ArnavKumar/OneDrive - EPAM/Work/Unit Testing, Debugging/Finding Memory Leaks CRT$ 