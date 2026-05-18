// uninit_demo.cpp
#include <iostream>
int main() {
    int* arr = new int[5];
    for (int i = 0; i < 5; ++i) {
        std::cout << arr[i] << " "; // UNINITIALIZED READ!
    }
    std::cout << std::endl;
    delete[] arr;
    return 0;
}

// arnavkumar@EPINHYDW182F:/mnt/c/Users/ArnavKumar/OneDrive - EPAM/Work/Unit Testing, Debugging/Finding Memory Leaks CRT$ valgrind --track-origins=yes ./T9
// ==4753== Memcheck, a memory error detector
// ==4753== Copyright (C) 2002-2024, and GNU GPL'd, by Julian Seward et al.
// ==4753== Using Valgrind-3.26.0 and LibVEX; rerun with -h for copyright info
// ==4753== Command: ./T9
// ==4753== 
// ==4753== Conditional jump or move depends on uninitialised value(s)
// ==4753==    at 0x49BE7FB: std::ostreambuf_iterator<char, std::char_traits<char> > std::num_put<char, std::ostreambuf_iterator<char, std::char_traits<char> > >::_M_insert_int<long>(std::ostreambuf_iterator<char, std::char_traits<char> >, std::ios_base&, char, long) const (in /usr/lib/x86_64-linux-gnu/libstdc++.so.6.0.35)
// ==4753==    by 0x49CF3DD: std::ostream& std::ostream::_M_insert<long>(long) (in /usr/lib/x86_64-linux-gnu/libstdc++.so.6.0.35)
// ==4753==    by 0x4001212: main (Task9.cpp:6)
// ==4753==  Uninitialised value was created by a heap allocation
// ==4753==    at 0x48525F3: operator new[](unsigned long) (vg_replace_malloc.c:730)
// ==4753==    by 0x40011DE: main (Task9.cpp:4)
// ==4753== 
// ==4753== Use of uninitialised value of size 8
// ==4753==    at 0x49BE6E2: ??? (in /usr/lib/x86_64-linux-gnu/libstdc++.so.6.0.35)
// ==4753==    by 0x49BE825: std::ostreambuf_iterator<char, std::char_traits<char> > std::num_put<char, std::ostreambuf_iterator<char, std::char_traits<char> > >::_M_insert_int<long>(std::ostreambuf_iterator<char, std::char_traits<char> >, std::ios_base&, char, long) const (in /usr/lib/x86_64-linux-gnu/libstdc++.so.6.0.35)
// ==4753==    by 0x49CF3DD: std::ostream& std::ostream::_M_insert<long>(long) (in /usr/lib/x86_64-linux-gnu/libstdc++.so.6.0.35)
// ==4753==    by 0x4001212: main (Task9.cpp:6)
// ==4753==  Uninitialised value was created by a heap allocation
// ==4753==    at 0x48525F3: operator new[](unsigned long) (vg_replace_malloc.c:730)
// ==4753==    by 0x40011DE: main (Task9.cpp:4)
// ==4753== 
// ==4753== Conditional jump or move depends on uninitialised value(s)
// ==4753==    at 0x49BE6EA: ??? (in /usr/lib/x86_64-linux-gnu/libstdc++.so.6.0.35)
// ==4753==    by 0x49BE825: std::ostreambuf_iterator<char, std::char_traits<char> > std::num_put<char, std::ostreambuf_iterator<char, std::char_traits<char> > >::_M_insert_int<long>(std::ostreambuf_iterator<char, std::char_traits<char> >, std::ios_base&, char, long) const (in /usr/lib/x86_64-linux-gnu/libstdc++.so.6.0.35)
// ==4753==    by 0x49CF3DD: std::ostream& std::ostream::_M_insert<long>(long) (in /usr/lib/x86_64-linux-gnu/libstdc++.so.6.0.35)
// ==4753==    by 0x4001212: main (Task9.cpp:6)
// ==4753==  Uninitialised value was created by a heap allocation
// ==4753==    at 0x48525F3: operator new[](unsigned long) (vg_replace_malloc.c:730)
// ==4753==    by 0x40011DE: main (Task9.cpp:4)
// ==4753== 
// ==4753== Conditional jump or move depends on uninitialised value(s)
// ==4753==    at 0x49BE857: std::ostreambuf_iterator<char, std::char_traits<char> > std::num_put<char, std::ostreambuf_iterator<char, std::char_traits<char> > >::_M_insert_int<long>(std::ostreambuf_iterator<char, std::char_traits<char> >, std::ios_base&, char, long) const (in /usr/lib/x86_64-linux-gnu/libstdc++.so.6.0.35)
// ==4753==    by 0x49CF3DD: std::ostream& std::ostream::_M_insert<long>(long) (in /usr/lib/x86_64-linux-gnu/libstdc++.so.6.0.35)
// ==4753==    by 0x4001212: main (Task9.cpp:6)
// ==4753==  Uninitialised value was created by a heap allocation
// ==4753==    at 0x48525F3: operator new[](unsigned long) (vg_replace_malloc.c:730)
// ==4753==    by 0x40011DE: main (Task9.cpp:4)
// ==4753== 
// 0 0 0 0 0 
// ==4753== 
// ==4753== HEAP SUMMARY:
// ==4753==     in use at exit: 0 bytes in 0 blocks
// ==4753==   total heap usage: 3 allocs, 3 frees, 74,772 bytes allocated
// ==4753== 
// ==4753== All heap blocks were freed -- no leaks are possible
// ==4753== 
// ==4753== For lists of detected and suppressed errors, rerun with: -s
// ==4753== ERROR SUMMARY: 20 errors from 4 contexts (suppressed: 0 from 0)
// arnavkumar@EPINHYDW182F:/mnt/c/Users/ArnavKumar/OneDrive - EPAM/Work/Unit Testing, Debugging/Finding Memory Leaks CRT$ 