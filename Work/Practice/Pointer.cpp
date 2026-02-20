#include<bits/stdc++.h>
using namespace std;

class A{
    public:
    int Ab = 200;
};

int main(){
    // int a = 10;
    // int *ptr = &a;
    // *ptr *= 10;
    // cout<<a;

    // const int *p = &a;
    // a = 200;
    // cout<<*p;
    
    // int num = 10;
    // int *firstPointer = &num;
    // int **secondPointer = &firstPointer;
    // cout<<firstPointer << " " << secondPointer;
    // int val = 100;
    // int const* ptr = &val;
    // cout<<ptr<<endl;
    // ptr++;
    // cout<<ptr;
    // double dVal = 10.00;
    // double *dptr = &dVal;
    // cout<<sizeof(dptr);
    // cout<<"\n" <<sizeof(dVal);
    // cout<<"\n"<<sizeof(void*);
   
    shared_ptr<A> sp = make_shared<A>();
    weak_ptr<A> wp = sp;
    if(auto t = wp.lock()){
        // sp.reset();
        // t.reset();
        // cout<<t->Ab<<endl;
        cout<<sp.use_count()<<endl;
    }
    
}

