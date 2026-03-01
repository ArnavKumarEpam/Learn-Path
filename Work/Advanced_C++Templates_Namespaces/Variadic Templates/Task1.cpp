#include<iostream>
#include<typeinfo>
// template<int n>
// class Store{
//     public:
//         int cont[n];
// };
// template<typename T>
// T check(T value){
//     return value;
// }
// template <typename T, typename U>
// auto getMax(T a, U b){
//     return a > b ? a : b;
// }
// template<typename...Args>
// void print(Args... args){
//     std::cout<<sizeof...(args);
// }
template<typename... Args>
void printAll(Args... args) {
    (std::cout<<...<<(args<< " "));
}
int main(){
    // Store<89>;
    std::string ans = "hello";
    // std::cout<<typeid(check(1000)).name();
    // std::cout<<getMax(10, 25.45);
    // print(1,2,3,4,5,6,6);
    printAll();
    
}