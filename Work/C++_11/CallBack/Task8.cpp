#include<iostream>

int main(){
    auto add = [](int a, int b){return a + b;};
    int result = add(10, 15);
    std::cout<<"Sum: "<<result<<std::endl;
    return 0;
    

}