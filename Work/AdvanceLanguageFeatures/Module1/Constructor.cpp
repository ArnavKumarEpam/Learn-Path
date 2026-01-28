#include<iostream>
using namespace std;

class Memory{
    int num1;
    // int num2;
    public:
        Memory(int n){
            num1 = n;
        }
        // Memory(int num1, int num2){
        //     this -> num1 = num1;
        //     this -> num2 = num2;
        // }
        int mul() {return num1;}
        // int mul(){return num2 * num1;}
};

int main(){
    // Memory memory(10, 20); // valid constructor
    // Memory cons{10, 20}; // valid constructor
    Memory constr = 10;
    Memory sidt = {20};
    cout<<constr.mul()<<endl;
    cout<<sidt.mul()<<endl;

    // Memory memory1(); // not a default contructor its Memory class return type function
    // cout<<cons.mul();
    
}
 