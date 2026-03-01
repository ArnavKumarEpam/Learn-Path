#include<iostream>
void printAll(){
    std::cout<<"Empty Case \n";
}
template<typename T ,typename...Args>
void printAll(T a, Args...args){
    std::cout<<a<<" ";
    printAll(args...);
}

int main(){
    printAll(12, 7.8);
}