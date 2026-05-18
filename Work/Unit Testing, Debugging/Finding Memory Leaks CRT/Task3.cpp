#include <iostream>
#ifdef _WIN32
#include <crtdbg.h>
#endif

int main() {
#ifdef _WIN32
    _CrtSetDbgFlag(_CRTDBG_ALLOC_MEM_DF | _CRTDBG_LEAK_CHECK_DF);
#endif

    const int N = 10;
    int* pointers[N];

    for (int i = 0; i < N; ++i) {
        pointers[i] = new int(i * 10);
    }

    // Intentionally delete only even-indexed objects
    for (int i = 0; i < N; ++i) {
        if (i % 2 == 0) {
            delete pointers[i];
            pointers[i] = nullptr;
        }
        // Odd-indexed objects are purposely not deleted (leaked)
    }

    return 0; // Leaks for odd-indexed allocations
}


// arnavkumar@EPINHYDW182F:/mnt/c/Users/ArnavKumar/OneDrive - EPAM/Work/Unit Testing, Debugging/Finding Memory Leaks CRT$ valgrind --leak-check=full ./T3
// ==5018== Memcheck, a memory error detector
// ==5018== Copyright (C) 2002-2024, and GNU GPL'd, by Julian Seward et al.
// ==5018== Using Valgrind-3.26.0 and LibVEX; rerun with -h for copyright info
// ==5018== Command: ./T3
// ==5018== 
// ==5018== 
// ==5018== HEAP SUMMARY:
// ==5018==     in use at exit: 20 bytes in 5 blocks
// ==5018==   total heap usage: 11 allocs, 6 frees, 73,768 bytes allocated
// ==5018== 
// ==5018== 20 bytes in 5 blocks are definitely lost in loss record 1 of 1
// ==5018==    at 0x4850FD3: operator new(unsigned long) (vg_replace_malloc.c:488)
// ==5018==    by 0x40011BD: main (Task3.cpp:15)
// ==5018== 
// ==5018== LEAK SUMMARY:
// ==5018==    definitely lost: 20 bytes in 5 blocks
// ==5018==    indirectly lost: 0 bytes in 0 blocks
// ==5018==      possibly lost: 0 bytes in 0 blocks
// ==5018==    still reachable: 0 bytes in 0 blocks
// ==5018==         suppressed: 0 bytes in 0 blocks
// ==5018== 
// ==5018== For lists of detected and suppressed errors, rerun with: -s
// ==5018== ERROR SUMMARY: 1 errors from 1 contexts (suppressed: 0 from 0)
// arnavkumar@EPINHYDW182F:/mnt/c/Users/ArnavKumar/OneDrive - EPAM/Work/Unit Testing, Debugging/Finding Memory Leaks CRT$ 