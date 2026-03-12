#include<iostream>
template<typename T>
T add(T t1, T t2){
    return t1 + t2;
}

int main(){
    int i = add(2, 3);
    double d = add(1.25, 2.24);
    float f = add(8.9f, 6.7f);

    std::cout << "int: " << i << std::endl;
    std::cout << "double: " << d << std::endl;
    std::cout << "float: " << f << std::endl;
    return 0;
}