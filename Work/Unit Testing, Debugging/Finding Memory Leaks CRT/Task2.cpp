#include <crtdbg.h>
int main() {
    _CrtSetDbgFlag(_CRTDBG_ALLOC_MEM_DF | _CRTDBG_LEAK_CHECK_DF);
    
    int* arr = new int[100];
    // ... (use arr as needed)
    
    delete[] arr;  // Correctly free memory
    return 0;      // Program ends, no leak should be reported
}