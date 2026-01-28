#include<bits/stdc++.h>
using namespace std;

class InheritanceBase {
    private:
    int num = 20;

    public:
    int getNum(){
        return num;
    }   
    void setNum(int n){
        num = n;
    }
    virtual void display() = 0;
};
class InheritanceChild : public InheritanceBase{
    public:
    void display() override{
        cout<<"Child Class Display Function"<<endl;
    }
    void show(){
        cout<<"Child Class Show Function"<<endl;
        cout<<"Num: "<<InheritanceBase::getNum()<<endl;
    }
    void show(int x){
        cout<<"Child Class Show Function with parameter: "<<x<<endl;
    }
};


int main(){
    // InheritanceBase *obj = new InheritanceChild();
    // // obj->setNum(50);
    // cout<<"Num: "<<obj->getNum()<<endl;
    // obj->display();
    // InheritanceChild *childObj = new InheritanceChild();
    // childObj->show();
    // childObj->show(10);
    

}