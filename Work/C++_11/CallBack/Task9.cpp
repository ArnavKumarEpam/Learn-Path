#include<iostream>

int main(){
    int a = 10, b = 3;
    auto op = [a, &b](int x){return x *= a + b;};
    int result = op(5);
    std::cout << "op(5): " << op(5) << std::endl;
    b = 100; // will change the value as its captured by reference
    std::cout << "op(5) after b=100: " << op(5) << std::endl;
    a = 100; // Will not change the value as its captured by value
    b = 3;
    std::cout << "op(5) after a=100: " << op(5) << std::endl;
}