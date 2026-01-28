// Online C++ compiler to run C++ program online
#include <iostream>
using namespace std;

class A{
    public:
    int x;
    A(){
    }
    A(A &obj){
        x = obj.x;
        cout<<"X is: "<<x<<endl;
    }
};


int main() {
    A obj;
    obj.x = 10;
    A obj2 = obj;

    // Write C++ code here
    // std::cout << "Try programiz.pro";

    return 0;
}