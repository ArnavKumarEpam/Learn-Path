// #include<exception>
// #include<iostream>
// #include<vector>
// int main(){
//     // std::vector<int> v = {1, 2, 3, 4, 5};
//     // try{
//     //     std::cout<<v.at(4)<<std::endl;
//     // }
//     // catch(std::out_of_range e){
//     //     std::cout<<"MEssage: "<<e.what()<<std::endl;
//     // }
//     // std::cout<<"AAgya ladle\n";
//     try{
//         // throw 1;
//         // throw 1.1;
//         // throw 1.2f;
//         // throw 'a';
//         // throw "THis is the character array";
//         throw (std::string)"this is the string";
//     }
//     catch(const int &e){
//         std::cout<<"Integer Exception: "<<e<<std::endl;    
//     }
//     catch(const double &e){
//         std::cout<<"Double Exception: "<<e<<std::endl;    
//     }
//     catch(const float &e){
//         std::cout<<"Float Exception: "<<e<<std::endl;    
//     }
//     catch(const char &e){
//         std::cout<<"Character Exception: " <<e<<std::endl;
//     }
//     catch (const char *&e){
//         std::cout<<"Character Array Exception: "<<e<<std::endl;
//     }
//     catch(const std::string &e){
//         std::cout<<"String Exception: "<<e<<std::endl;
//     }
// }











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