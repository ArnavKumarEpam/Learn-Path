#include <bits/stdc++.h>
using namespace std;

class A {
public:
    int a;
};

class B : virtual public A {
public:
    int b;
};

class C : virtual public A {
public:
    int c;
};

class D : public B, public C {
public:
    int d;
};

int main() {
    // cout << "Size of A: " << sizeof(A) << endl;
    // cout << "Size of B: " << sizeof(B) << endl;
    // cout << "Size of C: " << sizeof(C) << endl;
    // cout << "Size of D: " << sizeof(D) << endl;
    // B b;
    // cout<<sizeof(b)<<endl;
    float a = 23.53333;
 cout << floor(a) << endl;
 cout << ceil(a) << endl;
 cout << trunc(a) << endl;
 cout << round(a) << endl;
 cout << setprecision(2) << a;
 return 0; 

    return 0;
}