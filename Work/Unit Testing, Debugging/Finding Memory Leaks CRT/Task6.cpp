#include <iostream>
#ifdef _WIN32
#include <crtdbg.h>
#endif

int main() {
#ifdef _WIN32
    _CrtSetDbgFlag(_CRTDBG_ALLOC_MEM_DF | _CRTDBG_LEAK_CHECK_DF);
#endif
    int* arr = new int[5];
    for (int i = 0; i < 5; ++i)
        arr[i] = i * 10;

    // Buffer overflow: Write past the end!
    arr[5] = 999; // Undefined behavior—heap corruption!

    delete[] arr;
    return 0;
}


// arnavkumar@EPINHYDW182F:/mnt/c/Users/ArnavKumar/OneDrive - EPAM/Work/Unit Testing, Debugging/Finding Memory Leaks CRT$ valgrind --leak-check=full ./T6
// ==4141== Memcheck, a memory error detector
// ==4141== Copyright (C) 2002-2024, and GNU GPL'd, by Julian Seward et al.
// ==4141== Using Valgrind-3.26.0 and LibVEX; rerun with -h for copyright info
// ==4141== Command: ./T6
// ==4141== 
// ==4141== Invalid write of size 4
// ==4141==    at 0x40011C1: main (Task6.cpp:15)
// ==4141==  Address 0x4e98094 is 0 bytes after a block of size 20 alloc'd
// ==4141==    at 0x48525F3: operator new[](unsigned long) (vg_replace_malloc.c:730)
// ==4141==    by 0x400117E: main (Task6.cpp:10)
// ==4141== 
// ==4141== 
// ==4141== HEAP SUMMARY:
// ==4141==     in use at exit: 0 bytes in 0 blocks
// ==4141==   total heap usage: 2 allocs, 2 frees, 73,748 bytes allocated
// ==4141== 
// ==4141== All heap blocks were freed -- no leaks are possible
// ==4141== 
// ==4141== For lists of detected and suppressed errors, rerun with: -s
// ==4141== ERROR SUMMARY: 1 errors from 1 contexts (suppressed: 0 from 0)
// arnavkumar@EPINHYDW182F:/mnt/c/Users/ArnavKumar/OneDrive - EPAM/Work/Unit Testing, Debugging/Finding Memory Leaks CRT$ 