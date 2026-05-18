// use_after_free.cpp
#include <iostream>
int main() {
    int* p = new int(7);
    delete p;
    *p = 42;               // Use-after-free crash or undefined behavior
    std::cout << *p << std::endl;
    return 0;
}
