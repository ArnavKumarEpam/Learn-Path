#include<iostream>
#include "config.h" // included the config.h file for VERSION macro

int main(){
    
    #if VERSION >= 3 // checks whether the version is stable or beta
            std::cout<<"Stable Version"<<std::endl; // prints stable for version more than or equal to 3
    #else 
            std::cout<<"Beta Version"<<std::endl; // else prints beta for version less than 3
    #endif
    return 0;
}