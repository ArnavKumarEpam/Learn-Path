#include<iostream>
using namespace std;

class Counter{
    public:
    static int count; // static count variable 
        Counter(){ // constructor 
            count += 1; // incrementing the count
        }
        ~Counter(){ // destructor
            count -= 1; // decrementing the count variable
        }
        static int getCount(){ // function to return count
            return count;
        }
};

int Counter::count = 0; // initializing the count variable

void func(){
    Counter obj1; // obj3
    cout<<Counter::count<<endl;
}

int main(){
    
    Counter obj2; // obj1
    cout<<Counter::getCount()<<endl;
    Counter obj3; // obj2
    cout<<Counter::getCount()<<endl;
    func();
    // destructor is called after the func function
    cout<<Counter::getCount()<<endl;
    

}