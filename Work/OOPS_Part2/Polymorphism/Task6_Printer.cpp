#include<iostream>
/*
    When the default arguements are there in the function compiler at compile time decide which object will execute it
    And in this case Printer * p = &cp p->print() compiler at compile time decides its a Printer class function
    But at run time it gets to know that object is of ColorPrinter so then it calls the print function of ColorPrinter but with arguements of Printer class function ("Base Printer")
    This can be corrected by having default arguements in the function of Base class only not in the Child class
*/
class Printer{
    public:
        virtual void print(const std::string &msg = "Base Printer"){
            std::cout<<msg<<std::endl;
        }
};

class ColorPrinter : public Printer{
    public:
        void print(const std::string &msg = "Color Printer") override{
            std::cout<<"This is the: "<<msg<<std::endl;
        }
};

int main(){
    ColorPrinter cp;
    cp.print();
    Printer *p = &cp;
    p ->print();
}