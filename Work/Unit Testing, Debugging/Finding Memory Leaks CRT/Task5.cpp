#include <iostream>
#include <cstring>
#ifdef _WIN32
#include <crtdbg.h>
#endif

class Person {
    char* name;
public:
    Person(const char* nm) {
        size_t len = std::strlen(nm) + 1;
        name = new char[len];
        std::strcpy(name, nm);
    }
    ~Person() {
        delete[] name; // Proper cleanup!
    }
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
    return 0;
}

// arnavkumar@EPINHYDW182F:/mnt/c/Users/ArnavKumar/OneDrive - EPAM/Work/Unit Testing, Debugging/Finding Memory Leaks CRT$ valgrind --leak-check=full ./T5
// ==4000== Memcheck, a memory error detector
// ==4000== Copyright (C) 2002-2024, and GNU GPL'd, by Julian Seward et al.
// ==4000== Using Valgrind-3.26.0 and LibVEX; rerun with -h for copyright info
// ==4000== Command: ./T5
// ==4000== 
// Hello, my name is Alice
// Hello, my name is Bob
// ==4000== 
// ==4000== HEAP SUMMARY:
// ==4000==     in use at exit: 0 bytes in 0 blocks
// ==4000==   total heap usage: 4 allocs, 4 frees, 74,762 bytes allocated
// ==4000== 
// ==4000== All heap blocks were freed -- no leaks are possible
// ==4000== 
// ==4000== For lists of detected and suppressed errors, rerun with: -s
// ==4000== ERROR SUMMARY: 0 errors from 0 contexts (suppressed: 0 from 0)
// arnavkumar@EPINHYDW182F:/mnt/c/Users/ArnavKumar/OneDrive - EPAM/Work/Unit Testing, Debugging/Finding Memory Leaks CRT$ 