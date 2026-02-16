#include<iostream>

class Person{
    private:
        std::string name;
        int age;
    public:
        friend std::istream& operator>>(std::istream& is, Person& p);
        friend std::ostream& operator<<(std::ostream& os, const Person& p);
};
std::istream& operator>>(std::istream& is, Person& p){
    std::cout<<"Enter the the Name of the Person: ";
    getline(is >> std::ws, p.name);

    std::cout<<"Enter the Age of the Person: ";
    is >> p.age;
    return is;
}
std::ostream& operator<<(std::ostream& os, const Person& p){
    os<<"Name of the Person: "<< p.name<<std::endl;
    os<<"Age of the Person: "<<p.age<<std::endl;
    return os;
}

int main(){
    Person person1;
    Person person2;
    std::cin>>person1>>person2;
    std::cout<<person1<<person2;

    

}