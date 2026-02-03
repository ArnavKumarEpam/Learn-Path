#include<iostream>

class Shape{
    public:
        virtual double area() = 0;
        virtual double perimeter() = 0;
        virtual void draw() = 0; 
};

class Circle : public Shape{
    double radius;
    public:
        Circle(double radius){
            this -> radius = radius;
        }
        double area() override{
            return 3.14 * radius * radius;
        }
        double perimeter() override{
            return 2 * 3.14 * radius;
        }

        void draw() override{
            std::cout<<"Drawing the shape of Circle! "<<std::endl;
        }
};

class Square : public Shape{
    double side;
    public:
        Square(double side){
            this -> side = side;
        }
        double area() override{
            return side * side;
        }
        double perimeter() override{
            return side * 4;
        }
        void draw() override{
            std::cout<<"Drawing the shape of Square! "<<std::endl;
        }

};

class Rectangle : public Shape{
    double length;
    double width;
    public:
        Rectangle(double length, double width){
            this -> length = length;
            this -> width = width;
        }
        double area() override{
            return length * width;
        }
        double perimeter() override{
            return 2*(length + width);
        }
        void draw() override{
            std::cout<<"Drawing the shape of Rectangle! "<<std::endl;
        }

};

int main(){
    Circle C(7);
    std::cout<<"Area of Circle: "<< C.area()<<std::endl;
    std::cout<<"Perimeter of Circle: "<< C.perimeter()<<std::endl;
    C.draw();

    Rectangle R(10, 20);
    std::cout<<"Area of Rectangle: "<< R.area()<<std::endl;
    std::cout<<"Perimeter of Rectangle: "<< R.perimeter()<<std::endl;
    R.draw();

    Square S(10);
    std::cout<<"Area of Square: "<<S.area()<<std::endl;
    std::cout<<"Perimeter of Square: "<< S.perimeter()<<std::endl;
    S.draw();
}