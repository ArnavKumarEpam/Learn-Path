#include<iostream>
using namespace std;
class Box{
    private:
        int length;
        int width;
        int height;
    public:
        void setDimensions(int length, int width, int height){ // setter method for dimensions
            // this pointer points to current object members and functions
            this -> length = length;
            this -> width = width;
            this -> height = height;
        }
        
        const Box &compareVolume(const Box &b){ // function to compare the volumes of both objects
            int volumeCurrent = length * width * height;
            int volumeOther = b.length * b.width * b.height;
            if(volumeCurrent >= volumeOther){
                return *this;
            }
            else return b;
        }
        void display(){ // displaying the dimensions
            cout<<"Length of the Box is: "<<length<<endl;
            cout<<"Width of the Box is: "<<width<<endl;
            cout<<"Height of the Box is: "<<height<<endl;
        }
};

int main(){
    Box b;
    b.setDimensions(10, 20, 30);

    Box a;
    a.setDimensions(30, 40, 50);
    Box ans = a.compareVolume(b); // copying another object
    cout<<"Box having larger Volume's dimensions are: "<<endl;
    ans.display();


}