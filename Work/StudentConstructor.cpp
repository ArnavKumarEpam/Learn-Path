#include<iostream>
using namespace std;

class Student{
    private:
        int rollNo = 0;
        string name = "Unknown";
        char grade = 'U';
    public:
        Student(){ // default constructor
            cout<<"Default Constructor has been called! "<<endl;
        }
        // Parameterized constructor / initialization list
        Student(int roll, string Name, char result): rollNo(roll), name(Name), grade(result){
            cout<<"Parameterized Constructor Called! "<<endl;
        }
        int getRollNo(){return rollNo;} // getter for RollNo
        string getName(){return name;} // getter for Name
        char getGrade(){return grade;} // getter for Grade

};

int main(){
    Student defaultConstructorStudent; // default constructor
    cout<<"Diplaying the values initialized by default constuctor: "<<endl;
    cout<<"The RollNo of the Student: "<<defaultConstructorStudent.getRollNo()<<endl;
    cout<<"The Name of the Student: "<<defaultConstructorStudent.getName()<<endl;
    cout<<"The Grade of the Student: "<<defaultConstructorStudent.getGrade()<<endl;
    // parameterized contructor
    Student parameterizedConstructorStudent(1, "Arnav", 'A');
    cout<<"Diplaying the values initialized by parameterized constuctor: "<<endl;
    cout<<"The RollNo of the Student: "<<parameterizedConstructorStudent.getRollNo()<<endl;
    cout<<"The Name of the Student: "<<parameterizedConstructorStudent.getName()<<endl;
    cout<<"The Grade of the Student: "<<parameterizedConstructorStudent.getGrade()<<endl;
}