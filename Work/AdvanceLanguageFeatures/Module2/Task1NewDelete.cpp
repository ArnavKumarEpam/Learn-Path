#include<iostream>
using namespace std;

class Tracker{
    public:
        static int counter;
        void* operator new(size_t size){
            void *ptr = :: operator new(size); // allocate memory to the pointer for future use
            counter++; // increment the counter
            return ptr;
        }
        void operator delete(void *ptr){
            counter--; // decrement the counter
            ::operator delete (ptr); // frees the memory allocated to the pointer earlier
            cout<<"Freed the memory of pointer: "<<ptr<<endl;
        }
        Tracker(){ // constructor
            cout<<"Default Constructor! "<<endl;
        }
        ~Tracker(){ // destructor
            cout<<"Destructor! "<<endl;
        }
};

int Tracker :: counter = 0;
int main(){
    Tracker *t1 = new Tracker; // pointer 1
    Tracker *t2 = new Tracker; // pointer 2
    Tracker *t3 = new Tracker; // pointer 3 
    delete t3; // deleting the pointer
    delete t2; // deleting the pointer

    if(Tracker :: counter > 0){ // checking is there a memory leak as some objects are not deleted
        cout<<"Memory Leak Detected! Number of Objects still not deleted: "<<Tracker::counter<<endl;
    }else{
        cout<<"No Memory Leak Detected! Number of Objects still not deleted: "<<Tracker :: counter <<endl; 
    }

    
}