#include<iostream>

/*
Compiler time overloading 
In this compiler calls the function with the most closest parameters
in this example there are add functions with integer, double, string parameters
So, compiler calls functions accordingly
*/
class Calculator{
    public:
    int add(int a, int b){ // Integer
        return a + b;
    }
    double add(double a, double b){ // Double
        return a + b;
    }
    std::string add(const std::string &a, const std::string &b){ // String
        return a + b;
    }
};

int main(){
    Calculator c; // Object creation of Calculator class
    std::cout<<c.add(1, 2)<<std::endl; // Integer add function
    std::cout<<c.add((double)2.0, (double)4.0)<<std::endl; // Double add function
    std::cout<<c.add("Hello", " World")<<std::endl; // String add function
    return 0;
}