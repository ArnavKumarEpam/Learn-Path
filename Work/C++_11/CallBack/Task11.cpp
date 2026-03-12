#include<iostream>

int main(){
    int counter = 0;
    auto next = [counter]() mutable { // mutable keyword allows modification of the capture value
        counter++;
        return counter;
    };
    std::cout << "next(): " << next() << std::endl; // 1
    std::cout << "next(): " << next() << std::endl; // 2
    std::cout << "next(): " << next() << std::endl; // 3
    std::cout << "Outer counter: " << counter << std::endl; // 0 as its captured by value if it was by reference then 3
}