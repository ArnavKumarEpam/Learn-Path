// Online C++ compiler to run C++ program online
#include <iostream>
using namespace std;

class A{
    public:
        int num;
        string name;
    
        A(){}
        A(int num, string name){
            this -> num = num;
            this -> name = name;
        }
        A operator + (const A &a){// const here used for temporary object as we cannot modify them 
            return A(this->num + a.num, this->name + a.name);
        }
};
int main() {
    // Write C++ code here
    A a(5,"ABC");
    A b(6, "DEF");
    A c;
    c = a + A(7, "JKL"); // temporary object
    cout<<c.num<<" "<<c.name;

    return 0;
}