#include<iostream>
#include"env.h" // included the env.h file for API_URL macro

int main(){
    std::cout<<"API URL is: "<< API_URL <<std::endl; // printing the API URL based on environment
    return 0;
}