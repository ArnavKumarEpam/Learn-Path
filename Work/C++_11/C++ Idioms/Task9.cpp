#include "BigData_T9.h"
#include<iostream>
// No need for <vector>, <map>, <string>, or other heavy includes!

int main() {
    BigData bd;
    bd.process();
    std::cout << "BigData size: " << bd.getSize() << std::endl;
    return 0;
}
