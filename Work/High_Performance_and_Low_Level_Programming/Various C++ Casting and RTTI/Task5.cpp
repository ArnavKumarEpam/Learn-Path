#include<iostream>

class Animal{
    public:
        virtual void speak() const{
            std::cout<<"Animal speaks! \n";
        }
        virtual ~Animal(){
            std::cout<<"Animal Destructor called! \n";

        }
};

class Dog : public Animal{
    public:
        void speak() const{
            std::cout<<"Dog speaks! \n";
        }
        void fetch() const{
            std::cout<<"Dog fetches! \n";
        }
        ~Dog(){
            std::cout<<"Dog destructor called! \n"; }
};

class Cat : public Animal{
    public:
        void speak() const{
            std::cout<<"Cat speaks! \n";
        }
        void scratch() const{
            std::cout<<"Cat scratches! \n";
        }
        ~Cat(){
            std::cout<<"Cat destructor called! \n"; }
};

void identifyAnimal(Animal *a){
    Dog *d = dynamic_cast<Dog*> (a);
    Cat * c = dynamic_cast<Cat *> (a);
    std::cout<<"typeid: "<<typeid(*a).name()<<std::endl;
    if(d){
        std::cout<<"Its a Dog! \n";
        d -> fetch();
        return;
    }
    else if(c){
        std::cout<<"Its a Cat \n";
        c -> scratch();
        return;
    }
    else std::cout<<"Unknown Animal \n";


}

int main(){
    Animal * a[2] = {new Dog(), new Cat()};
    for(int i = 0 ; i < 2 ; i++){
        a[i] -> speak();
        identifyAnimal(a[i]);
    }
}
