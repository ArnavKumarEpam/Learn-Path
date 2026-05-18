#include <vector>
#include <memory>     // for std::unique_ptr
#include <iostream>
#ifdef _WIN32
#include <crtdbg.h>
#endif

int main() {
#ifdef _WIN32
    _CrtSetDbgFlag(_CRTDBG_ALLOC_MEM_DF | _CRTDBG_LEAK_CHECK_DF);
#endif
    std::vector<std::unique_ptr<int>> v;
    for (int i = 0; i < 10; ++i) {
        v.push_back(std::make_unique<int>(i * 10));
    }
    // No need to manually delete; unique_ptr will release memory automatically.
    return 0;
}

// arnavkumar@EPINHYDW182F:/mnt/c/Users/ArnavKumar/OneDrive - EPAM/Work/Unit Testing, Debugging/Finding Memory Leaks CRT$ g++ -g -o T12 Task12.cpp
// arnavkumar@EPINHYDW182F:/mnt/c/Users/ArnavKumar/OneDrive - EPAM/Work/Unit Testing, Debugging/Finding Memory Leaks CRT$ valgrind --leak-check=full ./T12
// ==1288== Memcheck, a memory error detector
// ==1288== Copyright (C) 2002-2024, and GNU GPL'd, by Julian Seward et al.
// ==1288== Using Valgrind-3.26.0 and LibVEX; rerun with -h for copyright info
// ==1288== Command: ./T12
// ==1288== 
// ==1288== 
// ==1288== HEAP SUMMARY:
// ==1288==     in use at exit: 40 bytes in 10 blocks
// ==1288==   total heap usage: 16 allocs, 6 frees, 74,016 bytes allocated
// ==1288== 
// ==1288== 40 bytes in 10 blocks are definitely lost in loss record 1 of 1
// ==1288==    at 0x4851FD3: operator new(unsigned long) (vg_replace_malloc.c:488)
// ==1288==    by 0x4001287: main (Task12.cpp:14)
// ==1288== 
// ==1288== LEAK SUMMARY:
// ==1288==    definitely lost: 40 bytes in 10 blocks
// ==1288==    indirectly lost: 0 bytes in 0 blocks
// ==1288==      possibly lost: 0 bytes in 0 blocks
// ==1288==    still reachable: 0 bytes in 0 blocks
// ==1288==         suppressed: 0 bytes in 0 blocks
// ==1288== 
// ==1288== For lists of detected and suppressed errors, rerun with: -s
// ==1288== ERROR SUMMARY: 1 errors from 1 contexts (suppressed: 0 from 0)
// arnavkumar@EPINHYDW182F:/mnt/c/Users/ArnavKumar/OneDrive - EPAM/Work/Unit Testing, Debugging/Finding Memory Leaks CRT$ 