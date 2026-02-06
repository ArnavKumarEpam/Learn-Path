#include<iostream>
#include <vector>

class Employee{ // Abstract class for abstraction
    private: // private access specifier showcases encapsulation
        
    public:
        
        virtual double calculatePay() const = 0; // pure virtual function for runtime polymorphism
};

class SalariedEmployee : public Employee{ // inheriting abstract class Employee showcasing inheritance
    private : // access specifiers showcases encapsulation
        double salary;
    public:
    SalariedEmployee (double salary){
        if(salary <= 0){
            throw std::invalid_argument("Invalid Salary cannot be less than 0.");
        }
        this -> salary = salary;
    }
    double calculatePay() const override{ // function overriding 
        std::cout<<"Salary of Salaried Employee: ";
        return salary;
    }

};

class HourlyEmployee : public Employee{ // inheriting abstract class Employee showcasing inheritance
    private : // access specifiers showcases encapsulation
        double hourlyRate;
        double hoursWorked;
    public:
    HourlyEmployee(double hourlyRate, double hoursWorked){
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
        std::cout<<"Salary of hourly Employe: ";
        return hourlyRate * hoursWorked;
    }

};

int main(){
    std::vector<Employee*> ptrList;
    SalariedEmployee salariedEmployee(50000);
    Employee *salaryPtr = &salariedEmployee;
    ptrList.push_back(salaryPtr);
    HourlyEmployee hourlyEmployee(1000, 8);
    Employee * hourlyPtr = &hourlyEmployee;
    ptrList.push_back(hourlyPtr);

    

    for(int i = 0 ; i < ptrList.size() ; i++){
        
        std::cout<<ptrList[i]->calculatePay()<<std::endl;  //displaying the salary of the Employee
    }


    return 0;

}