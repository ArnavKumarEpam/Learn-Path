#include<iostream>
#include<typeinfo>
template<typename T>
class Box{
    T value;
    public:
        Box(T v) : value(v) {}
        void print(){
            std::cout<<"Value: "<<value<<" type: "<< typeid(T).name() <<std::endl;
        }
};

int main(){
    Box<int> intBox(42);
    Box<std::string> strBox("Hello, Templates!");

    intBox.print();   // Prints: 42
    strBox.print();   // Prints: Hello, Templates!
}