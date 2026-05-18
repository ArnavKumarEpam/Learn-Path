#include <vector>
#include <iostream>
#include<memory>
#ifdef _WIN32
#include <crtdbg.h>
#endif
  

int main() {
#ifdef _WIN32
    _CrtSetDbgFlag(_CRTDBG_ALLOC_MEM_DF | _CRTDBG_LEAK_CHECK_DF);
#endif
    std::vector<std::unique_ptr<int>> v;
    for (int i = 0; i < 10; ++i) {
        v.push_back(std::make_unique<int>(i * 10));
    }
    // v.clear(); // or let v go out of scope
    // No deletes—memory leak!
    return 0;
}
