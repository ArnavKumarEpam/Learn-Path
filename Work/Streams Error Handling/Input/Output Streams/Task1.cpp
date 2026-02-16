#include<iostream> // Stream to facilitate input and output from user and to user
#include<string> // Includes string 

int main(){
    std::cout<<"Enter your Name: ";
    std::string name;
    getline(std::cin, name);
    std::cout<<"Enter your Age: ";
    int age;
    std::cin>>age;
    std::cout<<"Enter your City: ";
    std::string city;
    std::cin>>city;

    std::cout<<"\nHello "<<name<<", you are "<<age<<" and live in "<<city<<std::endl;

    return 0;
}