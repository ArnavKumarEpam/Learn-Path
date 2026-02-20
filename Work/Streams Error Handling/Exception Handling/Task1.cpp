

#include<iostream>
#include<exception>
#include<limits>
double divide(int numerator, int denominator){
    
        if(denominator == 0) throw std::runtime_error("Division by zero cannot be performed.");
    
    return (double)numerator / denominator;
    

}

int main(){
    std::cout<<"Enter the Numerator: ";
    int numerator ;
   
   while(!(std::cin >> numerator)){
    std::cout<<"Only Numeric Values allowed! \nEnter Numerator Again: ";
    std::cin.clear();
    std::cin.ignore();
   }
    int denominator ;
    std::cout<<"Enter the Denominator: ";
    
    while(!(std::cin >> denominator)){
    std::cout<<"Only Numeric Values allowed! \nEnter Denominator Again: ";
    std::cin.clear();
    std::cin.ignore();
   }
    try{
        double result = divide(numerator, denominator);
        std::cout<<"Division: "<<result;
    }
    catch(const std::runtime_error &e){
        std::cout<<"Error: "<<e.what();
    }
}