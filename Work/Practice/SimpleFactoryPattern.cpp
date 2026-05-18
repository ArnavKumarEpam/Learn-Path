#include<bits/stdc++.h>
using namespace std;

class Burger{
    public:
        virtual void prepare() = 0; 
};

class CheeseBurger : public Burger{
    public:
        void prepare(){
            cout<<"Preparing Cheese Burger\n";
        }
};
class VegBurger : public Burger{
    public:
        void prepare(){
            cout<<"Preparing Veg Burger\n";
        }
};
class NonVegBurger : public Burger{
    public:
        void prepare(){
            cout<<"Preparing Non-Veg Burger\n";
        }
};
class BurgerFactory{
    public:
        Burger* createBurger(string type){
            if(type == "Cheese"){
                return new CheeseBurger();
            }
            else if(type == "Veg"){
                return new VegBurger();
            }
            else if(type == "NonVeg"){
                return new NonVegBurger();
            }
            else {
                return nullptr;
            }
        }
};
int main(){
    string burgerType = "Cheese";
    BurgerFactory *factory = new BurgerFactory();
    Burger* burger = factory->createBurger(burgerType);
    burger -> prepare();
    delete burger;
    delete factory;
}