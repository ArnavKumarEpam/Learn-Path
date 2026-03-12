#include<iostream>

struct Add{
    int operator()(int a, int b){
        return a + b;
    }
};

int main(){
    Add add;
    int result = add(20, 30);
    result = add(60, 70);
    std::cout << "Sum: " << result << std::endl;

}