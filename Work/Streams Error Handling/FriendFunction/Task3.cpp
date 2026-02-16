#include<iostream>

class Circle;

class Rectangle{
    private:
        double length, width;
    public:
        Rectangle(double length, double width) : length(length), width(width){}
        friend double compareArea(const Rectangle&rectangle, const Circle&cicle);
};

class Circle{
    private:
        double radius;
    public:
        Circle(double radius) : radius(radius){}
        friend double compareArea(const Rectangle&rectangle, const Circle&circle);
};

double compareArea(const Rectangle &rectangle, const Circle &circle){
    double rectangleArea = rectangle.length * rectangle.width;
    double circleArea = 3.14 * circle.radius * circle.radius;
    if(rectangleArea > circleArea){
        std::cout<<"Rectangle has more Area than Circle! \n";
        std::cout<<"Area Of Rectangle: ";
        return rectangleArea;
    }
    else if(rectangleArea == circleArea){
        std::cout<<"Both Rectangle and Circle have equal Area! \n";
        std::cout<<"Area of Both: ";
        return rectangleArea;
    }
    else{
        std::cout<<"Circle has more Area than Rectangle! \n";
        std::cout<<"Area of Circle: ";
        return circleArea;
    }
}
int main(){
    Rectangle rectangle(10.0, 20.0);
    Circle circle(42);
    std::cout<<compareArea(rectangle, circle);
}