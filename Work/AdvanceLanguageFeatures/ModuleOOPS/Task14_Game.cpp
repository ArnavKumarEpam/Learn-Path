#include<iostream>
#include<vector>

/*
    OOPS stands for Object Oriented Programming
    It has 4 pillars
        1. Inheritance: Shown by inheriting Character class in Warrior and Mage class
        2. Encapsulation: Shown by using access specifiers and getters and setters
        3. Polymorphism: Shown by overriding attack function in Warrior and Mage class
        4. Abstraction: Shown by Character class whose object is not instantiated
*/

class Character{// showcases Abstraction
    private: // encapsulation
        int health;
        int mana;
    public: 
        Character(int health, int mana){ 
            if(health >= 0 && health <= 100){
                this -> health = health;
            }
            else throw std::invalid_argument("Health should be in the range of 0 - 100");
            if(mana >= 0 && mana <= 100){
                this -> mana = mana;
            }
            else throw std::invalid_argument("Mana should be in the range of 0 - 100");
        }
        void setHealth(int health){ // setter
            if(health >= 0 && health <= 100){
                this -> health = health;
            }
            else throw std::invalid_argument("Health should be in the range of 0 - 100");
        }
        void setMana(int mana){// setter
            if(mana >= 0 && mana <= 100){
                this -> mana = mana;
            }
            else throw std::invalid_argument("Mana should be in the range of 0 - 100");
        }
        int getHealth() const {return health;} // getter
        int getMana() const {return mana;} // getter
        virtual void attack() = 0; // polymorphism
};

class Warrior : public Character{ // inheritance
    public:
        Warrior(int health = 0, int mana = 0): Character(health, mana){}
        void attack() override{ // runtime polymorphism
            if(getHealth() > 0){
                std::cout<<"Warrior Attacks with Melee. "<<std::endl;
            }
            else{
                std::cout<<"Warrior's Health is 0"<<std::endl;
            }
        }

};

class Mage: public Character{ // inheritance
    public:
        Mage(int health = 0, int mana = 0): Character(health, mana){}
        void attack() override{ // runtime polymorphism
            if(getMana() > 0){
                std::cout<<"Mage cast a spell. "<<std::endl;
            }
            else{
                std::cout<<"Mage has no more Mana"<<std::endl;
            }
        }
};

int main(){
    
    Warrior warrior(50, 10);
    Mage mage(50, 40);
    Character *ptrWarrior = &warrior;
    Character *ptrMage = &mage;
    std::vector<Character*> ptrList;
    ptrList.push_back(ptrWarrior);
    ptrList.push_back(ptrMage);

    for(int i = 0 ; i < ptrList.size() ; i++){
        ptrList[i]->attack();
    }
    return 0;
}

