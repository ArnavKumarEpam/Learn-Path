#include <iostream>
#ifdef _WIN32
#include <crtdbg.h>
#endif

int main() {
#ifdef _WIN32
    _CrtSetDbgFlag(_CRTDBG_ALLOC_MEM_DF | _CRTDBG_LEAK_CHECK_DF);
#endif
    for (int i = 0; i < 100; ++i) {
        int* arr = new int[1000];
        // No delete[] arr;  // Intentional leak!
    }
    return 0;
}
