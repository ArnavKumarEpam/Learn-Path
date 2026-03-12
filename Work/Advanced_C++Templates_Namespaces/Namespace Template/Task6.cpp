#include<iostream>
#include<typeinfo>
template<typename T = int> 
class Number{
    T value;
    public:
        Number(T v) : value(v){}
        void print()const { std::cout <<"Value: "<< value <<" Type: " << typeid(value).name() << std::endl; }
};
int main(){
    Number<> N(100);
    Number<double> N2(10.890);
    N.print();
    N2.print();

}
