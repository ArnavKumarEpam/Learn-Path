#include<bits/stdc++.h>
using namespace std;

class Coffee{
    public:
        virtual void prepare() = 0;
};
class SimpleCoffee : public Coffee{
    public:
        void prepare(){
            cout<<"Preparing Simple Coffee";
        }
};
class MilkCoffee : public Coffee{
    public:
        void prepare(){
            cout<<"Preparing Milk Coffee";
        }
};
class LatteCoffee : public Coffee{
    public:
        void prepare(){
            cout<<"Preparing Latte Coffee";
        }
};
class DecoratorCoffee : public Coffee{
    
    public:
        Coffee * coffee;
        DecoratorCoffee(Coffee * c){
            this -> coffee = c;
        }
        void prepare(){
            coffee -> prepare();
        }
};
class SugarDecorator : public DecoratorCoffee{
    public:
        SugarDecorator(Coffee * c) : DecoratorCoffee(c){}
        void prepare(){
            coffee->prepare();
            cout<<" with Sugar";
        }
};
class MilkDecorator : public DecoratorCoffee{
    public:
        MilkDecorator(Coffee * c) : DecoratorCoffee(c){}
        void prepare(){
            coffee->prepare();
            cout<<" with Milk";
        }
};

int main(){
    Coffee * coffee = new SimpleCoffee();
    coffee = new SugarDecorator(coffee);
    coffee = new MilkDecorator(coffee);
    coffee->prepare();
}