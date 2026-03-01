#include<iostream>
// auto sumAll(){
//     return 0;
// }
// template<typename T, typename ...Args>
// auto sumAll(T first, Args...args){
//     return first + sumAll(args...);
// }

template<typename ...Args>
auto sumAll(Args...args){
    return (args + ...);
}

int main(){
    std::cout<<sumAll(1, 2, 3, 90.89) << std::endl;
}