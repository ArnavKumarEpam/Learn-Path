#include<iostream>

class Person{
    protected:
        std::string name;
        int age;
    public:
        std::string getName(){
            return name;
        }
        int getAge(){
            return age;
        }
        void setName(std::string Name){
            name = Name;
        }
        void setAge(int Age){
            age = Age;
        }


};

class Student : public Person{
    private:
        int rollNo;
        char grade;

    public:
        Student(std::string Name, int Age){
            setName(Name);
            setAge(Age);
        
        }
        void setRollNo(int RollNo){
            rollNo = RollNo;
        }
        void setGrade(char Grade){
            grade = Grade;
        }
        int getRollNo(){return rollNo;}
        char getGrade(){return grade;}
        
        void display(){
           std::cout<<"Student having name: " << getName() <<", rollNo: "<<rollNo
           <<", Grade: "<<grade<<" and age: "<<getAge()<<std::endl;
        }
};

class Teacher : public Person{
    private:
        std::string subject;
        double salary;
    public:
        Teacher(std::string Name, int Age){
            setName(Name);
            setAge(Age);
            
        }
        void setSubject(std::string Subject){
            subject = Subject;
        }
        void setSalary(double Salary){
            salary = Salary;
        }
        std::string getSubject(){return subject;}
        double getSalary(){return salary;}
        
        void display(){
           std::cout<<"Teacher having name: " << getName()<< ", Subject: "<<subject<<", salary: "<<salary<<" and age: "<<
           getAge()<<std::endl;
        }
};

int main(){
    Person P;
    
    std::cout<<"Record of Student: "<<std::endl;
    Student student("ABC", 21);
    student.setRollNo(101);
    student.setGrade('A');
    student.display();


    std::cout<<"Records of Teacher: "<<std::endl;
    Teacher teacher("DEF", 30);
    teacher.setSubject("Maths");
    teacher.setSalary(50000);
    teacher.display();

    return 0;

}