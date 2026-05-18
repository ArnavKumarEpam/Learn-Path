// asan_example.cpp
#include <iostream>
int main() {
    int* arr = new int[5];
    arr[6] = 123;             // Buffer overflow!
    delete[] arr;
    return 0;
}

// arnavkumar@EPINHYDW182F:/mnt/c/Users/ArnavKumar/OneDrive - EPAM/Work/Unit Testing, Debugging/Crash Dump Analysis$ g++ -fsanitize=address -g -o T12 Task12.cpp
// /usr/bin/x86_64-linux-gnu-ld.bfd: /usr/lib/gcc/x86_64-linux-gnu/15/../../../x86_64-linux-gnu/Scrt1.o: in function `_start':
// (.text+0x1b): undefined reference to `main'
// collect2: error: ld returned 1 exit status
// arnavkumar@EPINHYDW182F:/mnt/c/Users/ArnavKumar/OneDrive - EPAM/Work/Unit Testing, Debugging/Crash Dump Analysis$ g++ -fsanitize=address -g -o T12 Task12.cpp
// arnavkumar@EPINHYDW182F:/mnt/c/Users/ArnavKumar/OneDrive - EPAM/Work/Unit Testing, Debugging/Crash Dump Analysis$ ./T12
// =================================================================
// ==1994==ERROR: AddressSanitizer: heap-buffer-overflow on address 0x770aebee0058 at pc 0x605f035d5222 bp 0x7ffda019be10 sp 0x7ffda019be00
// WRITE of size 4 at 0x770aebee0058 thread T0
//     #0 0x605f035d5221 in main /mnt/c/Users/ArnavKumar/OneDrive - EPAM/Work/Unit Testing, Debugging/Crash Dump Analysis/Task12.cpp:5
//     #1 0x7adaeca2a600 in __libc_start_call_main ../sysdeps/nptl/libc_start_call_main.h:59
//     #2 0x7adaeca2a717 in __libc_start_main_impl ../csu/libc-start.c:360
//     #3 0x605f035d5104 in _start (/mnt/c/Users/ArnavKumar/OneDrive - EPAM/Work/Unit Testing, Debugging/Crash Dump Analysis/T12+0x1104) (BuildId: b745ec84f28b00c6aba4e2fac5f1f23894231afa)

// 0x770aebee0058 is located 4 bytes after 20-byte region [0x770aebee0040,0x770aebee0054)
// allocated by thread T0 here:
//     #0 0x7adaed32c8cf in operator new[](unsigned long) ../../../../src/libsanitizer/asan/asan_new_delete.cpp:111
//     #1 0x605f035d51de in main /mnt/c/Users/ArnavKumar/OneDrive - EPAM/Work/Unit Testing, Debugging/Crash Dump Analysis/Task12.cpp:4
//     #2 0x7adaeca2a600 in __libc_start_call_main ../sysdeps/nptl/libc_start_call_main.h:59
//     #3 0x7adaeca2a717 in __libc_start_main_impl ../csu/libc-start.c:360
//     #4 0x605f035d5104 in _start (/mnt/c/Users/ArnavKumar/OneDrive - EPAM/Work/Unit Testing, Debugging/Crash Dump Analysis/T12+0x1104) (BuildId: b745ec84f28b00c6aba4e2fac5f1f23894231afa)

// SUMMARY: AddressSanitizer: heap-buffer-overflow /mnt/c/Users/ArnavKumar/OneDrive - EPAM/Work/Unit Testing, Debugging/Crash Dump Analysis/Task12.cpp:5 in main
// Shadow bytes around the buggy address:
//   0x770aebedfd80: 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00
//   0x770aebedfe00: 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00
//   0x770aebedfe80: 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00
//   0x770aebedff00: 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00
//   0x770aebedff80: 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00
// =>0x770aebee0000: fa fa 00 00 00 fa fa fa 00 00 04[fa]fa fa fa fa
//   0x770aebee0080: fa fa fa fa fa fa fa fa fa fa fa fa fa fa fa fa
//   0x770aebee0100: fa fa fa fa fa fa fa fa fa fa fa fa fa fa fa fa
//   0x770aebee0180: fa fa fa fa fa fa fa fa fa fa fa fa fa fa fa fa
//   0x770aebee0200: fa fa fa fa fa fa fa fa fa fa fa fa fa fa fa fa
//   0x770aebee0280: fa fa fa fa fa fa fa fa fa fa fa fa fa fa fa fa
// Shadow byte legend (one shadow byte represents 8 application bytes):
//   Addressable:           00
//   Partially addressable: 01 02 03 04 05 06 07 
//   Heap left redzone:       fa
//   Freed heap region:       fd
//   Stack left redzone:      f1
//   Stack mid redzone:       f2
//   Stack right redzone:     f3
//   Stack after return:      f5
//   Stack use after scope:   f8
//   Global redzone:          f9
//   Global init order:       f6
//   Poisoned by user:        f7
//   Container overflow:      fc
//   Array cookie:            ac
//   Intra object redzone:    bb
//   ASan internal:           fe
//   Left alloca redzone:     ca
//   Right alloca redzone:    cb
// ==1994==ABORTING
// arnavkumar@EPINHYDW182F:/mnt/c/Users/ArnavKumar/OneDrive - EPAM/Work/Unit Testing, Debugging/Crash Dump Analysis$ 