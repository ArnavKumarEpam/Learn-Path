#include<iostream>
using namespace std;

class DynamicArray{
    int * data;
    int size;
    public:
        DynamicArray(){}
        DynamicArray(int size){
            this -> size = size;
            data = new int[size];
            for(int i = 0 ; i < size ; i++){
                data[i] = i + 1;
            }
        }

        DynamicArray(const DynamicArray &originalObj){
            this -> size = originalObj.size;
            data = new int[size];
            cout<<"Copying data from original object"<<endl;
            for(int i = 0 ; i < size ; i++){
                
                this -> data[i] = originalObj.data[i];
            }
        }

        ~DynamicArray(){
            cout<<"Memory freed"<<endl;
            delete []data;
        }
        void setValue(int index, int value){
            if(index >= 0 && index < size) data[index] = value;
        }

        void show(){
            cout<<"Elements of the Array: "<<endl;
            for(int i = 0 ; i < size ; i++){
                cout<<"Element "<< i + 1 << ": " << data[i]<<endl;
            }
        }
};

int main(){
    DynamicArray originalObj(5); // original object 
    DynamicArray shallow = originalObj; // shallow copy object = operator 
    originalObj.show(); // displays values
    shallow.show(); 


    DynamicArray copyObj(originalObj); // copy constructor does deep copy
    copyObj.setValue(1, 100);
    originalObj.show(); // no change should be there in the data of original object
    copyObj.show(); // change happens at index 1 
    





}