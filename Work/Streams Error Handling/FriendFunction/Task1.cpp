#include<iostream>

class Box{
    private:
        double length, width, height;
    public:
        Box(double length, double width, double height) : length(length), width(width), height(height){}
        friend double volume(const Box &box);
};
// friend function makes a block in which we can access the private members of the class 
double volume(const Box &box){
    return box.length * box.width * box.height;
}

int main(){
    Box box(2.0, 3.0, 4.0);
    std::cout<<volume(box);

}