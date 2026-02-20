#include<iostream>
using namespace std;

class A{
    private:
        int a = 10;
    public:
    friend void show(A& obj);
};
void show(A &obj){
    cout<<obj.a;
}

int main(){
    A a;
    show(a);
}