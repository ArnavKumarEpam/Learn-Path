#include<iostream>

class Student{
    private:
        std::string name;
        int marks;
    public:
        Student(std::string name, int marks) : name(name), marks(marks){}
        friend class Result;
};

class Result{
    public:
        void display(const Student & student){
            std::cout<<"Student Name: "<<student.name <<" and Student Marks: "<<student.marks;
        }
};
int main(){
    Result result;
    Student student("Arnav", 100);
    result.display(student);
}