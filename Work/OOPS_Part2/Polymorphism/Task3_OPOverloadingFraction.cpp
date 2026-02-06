#include<iostream>

/*
Operator Overloading allows us to use operators like ==, <, > !=, +, -, /, << and many more
    For Assignment Operators we need to return bool as they return true or false value when compare any two values
*/
class Fraction{

    private:

        int numerator;
        int denominator;

    public:

        Fraction(int numerator, int denominator):numerator(numerator), denominator(denominator){}

        bool operator == (const Fraction &otherObject){ // Overloading ==
            
            return (this->numerator * otherObject.denominator == this->denominator * otherObject.numerator);
        }

        bool operator < (const Fraction &otherObject){ // Overloading < 
            return (this->numerator * otherObject.denominator < this->denominator * otherObject.numerator);
        }
};
int main(){

    Fraction f1(1, 2);
    Fraction f2(2, 4);
    Fraction f3(1, 3);

    if(f3 < f2){ // Check if fraction 3 is less than fraction 2
        std::cout<<"F3 is smaller than F2"<<std::endl;
    }
    else{ // If not less than
        std::cout<<"F3 is greater than F2"<<std::endl;
    }
    if(f1 == f2){ // Check if fraction 1 is equal to fraction 2
        std::cout<<"F1 and F2 are equal "<<std::endl;
    }
    else{ // If not equal
        std::cout<<"F1 is not equal to F2 "<<std::endl;
    }
}