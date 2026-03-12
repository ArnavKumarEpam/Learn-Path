#include<iostream>
#include<typeinfo>
template<typename T> 
void showType(T value){
    std::cout<<"Value: "<<value<<"\n";
    std::cout<<"Deduced Type: "<<typeid(value).name()<<std::endl;
}
int main(){
    showType(10);
    showType(3.14);

}
