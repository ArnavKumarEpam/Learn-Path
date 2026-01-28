#include<iostream>
#include "debug.h"

int main(){
    std::cout<<"Program for debugging started"<<std::endl;
    DEBUG_PRINT("This is a debug message.");
    std::cout<<"Program for debugging ended"<<std::endl;
    return 0;
}