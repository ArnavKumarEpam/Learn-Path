// leak_demo.cpp
#include <iostream>
int main() {
    int* arr = new int[100]; // Leaked memory
    // no delete[] arr;
    // Corrected version: 
    delete[] arr;
    return 0;
}
// Before correcting delete[]
// arnavkumar@EPINHYDW182F:/mnt/c/Users/ArnavKumar/OneDrive - EPAM/Work/Unit Testing, Debugging/Finding Memory Leaks CRT$ valgrind --leak-check=full ./T8
// ==4489== Memcheck, a memory error detector
// ==4489== Copyright (C) 2002-2024, and GNU GPL'd, by Julian Seward et al.
// ==4489== Using Valgrind-3.26.0 and LibVEX; rerun with -h for copyright info
// ==4489== Command: ./T8
// ==4489== 
// ==4489== 
// ==4489== HEAP SUMMARY:
// ==4489==     in use at exit: 400 bytes in 1 blocks
// ==4489==   total heap usage: 2 allocs, 1 frees, 74,128 bytes allocated
// ==4489== 
// ==4489== 400 bytes in 1 blocks are definitely lost in loss record 1 of 1
// ==4489==    at 0x48525F3: operator new[](unsigned long) (vg_replace_malloc.c:730)
// ==4489==    by 0x400115E: main (Task8.cpp:4)
// ==4489== 
// ==4489== LEAK SUMMARY:
// ==4489==    definitely lost: 400 bytes in 1 blocks
// ==4489==    indirectly lost: 0 bytes in 0 blocks
// ==4489==      possibly lost: 0 bytes in 0 blocks
// ==4489==    still reachable: 0 bytes in 0 blocks
// ==4489==         suppressed: 0 bytes in 0 blocks
// ==4489== 
// ==4489== For lists of detected and suppressed errors, rerun with: -s
// ==4489== ERROR SUMMARY: 1 errors from 1 contexts (suppressed: 0 from 0)
// arnavkumar@EPINHYDW182F:/mnt/c/Users/ArnavKumar/OneDrive - EPAM/Work/Unit Testing, Debugging/Finding Memory Leaks CRT$ 

// After correcting delete[]
// arnavkumar@EPINHYDW182F:/mnt/c/Users/ArnavKumar/OneDrive - EPAM/Work/Unit Testing, Debugging/Finding Memory Leaks CRT$ valgrind --leak-check=full ./T8
// ==4591== Memcheck, a memory error detector
// ==4591== Copyright (C) 2002-2024, and GNU GPL'd, by Julian Seward et al.
// ==4591== Using Valgrind-3.26.0 and LibVEX; rerun with -h for copyright info
// ==4591== Command: ./T8
// ==4591== 
// ==4591== 
// ==4591== HEAP SUMMARY:
// ==4591==     in use at exit: 0 bytes in 0 blocks
// ==4591==   total heap usage: 2 allocs, 2 frees, 74,128 bytes allocated
// ==4591== 
// ==4591== All heap blocks were freed -- no leaks are possible
// ==4591== 
// ==4591== For lists of detected and suppressed errors, rerun with: -s
// ==4591== ERROR SUMMARY: 0 errors from 0 contexts (suppressed: 0 from 0)
// arnavkumar@EPINHYDW182F:/mnt/c/Users/ArnavKumar/OneDrive - EPAM/Work/Unit Testing, Debugging/Finding Memory Leaks CRT$ 

