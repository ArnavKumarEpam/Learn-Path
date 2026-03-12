#include<iostream>

int& funcReturningReference(){
    static int val = 50; // Why static is important because normal local variables are limited to the scope of the function 
    // After the function their memory is released and if you access them it will be dangling pointer
    std::cout<<"Adress of static val: "<<&val<<std::endl;
    return val;
}

int main(){
    auto x = funcReturningReference();
    auto &y = funcReturningReference(); 
    std::cout<<"Value of X: "<<x<<", Address of x: "<<&x<<std::endl;
    std::cout<<"Value of Y: "<<y<<", Address of y: "<<&y<<std::endl;

    y += 90;
    std::cout<<"Values after modification\n";
    std::cout<<"Value of X: "<<x<<", Address of x: "<<&x<<std::endl;
    std::cout<<"Value of Y: "<<y<<", Address of y: "<<&y<<std::endl; // Value changes after modification
     
    

    
}