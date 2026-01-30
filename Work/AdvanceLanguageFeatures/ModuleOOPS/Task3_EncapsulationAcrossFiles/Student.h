#ifndef STUDENT_H
#define STUDENT_h
#include<string>


class Student{
    private:
        int rollNo;
        std::string name;
        int marks;
    public:
        // declaration of getter and setter functions to be implemented in the Student.cpp file
        void setRollNo(int RollNo);
        void setName(std::string Name);
        void setMarks(int Marks);

        int getRollNo();
        std::string getName();
        int getMarks();
};

#endif