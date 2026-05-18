#include <iostream>
#include <stdexcept>
#ifdef _WIN32
#include <crtdbg.h>
#endif

void mayThrow(bool doThrow) {
    int* data = new int[100];
    if (doThrow)
        throw std::runtime_error("Boom!");
    delete[] data; // Only called if no exception
}

int main() {
#ifdef _WIN32
    _CrtSetDbgFlag(_CRTDBG_ALLOC_MEM_DF | _CRTDBG_LEAK_CHECK_DF);
#endif
    try {
        mayThrow(true);  // This leaks
    } catch (const std::exception& e) {
        std::cout << "Caught exception: " << e.what() << std::endl;
    }
    return 0;
}
