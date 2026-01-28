#include<iostream>
using namespace std;

class Logger{
    public:
        mutable int accessCount = 0;
        string message = "Incremented Successfully! ";
        void print() const{ // const function actually doesnt change the object 
            // it is used in logs, caches, counters which actually doesnt change the object just the internal data

            
            ++accessCount;
            
            cout<<"Current AccessCount = "<<accessCount<<endl;
            cout<<message<<endl;
        }
};

int main(){
    Logger logger;
    cout<<"AccessCounter before incrementing: "<<logger.accessCount<<endl;
    logger.print();
    cout<<"AccessCounter After incrementing: "<< logger.accessCount<<endl;

}