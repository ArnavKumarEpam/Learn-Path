#define _CRTDBG_MAP_ALLOC
#include <crtdbg.h>
#include <stdlib.h>
int main() {
    _CrtSetDbgFlag(_CRTDBG_ALLOC_MEM_DF | _CRTDBG_LEAK_CHECK_DF);
    int* arr = new int[100];
    return 0; // Do not delete arr!
}
