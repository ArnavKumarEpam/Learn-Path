#include<iostream>
using namespace std;

class LeakDemo{
    public:
        LeakDemo(){
            cout<<"Constructor! "<<endl;
        }
        ~LeakDemo(){
            cout<<"Destructor! "<<endl;
        }
};

int main(){
    for(int i = 1 ; i <= 1000 ; i++){
        LeakDemo *lD = new LeakDemo(); 
        // 1000 objects are created and each object goes out of scope with each iteration and all the pointers are lost
        // if the object be created normally stack memory then destructor would have called after each iteration as well but dynamically made objects need delete to free the memory
        
    }
    for(int i = 1 ; i <= 1000 ; i++){
        LeakDemo *lD = new LeakDemo();
        delete lD;
    }

}