#include<iostream>

int main(){
    auto multiply = [](int x, int factor = 2){return x * factor;};
    std::cout << "multiply(10): " << multiply(10) << std::endl;      // Uses default factor 2 
    std::cout << "multiply(10, 5): " << multiply(10, 5) << std::endl; // factor = 5
}