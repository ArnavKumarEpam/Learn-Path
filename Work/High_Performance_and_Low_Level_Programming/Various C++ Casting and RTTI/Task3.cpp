#include<iostream>

int main(){
    const int x = 10;
    std::cout<<"Original value of x: "<<x<<std::endl;
    const int *ptr = &x;

    int *ptr2 = const_cast<int *> (ptr);
    *ptr2 = 20; // This is undefined behavior since x is const, but
    // Whenever we try to print x we will get the original value of x as compiler sees x as const and may optimize it by replacing all occurrences of x with 10 directly in the code.
    std::cout<<"Value of x after const_cast: "<<x<<std::endl; // May still print 10 or may print 20 depending on the compiler and optimization  
    std::cout<<"Value through ptr2: "<<*ptr2<<std::endl; // May print 20, but this is not guaranteed and is undefined behavior
    std::cout<<"Value through ptr: "<<*ptr<<std::endl; // Will print 20, but again this is undefined behavior

    int a = 50;
    std::cout<<"Original value of a: "<<a<<std::endl;
    const int *ptr3 = &a;
    int *ptr4 = const_cast<int *> (ptr3);
    *ptr4 = 100; // This is well-defined behavior since a is not const
    std::cout<<"Value of a after const_cast: "<<a<<std::endl; // Will print 100
    std::cout<<"Value through ptr3: "<<*ptr4<<std::endl;
    std::cout<<"Value through ptr2: "<<*ptr3<<std::endl; // Will also print 100 since ptr2 points to a which is now modified 
}