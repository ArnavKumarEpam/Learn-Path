#include<iostream>
using namespace std;

#define SQUARE(x) (x*x)

class Math{
    public:
        inline int square(int x){ return x*x;}

};
int main(){
    Math m;
    cout<<"Calculating the square of: 3, the sqaure should be 9."<<endl;
    cout<<m.square(3)<<endl;
    cout<<SQUARE(3)<< endl;

    cout<<"Calculating the square of: (1 + 2) the square should be: 9."<<endl;
    cout<<m.square(1+2)<<endl; // error prone
    cout<<SQUARE(6++)<<endl; // secure error free



}