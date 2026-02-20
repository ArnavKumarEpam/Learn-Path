#include<iostream>

class LivingBeing{
    private:
        int id;
        std::string name;
    public:
        LivingBeing(){} // default constructor needed for compiler to initialize the LivingBeing even though most derived class initialises it later
        LivingBeing(int id, std::string name) : id(id), name(name){}
        void show(){
            std::cout<<"Name of the livingBeing: "<<name<<" and the instance address: "<<this<<std::endl;
        }
        virtual ~LivingBeing(){} // destructor
};

class Animal : virtual public LivingBeing{
    public:
        Animal() : LivingBeing(){}
};
class Plant : virtual public LivingBeing{
    public:
        Plant() : LivingBeing(){}
};

class Hybrid : public Animal, public Plant{
    public:
        Hybrid(int id, std::string name) : LivingBeing(id, name), Animal(), Plant(){} // initialises LivingBeing
};

int main(){
    Hybrid hybrid(1, "Chimera");
    Animal * animal = &hybrid;
    // Animal subobject
    ((LivingBeing*)(Animal*)(&hybrid))->show();
    // Plant subobject
    ((LivingBeing*)(Plant*)(&hybrid)) -> show();
}