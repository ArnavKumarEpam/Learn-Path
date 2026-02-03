#include<iostream>
#include <vector>

class Employee{ // Abstract class for abstraction
    private: // private access specifier showcases encapsulation
        std::string name;
        int id;
    public:
        Employee(std::string name, int id){
            if(name.empty()){
                throw std::invalid_argument("Name of an Employee cannot be empty! ");
            }
            if(id <= 0){
                throw std::invalid_argument("Id of an Employee cannot be less than 0! ");
            }
            this -> name = name;
            this -> id = id;
        }
        virtual void display(){
            std::cout<<"Employee ID: "<<id<<" and EmployeeName: "<<name<<std::endl;
        }

        virtual double calculatePay() const = 0; // pure virtual function for runtime polymorphism
};

class SalariedEmployee : public Employee{ // inheriting abstract class Employee showcasing inheritance
    private : // access specifiers showcases encapsulation
        double salary;
    public:
    SalariedEmployee(int id, std::string name, double salary):Employee(name , id){
        if(salary <= 0){
            throw std::invalid_argument("Invalid Salary cannot be less than 0.");
        }
        this -> salary = salary;
    }
    double calculatePay() const override{ // function overriding 
        return salary;
    }

};

class HourlyEmployee : public Employee{ // inheriting abstract class Employee showcasing inheritance
    private : // access specifiers showcases encapsulation
        double hourlyRate;
        double hoursWorked;
    public:
    HourlyEmployee(int id, std::string name, double hourlyRate, double hoursWorked):Employee(name , id){
        if(hourlyRate <= 0){
            throw std::invalid_argument("Hourly Rate cannot be less than 0! ");
        }
        if(hoursWorked <= 0){
            throw std::invalid_argument("Hours worked cannot be negative! ");
        }
        this -> hourlyRate = hourlyRate;
        this -> hoursWorked = hoursWorked;
    }
    double calculatePay() const override{ // runtime polymorphism
        return hourlyRate * hoursWorked;
    }

};

int main(){
    std::vector<Employee*> ptrList;
    SalariedEmployee salariedEmployee(101, "ABC", 50000);
    Employee *salaryPtr = &salariedEmployee;
    ptrList.push_back(salaryPtr);
    HourlyEmployee hourlyEmployee(102, "DEF", 7.8, 8);
    Employee * hourlyPtr = &hourlyEmployee;
    ptrList.push_back(hourlyPtr);

    // SalariedEmployee salariedEmployee2(103, "JKL", 0);
    // Employee *salaryPtr2 = &salariedEmployee2;
    // ptrList.push_back(salaryPtr2);

    for(int i = 0 ; i < ptrList.size() ; i++){
        ptrList[i]->Employee::display(); // displaying the details of the Employee
        std::cout<<"Salary: "<<ptrList[i]->calculatePay()<<std::endl;  //displaying the salary of the Employee
    }


    

}