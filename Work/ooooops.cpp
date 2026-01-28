// #include<iostream>
// using namespace std;

// class Oops{
//     private:
//         int data;
//         string name = "OopsClass";
//     public:
//         void setData(int data){
//             this -> data = data;
//         }
//         string getName(){
//             return name;
//         }
//         int getData(){
//             return data;
//         }
//         void show(){
//             cout<<"Base Class Show Function"<<endl;
//         }
// };
// class SubOops : public Oops{
//     public:
//         void show(){ 
//             cout<<Oops::getName()<<endl;
//             // cout<<"Private Data from base class "<<Oops::getData()<<endl;
//         }


// };

// int main(){
//     // SubOops child;
//     // Oops parent;
//     // parent.setData(100);
//     // child.show();
//     SubOops sb;
//     Oops oops;
//     oops.show();
//     sb.show();
// }

#include<iostream>
using namespace std;

class Student{
    private:
        string name;
        int rollNo;
        char grade;
    public:
        Student(string Name, int x, char y) : name(Name), rollNo(x), grade(y){}
        void setName(string name){
            this -> name = name;
        }
        void setRollNo(int rollNo){
            this -> rollNo = rollNo;
        }
        void setGrade(char grade){
            this -> grade = grade;
        }

        string getName(){return name;}
        int getRollNo(){return rollNo;}
        char getGrade(){return grade;}

        void setValues(int, char);

};
    


void Student :: setValues(int a, char b){
    rollNo = a;
    grade = b;
}


int main(){
    Student std("ABC", 1, 'A');
    // Student student;
    // cout<<"Enter the name: "<<endl;
    // string name;
    // getline(cin, name);
    // student.setName(name);
    // cout<<"Enter the rollNo: "<<endl;
    // int rollNo;
    // cin>> rollNo;
    // student.setRollNo(rollNo);
    // cout<<"Enter the grade: "<<endl;
    // char grade;
    // cin>>grade;
    // student.setGrade(grade);

    // cout<<"The Records of the student are: "<<endl;
    // cout<<student.getName()<<endl;
    // cout<<student.getRollNo()<<endl;
    // cout<<student.getGrade()<<endl;
    // student.setValues(10, 'A');
    //  cout<<student.getRollNo()<<endl;
    // cout<<student.getGrade()<<endl;
    cout<<std.getName()<<endl;
    cout<<std.getRollNo()<<endl;
    cout<<std.getGrade()<<endl;
}