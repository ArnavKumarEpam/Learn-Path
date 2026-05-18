#include <iostream>
#include <cstring>
#ifdef _WIN32
#include <crtdbg.h>
#endif

class A {
    int* arr;
public:
    A(size_t n) { arr = new int[n]; }
    ~A() { delete[] arr; } // Correct
};

class B {
    char* str;
public:
    B(const char* s) {
        str = new char[strlen(s) + 1];
        strcpy(str, s);
    }
    ~B() { delete[] str; } // Corrected
};

class C {
    double* data;
public:
    C(int v) { data = new double[10]; }
    ~C() { delete[] data; } // Correct
};

class D {
    int* x;
public:
    D() { x = new int(42); }
    ~D() { delete x; } // Corrected
    // forgot delete x; // Leak
};

int main() {
#ifdef _WIN32
    _CrtSetDbgFlag(_CRTDBG_ALLOC_MEM_DF | _CRTDBG_LEAK_CHECK_DF);
#endif
    A a(20);
    B b("hello world");
    C c(10);
    D d;
    return 0;
}


// Before fixing the leaks
// arnavkumar@EPINHYDW182F:/mnt/c/Users/ArnavKumar/OneDrive - EPAM/Work/Unit Testing, Debugging/Finding Memory Leaks CRT$ g++ -g -o T15 Task15.cpp
// arnavkumar@EPINHYDW182F:/mnt/c/Users/ArnavKumar/OneDrive - EPAM/Work/Unit Testing, Debugging/Finding Memory Leaks CRT$ valgrind --leak-check=full ./T15
// ==1777== Memcheck, a memory error detector
// ==1777== Copyright (C) 2002-2024, and GNU GPL'd, by Julian Seward et al.
// ==1777== Using Valgrind-3.26.0 and LibVEX; rerun with -h for copyright info
// ==1777== Command: ./T15
// ==1777== 
// ==1777== 
// ==1777== HEAP SUMMARY:
// ==1777==     in use at exit: 16 bytes in 2 blocks
// ==1777==   total heap usage: 5 allocs, 3 frees, 73,904 bytes allocated
// ==1777== 
// ==1777== 4 bytes in 1 blocks are definitely lost in loss record 1 of 2
// ==1777==    at 0x4850FD3: operator new(unsigned long) (vg_replace_malloc.c:488)
// ==1777==    by 0x400149F: D::D() (Task15.cpp:34)
// ==1777==    by 0x40012A8: main (Task15.cpp:45)
// ==1777== 
// ==1777== 12 bytes in 1 blocks are definitely lost in loss record 2 of 2
// ==1777==    at 0x48525F3: operator new[](unsigned long) (vg_replace_malloc.c:730)
// ==1777==    by 0x40013F9: B::B(char const*) (Task15.cpp:18)
// ==1777==    by 0x400128B: main (Task15.cpp:43)
// ==1777== 
// ==1777== LEAK SUMMARY:
// ==1777==    definitely lost: 16 bytes in 2 blocks
// ==1777==    indirectly lost: 0 bytes in 0 blocks
// ==1777==      possibly lost: 0 bytes in 0 blocks
// ==1777==    still reachable: 0 bytes in 0 blocks
// ==1777==         suppressed: 0 bytes in 0 blocks
// ==1777== 
// ==1777== For lists of detected and suppressed errors, rerun with: -s
// ==1777== ERROR SUMMARY: 2 errors from 2 contexts (suppressed: 0 from 0)
// arnavkumar@EPINHYDW182F:/mnt/c/Users/ArnavKumar/OneDrive - EPAM/Work/Unit Testing, Debugging/Finding Memory Leaks CRT$ 