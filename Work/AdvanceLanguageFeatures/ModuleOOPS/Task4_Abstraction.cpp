#include<iostream>
#include <cmath>
#include<vector>

using namespace std;

class Shape{ // Abstract class

    public:
        virtual double area() const = 0;// pure virtual function of area
        virtual double perimeter() const = 0; // pure virtual function of perimeter

};

class Circle : public Shape{ // Circle class inheriting Shape Abstract class
    private:
    double radius;
    public:
        Circle(double Radius){
            radius = Radius;
        }
        double area() const override{ // overriding area function
            cout<<"Area of Circle: ";
            return 3.14 * radius * radius;
        }
        double perimeter() const override{ // overriding perimeter function
            cout<<"Perimeter of Circle: ";
            return 2 * 3.14 * radius;
        }

};
class Rectangle : public Shape{ // Rectangle class inheriting Shape Abstract class
    private:
    double length;
    double width;
    public:
        Rectangle(double Length, double Width){
            length = Length;
            width = Width;
        }
        double area() const override{
            cout<<"Area of Rectangle: ";
            return length * width;
        }
        double perimeter() const override{
            cout<<"Perimeter of Rectangle: ";
            return 2 * (length + width);
        }
};

class Triangle : public Shape{ // Triangle class inheriting Shape Abstract class
    private:
    double side1;
    double side2;
    double side3;

    public: 
        Triangle(double sideA, double sideB, double sideC){
            side1 = sideA;
            side2 = sideB;
            side3 = sideC;
        }
        double area() const override{ // overriding area function
            // sum of two should be greter than third side
            if(side1 + side2 <= side3){
                cout<<"The sum of two sides should be greater than third side! "<<endl;
                return 0.0;
            }
            cout<<"Area of Triangle: ";
            double semiPerimeter = (side1 + side2 + side3 ) / 2;
            double Area = sqrt(semiPerimeter*(semiPerimeter - side1) *
             (semiPerimeter - side2 ) * (semiPerimeter - side3));
             return Area;

        }
        double perimeter()const override{ // overriding permimeter function
            cout<<"Perimeter of Triangle: ";
            return side1 + side2 + side3;
        }
};

int main(){
    vector<Shape*> pointers; // vector of Shape* data type
    Rectangle *rect = new Rectangle(10, 20); // object creation for Rectangle class
    Circle *cir = new Circle(7); // object creation for Circle class
    Triangle *tri = new Triangle(20, 20, 30); // object creation for Triangle class


    // Polymorphism and Abstraction
    // In polymorphism the base class pointer points to derived object and with the help of virtual derived function is called and executed
    Shape * rectangle = rect; // Shape * pointer pointing to the object of Rectangle class
    pointers.push_back(rectangle);
    Shape * circle = cir; // Shape * pointer pointing to the object of Circle class
    pointers.push_back(circle);
    Shape * triangle = tri; // Shape * pointer pointing to the object of Triangle class
    pointers.push_back(triangle);

    for(int i = 0 ; i < pointers.size() ; i++){
        cout<<pointers[i]->area()<<endl; // Calling the area overridden function in child classes
        cout<<pointers[i]->perimeter()<<endl; // Calling the perimeter overridden function in child classes
    }

    // freeing the vector
    pointers.clear();
    pointers.shrink_to_fit();
    delete rect;
    delete cir;
    delete tri;


    return 0;

    

}