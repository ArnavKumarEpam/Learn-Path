#include<bits/stdc++.h>
using namespace std;

void passByValue(int x){
    x = x + 10;
    cout<<"Inside passByValue: "<<x<<endl;
}   

void pasByRef(int *x){
    *x = *x + 10;
    cout<<"Inside pasByRef: "<<*x<<endl;
}
int main(){
    // int n = 10;
    // int *pN = &n;
    // cout << "Value of n: " << n << endl;
    // cout << "Address of n: " << &n << endl;

    // string str = "Hello, World!";
    // cout<<str.substr(0, str.size() - 2)<<endl;
    int value = 20;
    int reference = 30;
    pasByRef(&reference);
    passByValue(value);
    cout<<reference<<endl;
    cout<<value<<endl;
}
