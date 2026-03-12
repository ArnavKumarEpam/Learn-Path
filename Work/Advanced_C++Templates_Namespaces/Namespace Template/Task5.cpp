#include<iostream>
#include<typeinfo>
template<typename T>
class Box{
    T value;
    public: 
        Box(T v) : value(v){}
        void print(){
            std::cout<<"Value: "<<value<<" type: "<<typeid(value).name()<<std::endl;
        }
};
template<>
class Box<std::string>{
    std::string value;
    public:
        Box(std::string v) : value(v) {}
        void print(){
            // std::cout<<"Value: "<<value<<" type: "<< typeid(value).name()<<std::endl;
            for(char ch : value){
                std::cout << static_cast<char>(std::toupper(static_cast<unsigned char>(ch)));
            }
        }
};

int main(){
    
    Box<std::string> strBox("Hello, Templates!");
    strBox.print();   // Prints: Hello, Templates!
}