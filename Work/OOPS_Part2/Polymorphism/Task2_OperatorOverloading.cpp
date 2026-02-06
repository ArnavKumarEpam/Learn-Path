#include<iostream>
#include <ostream>

/*Operator Overloading allows to use operators on user defined class structures, it happens at compile time\
    Rules for Operator Overloading
        1. Returns the object of the class
        2. ClassName operator (sign) (const object) return Object
    We usually use const with the object in the parameters to use the temporary object also
*/

class Complex{
    private:
        double real;
        double imag;
    public:
        Complex(double real, double imag){
            this -> real = real;
            this -> imag = imag;
        }
        
        
        Complex operator + (const Complex &otherObject){ // Operator Overloading (+)
            return Complex(this->real + otherObject.real, this -> imag + otherObject.imag);
        }

        friend std::ostream &operator << (std::ostream &os, const Complex &otherObject); // Operator Overloading (<<)
};

std::ostream &operator << (std::ostream &os, const Complex &otherObject){
    os << otherObject.real << " + " << otherObject.imag<<"i";
    return os;
}

int main(){
    Complex number1 = Complex(5.2, 6.4);
    Complex number2 = Complex(7.1, 8.9);
    Complex number3 = number1 + number2;
    std::cout<<number3<<std::endl;
    return 0;
}