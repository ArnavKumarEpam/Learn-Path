#include<iostream>
#include <cmath>
#include<vector>

using namespace std;

class Shape{
    public:
        virtual double area() const = 0;
        virtual double perimeter() const = 0;

};

class Circle : public Shape{
    private:
    double radius;
    public:
        Circle(double Radius){
            radius = Radius;
        }
        double area() const override{
            cout<<"Area of Circle: ";
            return 3.14 * radius * radius;
        }
        double perimeter() const override{
            cout<<"Perimeter of Circle: ";
            return 2 * 3.14 * radius;
        }

};
class Rectangle : public Shape{
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

class Triangle : public Shape{
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
        double area() const override{
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
        double perimeter()const override{
            cout<<"Perimeter of Triangle: ";
            return side1 + side2 + side3;
        }
};

int main(){
    vector<Shape*> pointers;
    Rectangle rect(10, 20);
    Circle cir(7);
    Triangle tri(20, 20, 30);
    Shape * rectangle = &rect;
    pointers.push_back(rectangle);
    Shape * circle = &cir;
    pointers.push_back(circle);
    Shape * triangle = &tri;
    pointers.push_back(triangle);
    for(int i = 0 ; i < pointers.size() ; i++){
        cout<<pointers[i]->area()<<endl;
        cout<<pointers[i]->perimeter()<<endl;
    }

    // cout<<"Area's of different shapes: "<<endl;
    // cout<<"Area of Rectangle: "<<rectangle->area()<<endl;
    // cout<<"Area of Circle: "<<circle->area()<<endl;
    // cout<<"Area of Triangle: "<<triangle->area()<<endl;


    // cout<<"Perimeter of different shapes: "<<endl;
    // cout<<"Perimeter of Rectangle: "<<rectangle->perimeter()<<endl;
    // cout<<"Perimeter of Circle: "<<circle->perimeter()<<endl;
    // cout<<"Perimeter of Triangle: "<<triangle->perimeter()<<endl;

    

}