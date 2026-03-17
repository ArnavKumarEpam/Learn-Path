#include<iostream>

int main(){
    int counter = 0;
    auto inc = [counter]() mutable { counter++; };
    inc();
    std::cout << "After inc() (by value): counter = " << counter << std::endl; // Expect 0

    auto incRef = [&counter]() { counter++; };
    incRef();
    std::cout << "After incRef() (by reference): counter = " << counter << std::endl; // Expect 1
    
}