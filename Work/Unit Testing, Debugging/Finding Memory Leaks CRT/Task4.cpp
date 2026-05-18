#include <iostream>
#include <cstring>
#ifdef _WIN32
#include <crtdbg.h>
#endif

class Person {
    char* name;
public:
    Person(const char* nm) {
        size_t len = strlen(nm) + 1;
        name = new char[len];
        strcpy(name, nm);
    }
    // No destructor OR destructor without 'delete[] name' (intentional leak)
    ~Person() { /* missing delete[] name; */ }
    void greet() const {
        std::cout << "Hello, my name is " << name << std::endl;
    }
};


int main() {
#ifdef _WIN32
    _CrtSetDbgFlag(_CRTDBG_ALLOC_MEM_DF | _CRTDBG_LEAK_CHECK_DF);
#endif
    Person p1("Alice");
    Person p2("Bob");
    p1.greet();
    p2.greet();
    return 0; // 'name' buffers are leaked!
}

// arnavkumar@EPINHYDW182F:/mnt/c/Users/ArnavKumar/OneDrive - EPAM/Work/Unit Testing, Debugging/Finding Memory Leaks CRT$ g++ -g -o T4 Task4.cpp
// arnavkumar@EPINHYDW182F:/mnt/c/Users/ArnavKumar/OneDrive - EPAM/Work/Unit Testing, Debugging/Finding Memory Leaks CRT$ valgrind --leak-check=full ./T4
// ==5092== Memcheck, a memory error detector
// ==5092== Copyright (C) 2002-2024, and GNU GPL'd, by Julian Seward et al.
// ==5092== Using Valgrind-3.26.0 and LibVEX; rerun with -h for copyright info
// ==5092== Command: ./T4
// ==5092== 
// Hello, my name is Alice
// Hello, my name is Bob
// ==5092== 
// ==5092== HEAP SUMMARY:
// ==5092==     in use at exit: 10 bytes in 2 blocks
// ==5092==   total heap usage: 4 allocs, 2 frees, 74,762 bytes allocated
// ==5092== 
// ==5092== 4 bytes in 1 blocks are definitely lost in loss record 1 of 2
// ==5092==    at 0x48525F3: operator new[](unsigned long) (vg_replace_malloc.c:730)
// ==5092==    by 0x400131F: Person::Person(char const*) (Task4.cpp:12)
// ==5092==    by 0x4001250: main (Task4.cpp:28)
// ==5092== 
// ==5092== 6 bytes in 1 blocks are definitely lost in loss record 2 of 2
// ==5092==    at 0x48525F3: operator new[](unsigned long) (vg_replace_malloc.c:730)
// ==5092==    by 0x400131F: Person::Person(char const*) (Task4.cpp:12)
// ==5092==    by 0x400123A: main (Task4.cpp:27)
// ==5092== 
// ==5092== LEAK SUMMARY:
// ==5092==    definitely lost: 10 bytes in 2 blocks
// ==5092==    indirectly lost: 0 bytes in 0 blocks
// ==5092==      possibly lost: 0 bytes in 0 blocks
// ==5092==    still reachable: 0 bytes in 0 blocks
// ==5092==         suppressed: 0 bytes in 0 blocks
// ==5092== 
// ==5092== For lists of detected and suppressed errors, rerun with: -s
// ==5092== ERROR SUMMARY: 2 errors from 2 contexts (suppressed: 0 from 0)
// arnavkumar@EPINHYDW182F:/mnt/c/Users/ArnavKumar/OneDrive - EPAM/Work/Unit Testing, Debugging/Finding Memory Leaks CRT$ 