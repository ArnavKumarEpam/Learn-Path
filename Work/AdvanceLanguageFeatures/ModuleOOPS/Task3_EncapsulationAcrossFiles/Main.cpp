#include<iostream>
#include"Student.h"

using namespace std;

int main(){
    Student s; // object of Student class 
    s.setRollNo(101); // setter function called for RollNo
    s.setName("ABC"); // setter function called for Name
    s.setMarks(100); // setter function called for Marks
    int marks = s.getMarks();
    cout<<"Student having RollNo: "<<s.getRollNo()<<" and Name: "
    << s.getName()<<" and Marks: "<< (marks > 100 || marks < 0 ? "Invalid Input" : to_string(marks) )<< endl; // getter functions called for RollNo, Name, Marks
    return 0;
}