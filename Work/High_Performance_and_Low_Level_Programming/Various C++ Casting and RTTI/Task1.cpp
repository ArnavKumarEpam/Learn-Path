#include<iostream>
int main(){
    double pi = 3.14159265358979323846;
    int num = 10;
    // C style casting
    int pi_int_c = (int)pi;
    double num_double_c = (double)num;
    std::cout<<"C style cast PI: "<<pi_int_c<<" truncates all the values after the decimal point"<<std::endl;
    std::cout<<"C style cast Number: "<<num_double_c<<std::endl;

    // C++ style casting
    int pi_int_cpp = static_cast<int>(pi);
    double num_double_cpp = static_cast<double>(num);
    std::cout<<"C++ style cast PI: "<<pi_int_cpp<<" truncates all values after the decimal point"<<std::endl;
    std::cout<<"C++ style cast: "<<num_double_cpp<<std::endl;
    
    /*
    C++ style casts are more explicit, safer, readable than C style casts.
    C style casts can perform multiple types of conversion without any indication
    */

}