#include<iostream>

auto makeLambda(){
    int temp = 5;
    return [&temp]{ // temp is local variable it gets destroyed as scope goes out of the function
        return temp * 2;
    };
}

int main(){
    auto lambda = makeLambda();
    std::cout << "Calling lambda after temp is gone: " << lambda() << std::endl; // Undefined behavior!
}