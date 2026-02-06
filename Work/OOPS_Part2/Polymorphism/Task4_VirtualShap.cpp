#include<iostream>
#include<vector>

class Shape{ // abstract class Shape
    public:
        virtual double area() const = 0;
};

class Circle : public Shape{ // Circle class inheriting Shape (abstract class)
    private:
        double radius;
    public:
        Circle(double radius): radius(radius){}
        double area()const override{
            std::cout<<"Displaying the Area of Circle: ";
            return 3.14 * radius * radius;
        }
};

class Rectangle : public Shape{ // Rectangle class inheriting Shape (abstract class)
    private:
        double length;
        double width;
    public:
        Rectangle(double length, double width): length(length), width(width){}
        double area()const override{
            std::cout<<"Displaying the Area of Rectangle: ";
            return length * width;
        }
};

class Triangle : public Shape{ // Triangle class inheriting Shape (abstract class)
    private:
        double base;
        double height;
        
    public:
        Triangle(double base, double height): base(base), height(height){}
        double area() const override{
            std::cout<<"Displaying the Area of Triangle: ";
            return 0.5 * base * height;
        }
};

int main(){
    // vector of polymorphic objects: such that pointer is of Base class but actual object if of derived class
    std::vector<Shape *> ptrList; // vector of Shape type pointers 
    Rectangle rectangle(10, 20);
    ptrList.push_back(&rectangle);
    Circle circle(7);
    ptrList.push_back(&circle);
    Triangle triangle(10, 5);
    ptrList.push_back(&triangle);

    for(int i = 0 ; i < ptrList.size() ; i++){
        std::cout<<ptrList[i]->area()<<std::endl;

    }


}