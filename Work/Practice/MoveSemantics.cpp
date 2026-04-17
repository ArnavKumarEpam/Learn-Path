#include<bits/stdc++.h>
using namespace std;

class MyClass{
    int * data;
    int size;
    public:
        MyClass() : data(nullptr), size(0){// default
            cout<<"Default Constructor! Size: "<<size<<endl;
        } 
        MyClass(int size) : data(new int[size]), size(size){ // parameterized
            cout<<"Constructor! Size: "<<size<<endl;
        }
        MyClass(const MyClass &copy) : size(copy.size), data(new int[size]){ // copy constructor
            cout<<"Copy Constructor!"<<endl;
            for(int i = 0 ; i < size ; i++){
                data[i] = copy.data[i];
            }
        }
        MyClass(MyClass &&move) noexcept : size(move.size), data(move.data) { // move constructor
            cout<<"Move Constructor!"<<endl;
            move.data = nullptr; // prevent double deletion
            move.size = 0;
        }
        ~MyClass(){ // destructor
            cout<<"Destructor! Size: "<<size<<endl;
            delete[] data;
        }
        MyClass &operator=(const MyClass &copy){ // copy assignment
            cout<<"Copy Assignment!"<<endl;
            if(this != &copy){
                delete[] data; // free existing resource
                size = copy.size;
                data = new int[size];
                for(int i = 0 ; i < size ; i++){
                    data[i] = copy.data[i];
                }
            }
            return *this;
        }

        MyClass &operator=(MyClass &&move) noexcept { // move assignment
            cout<<"Move Assignment!"<<endl;
            if(this != &move){
                delete[] data; // free existing resource
                size = move.size;
                data = move.data;
                move.data = nullptr; // prevent double deletion
                move.size = 0;
            }
            return *this;
        }
        void print(){
            if(data == nullptr) cout<<"NULLPTR!"<<endl;
            else cout<<"Address: "<<(void*)data<<endl;
        }

};

int main(){
    MyClass obj1(10);
    obj1.print();
    MyClass obj2 = obj1; // copy constructor
    obj2.print();
    MyClass obj3 = move(obj1); // move constructor
    obj3.print();
    obj1.print(); // obj1 is in a valid but unspecified state after move
    MyClass obj4;
    obj4 = obj2; // copy assignment
    obj4.print();
    MyClass obj5;
    obj5 = move(obj3); // move assignment
    obj5.print();

}