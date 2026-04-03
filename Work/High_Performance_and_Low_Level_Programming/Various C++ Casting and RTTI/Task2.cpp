#include<iostream>

class Shape{
    public:
        virtual void draw() const{
            std::cout<<"Drawing shape! \n";
        }
        virtual ~Shape(){
            std::cout<<"Shape destructor called\n";
        }
};

class Circle : public Shape{
    public:
        void draw() const{
            std::cout<<"Drawing Circle! \n";
        }
        ~Circle(){
            std::cout<<"Circle Class Destructor called! \n";
        }
};

class Rectangle : public Shape{
    public:
        void draw() const{
            std::cout<<"Drawing Rectangle! \n";
        }
        ~Rectangle(){
            std::cout<<"Rectangle Class Destructor called! \n";
        }
};

int main(){
    Shape *s1 = new Circle();

    Circle * C = static_cast<Circle *> (s1);
    C->draw(); // This will work but is unsafe if s1 was not actually a Circle

    Circle * C2 = dynamic_cast<Circle *> (s1);
    if(C2){
        C2->draw();
    } else {
        std::cout << "Dynamic cast failed\n";
    }

    Rectangle * R = dynamic_cast<Rectangle *> (s1);
    if(R){
        R->draw();
    } else {
        std::cout << "Dynamic cast to Rectangle failed\n"; // This will fail and return nullptr since s1 is not a Rectangle
    }
    delete s1; // Properly deletes the Circle object and calls the correct destructors


}
