#include<iostream>
#include<vector>
#include <cmath>

class Shape{ // abstract class Shape
    public:
        virtual double area() const = 0;
        virtual double perimeter() const = 0;
        virtual ~Shape(){
            std::cout<<"Destructor!"<<std::endl;
        }
        
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
        double perimeter()const override{
            std::cout<<"Displaying the Perimeter of Circle: ";
            return 2 * 3.14 * radius;
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
         double perimeter()const override{
            std::cout<<"Displaying the Perimeter of Rectangle: ";
            return 2 * (length + width);
        }
};

class Triangle : public Shape{ // Triangle class inheriting Shape (abstract class)
    private:
        double side1;
        double side2;
        double side3;
        
    public:
        Triangle(double side1, double side2, double side3): side1(side1), side2(side2), side3(side3){}
        
        double area() const override{
            std::cout<<"Displaying the Area of Triangle: ";
            double semiPerimeter = (side1 + side2 + side3) / 2.0 ;
            double areaTriangle = sqrt(semiPerimeter * (semiPerimeter - side1) * (semiPerimeter - side2) * (semiPerimeter - side3));
            return areaTriangle;
        }
        double perimeter() const override{
            std::cout<<"Displaying the Perimeter of Triangle: ";
            return side1 + side2 + side3;
        }
};

int main(){
    // vector of polymorphic objects: such that pointer is of Base class but actual object if of derived class
    std::vector<Shape *> ptrList; // vector of Shape type pointers 
    Rectangle *rectangle = new Rectangle(10, 20);
    ptrList.push_back(rectangle);
    Circle *circle = new Circle(7);
    ptrList.push_back(circle);
    Triangle *triangle = new Triangle(100, 51, 150);
    ptrList.push_back(triangle);

    for(int i = 0 ; i < ptrList.size() ; i++){
        std::cout<<ptrList[i]->area()<<std::endl;
        std::cout<<ptrList[i]->perimeter()<<std::endl;

    }
    delete(rectangle);
    delete(circle);
    delete(triangle);
    
    


}