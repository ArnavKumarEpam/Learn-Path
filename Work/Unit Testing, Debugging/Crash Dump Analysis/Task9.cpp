#include <iostream>
#include <csignal>
#ifdef __linux__
#include <execinfo.h> // For backtrace (POSIX)
#endif

void crashHandler(int sig) {
    std::cerr << "Caught signal " << sig << "! (segmentation fault)" << std::endl;
#ifdef __linux__
    void *array[10];
    int size = backtrace(array, 10);
    std::cerr << "Stack trace:" << std::endl;
    backtrace_symbols_fd(array, size, STDERR_FILENO);
#endif
    std::_Exit(1); // Exit immediately
}

int main() {
    signal(SIGSEGV, crashHandler);

    int* ptr = nullptr;
    *ptr = 10; // Deliberately trigger SIGSEGV

    return 0;
}

// arnavkumar@EPINHYDW182F:/mnt/c/Users/ArnavKumar/OneDrive - EPAM/Work/Unit Testing, Debugging/Crash Dump Analysis$ g++ -g -o T9 Task9.cpp
// arnavkumar@EPINHYDW182F:/mnt/c/Users/ArnavKumar/OneDrive - EPAM/Work/Unit Testing, Debugging/Crash Dump Analysis$ ./T9
// Caught signal 11! (segmentation fault)
// Stack trace:
// ./T9(+0x1288) [0x5f7e7f6f7288]
// /usr/lib/x86_64-linux-gnu/libc.so.6(+0x45cb0) [0x7bae03845cb0]
// ./T9(+0x1302) [0x5f7e7f6f7302]
// /usr/lib/x86_64-linux-gnu/libc.so.6(+0x2a601) [0x7bae0382a601]
// /usr/lib/x86_64-linux-gnu/libc.so.6(__libc_start_main+0x88) [0x7bae0382a718]
// ./T9(+0x1145) [0x5f7e7f6f7145]
// arnavkumar@EPINHYDW182F:/mnt/c/Users/ArnavKumar/OneDrive - EPAM/Work/Unit Testing, Debugging/Crash Dump Analysis$ 
