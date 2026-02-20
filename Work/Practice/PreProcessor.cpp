#include<iostream>


#define max 100
int main(){
    // #if defined(max)
    //     std::cout<<"Max is defined as "<< max <<std::endl;
    
    // #elif (!defined(max))
    //     std::cout<<"Max is not defined"<<std::endl;
    
    // #else 
    // #error "This is else part"
    
    // #endif

    // #ifdef max 
    //     #undef max
    //     #define max 200
    // #endif
    #ifndef max
    #define max 200
    #endif
    std::cout<<"Max is defined as "<< max <<std::endl;


}