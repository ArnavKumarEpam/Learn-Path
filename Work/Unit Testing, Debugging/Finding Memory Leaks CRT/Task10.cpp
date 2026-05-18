// double_delete.cpp
#include <iostream>
int main() {
    int* ptr = new int(42);
    delete ptr;
    // Double deletion (uncomment to test):
    // delete ptr;         // Error: double free!
    
    // Use after free (uncomment to test):
    // std::cout << *ptr << std::endl;  // Error: use after free!
    
    return 0;
}


// arnavkumar@EPINHYDW182F:/mnt/c/Users/ArnavKumar/OneDrive - EPAM/Work/Unit Testing, Debugging/Finding Memory Leaks CRT$ g++ -g -o T10 Task10.cpp
// arnavkumar@EPINHYDW182F:/mnt/c/Users/ArnavKumar/OneDrive - EPAM/Work/Unit Testing, Debugging/Finding Memory Leaks CRT$ valgrind --leak-check=full ./T10
// ==4911== Memcheck, a memory error detector
// ==4911== Copyright (C) 2002-2024, and GNU GPL'd, by Julian Seward et al.
// ==4911== Using Valgrind-3.26.0 and LibVEX; rerun with -h for copyright info
// ==4911== Command: ./T10
// ==4911== 
// ==4911== 
// ==4911== HEAP SUMMARY:
// ==4911==     in use at exit: 0 bytes in 0 blocks
// ==4911==   total heap usage: 2 allocs, 2 frees, 73,732 bytes allocated
// ==4911== 
// ==4911== All heap blocks were freed -- no leaks are possible
// ==4911== 
// ==4911== For lists of detected and suppressed errors, rerun with: -s
// ==4911== ERROR SUMMARY: 0 errors from 0 contexts (suppressed: 0 from 0)
// arnavkumar@EPINHYDW182F:/mnt/c/Users/ArnavKumar/OneDrive - EPAM/Work/Unit Testing, Debugging/Finding Memory Leaks CRT$ 