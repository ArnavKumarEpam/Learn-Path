#include<iostream>
using namespace std;

class DynamicArray{
    private:
        int log;
    public:
        DynamicArray(){}
        DynamicArray(int index) : log(index){
            cout<<"Constructor called for index: "<<index << " and pointer: "<< this <<endl;
        }
        ~DynamicArray(){
            cout<<"Destructor called for index: "<<log << " and pointer :" << this <<endl;
        }
        

};


class DestructorDemo : public DynamicArray{
    public:
        void demoDestructors(){
           DynamicArray arr[3] = {DynamicArray(1), DynamicArray(2), DynamicArray(3)};
            
        } // destructor is called in reverse order 3 -> 2 -> 1
};




int main(){
    // DynamicArray dA;
    DestructorDemo dD;
    dD.demoDestructors();
    
}