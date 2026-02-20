#include<iostream>

class Person{
    public:
        virtual void displayInfo() = 0;
        virtual ~Person(){}
};

class Student : virtual public Person{
    protected:
        int rollNo;
    public:
        
        Student(int rollNo) : rollNo(rollNo){}
};

class Teacher : virtual public Person{
    protected:
        double salary;
    public:
        
        Teacher(double salary) : salary(salary){}
};

class TeachingAssistant : public Student, Teacher{
    public:
        TeachingAssistant(int rollNo, double salary) : Student(rollNo), Teacher(salary){}
        void displayInfo() override{
            std::cout<<"displayInfo() overriden in TeachingAssistant\n";
            std::cout<<"RollNo of Student: "<<rollNo<<", and Salary of the Teacher: "<<salary<<std::endl;
        }
};

int main(){
    TeachingAssistant teachingAssistant(101, 50000);
    teachingAssistant.displayInfo();
    // Address will be same for both as in virtual inheritance only one Person base subobject

    std::cout<<"Student SubObject: "<<(Person*)(Student*)&teachingAssistant<<'\n'; 
    std::cout<<"Teacher SubObject: "<<(Person*)(Teacher*)&teachingAssistant<<'\n';

    return 0;
}
