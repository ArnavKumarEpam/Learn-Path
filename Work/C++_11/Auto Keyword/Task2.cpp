#include<iostream>
#include<typeinfo>

int main(){
    auto a = 5 + 2.5;    // int + double: deduced as double
    auto b = 3 * 1.5f;   // int * float: deduced as float
    
    std::cout << "auto a = 5 + 2.5; value: " << a << ", type: " << typeid(a).name() << std::endl;
    std::cout << "auto b = 3 * 1.5f; value: " << b << ", type: " << typeid(b).name() << std::endl;
    return 0;
}