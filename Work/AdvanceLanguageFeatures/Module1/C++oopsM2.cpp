//
// Created by ArnavKumar on 23-01-2026.
//
#include<iostream>
using namespace std;

struct Point { // Point structure
    int x;
    int y;
};

class Rectangle { // Rectangle class

    int length;
    int width;
public:
    void setLength(int length) { // setter for length
        this -> length = length;
    }
    void setWidth(int width) { // setter for width
        this -> width = width;
    }
    int getLength() {return length;} // getter for length
    int getWidth() {return width;} // getter for width
};

int main() {
    cout<<"Variables of Structure (Point) are: "<<endl;
    Point p; // instance of Point structure

    p.x = 10; // assigning value to x
    p.y = 20; // assigning value to y
    cout<< p.x << " " << p.y <<endl;

    cout<<"Variables of Class (Rectangle) are: "<<endl;
    
    Rectangle r; // instance of Rectangle class
    r.setLength(20); // setter for length
    r.setWidth(10); // setter for width

    // Accessing private variable of class through getters
    cout<< r.getLength() << " " << r.getWidth(); // display values of length and width through getters

    // "Private Variables of Class cannot be accessed directly"
    // cout<<r.length<<endl;


}