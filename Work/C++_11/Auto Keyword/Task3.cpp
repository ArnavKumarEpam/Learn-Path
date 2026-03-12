#include<iostream>
#include<typeinfo>

int main(){
    int x = 10;
    int *ptr = &x;
    auto p = ptr;
    auto &r = x;

    r = 20;
    *p = 40;
    // Print all three
    std::cout << "x = " << x << std::endl;
    std::cout << "*p = " << *p << std::endl;
    std::cout << "r = " << r << std::endl;

    return 0;
}