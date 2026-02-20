#include<iostream>
using namespace std;
class Square{
    private:
    int side;
    public:
    Square(int side){
        this -> side = side;
    }
    int getSide(){return side;}
};

int main(){
    Square *ptr, *pptr;
    Square sq(2);
    ptr = &sq;
    pptr = new Square[2]{{4}, {6}};
    cout<<ptr -> getSide()<<endl;
    cout<<pptr[0].getSide() <<endl;
    cout<<(*pptr).getSide()<<endl;

}