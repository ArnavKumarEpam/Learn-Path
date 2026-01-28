#include<iostream>
using namespace std;

class Item{
    public: 
        int val;
        Item(){
            cout<<"Constructor! Address of this object is: "<<this<<endl;
        }
        Item(int value){
            val = value;
            cout<<"Constructor! Address of this object is: "<<this<<endl;
        }
        void input(int value){
            val = value;
            cout<<"Value of the object is: "<<val<<endl;
        }
        ~Item(){
            cout<<"Destructor! Address freed: "<<this<<endl;
        }
};

int main(){
    Item *num = new Item(10);
    Item *arr = new Item[3];
    
    delete(num);
    for(int i = 0 ; i < 3 ; i++){
        arr[i].input(i + 1);
    }
    

    /*
        delete[] has extra information like array size which tells compiler to call destructor how many times
        but delete doesn't have this information 

        So, if we interchange them,
        delete on array of objects then it will delete the first object only other objects wont be deleted it might cause memory leak and undefined behaviour
        and delete[] on single object will try to find the extra information like size but it isn't there so it might corrupt the memory
    */
    // incorrect usage of delete[] and delete
    // delete []num; using delete[] on single object
    // delete arr; using delete on array of objects
    delete[] arr;
}