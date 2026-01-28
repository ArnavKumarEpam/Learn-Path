#include<iostream>
#include<string>
#include"Student.h"
using namespace std;


void Student::setRollNo(int RollNo){ // setter function for RollNo
    rollNo = RollNo;
}

int Student::getRollNo(){ // getter function for RollNo
    return rollNo;
}

void Student::setName(string Name){ // setter function for Name
    name = Name;
}

string Student::getName(){ // getter function for Name
    return name;
}

void Student::setMarks(int Marks){ // setter function for Marks
    if(Marks<= 100 && Marks >= 0) marks = Marks;
    else {
        cout<<"Invalid Marks have to be in range of (0 - 100), Marks not set! "<<endl;
    }
}

int Student::getMarks(){ // getter function for Marks
    return marks;
}
        
        
        
