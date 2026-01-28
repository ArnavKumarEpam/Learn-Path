#include<stdio.h>

struct Student{
    int rollNo;
    char name[50];
    float marks;
};

void addStudentRecord(); // function to add student record
void displayAllRecords(); // function to display all student records


int main(){
    printf("Welcome to Student Record Management System!\n");
    int choice;
    
    do{
        printf("1. Add Student Record\n");
        printf("2. Display All Records\n");
        printf("3. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        
        switch(choice){
            case 1:
                addStudentRecord();
                break;
            case 2:
                displayAllRecords();
                break;
            case 3:
                printf("Exiting the system. Goodbye!\n");
                break;
            default:
                printf("Invalid choice! Please try again.\n");
        }
    }
    while(choice != 3);
    return 0;
}

int isDuplicat(int rollNo){ // function to check duplicate roll number
    struct Student student;
    FILE *fp;
    fp = fopen("students.dat", "rb");
    if(fp == NULL){
        printf("Error opening file!\n");
        return 0;
    }

    while(fread(&student, sizeof(struct Student), 1, fp)){
        if(student.rollNo == rollNo){ // exact roll number already exists
            printf("Roll Number already exists! Please use a unique Roll Number.\n");
            fclose(fp);
            return 1;
        }
    }
    return 0;
}


void addStudentRecord(){
    struct Student student; // student record
    FILE *fp; // file pointer
    printf("Enter Roll Number: ");
    scanf("%d", &student.rollNo);
    if( scanf("%d", &student.rollNo) != 1 || student.rollNo <= 0){ // validation check for roll number
        printf("Invalid Roll Number!\n");
        while(getchar() != '\n'); // clear input buffer
        return;
    }
    
    printf("Enter Name: ");
    scanf("%s", student.name);
    printf("Enter Marks: ");
    if(scanf("%f", &student.marks) != 1){ // input validation for marks
        printf("Invalid input for marks! Please enter a numeric value.\n");
        return;
    }
    
    else if(student.marks < 0 || student.marks > 100){ // validation check for marks
        printf("Invalid Marks! It must be between 0 and 100.\n");
        return;
    }

    


    fp = fopen("students.dat", "ab");

    if(fp == NULL){
        printf("Error opening file!\n");
        return;
    }
    if(isDuplicat(student.rollNo)){ // validation check for duplicate roll number
        printf("Duplicate Roll Number found. Record not added.\n");
        return;
    }
    fwrite(&student, sizeof(struct Student), 1, fp); // writing student record to file
    fclose(fp); // closing file
    printf("Student record added successfully!\n");

}

void displayAllRecords(){
    struct Student student; // student record
    FILE *fp; // file pointer
    fp = fopen("students.dat", "rb"); // opening file in read mode
    int found = 0;
    if (fp == NULL){ // file not found
        printf("Error opening file or no records found!\n");
        return;
    }
    printf("Student Records:\n");
    printf("Roll No\tName\tMarks\n");
    while(fread(&student, sizeof(struct Student), 1, fp)){ // reading the student records from the file
        printf("%-8d %-20s %-6.2f\n", student.rollNo, student.name, student.marks);
        found = 1;
    }
    if(!found){
        printf("No records found!\n");
    }
    fclose(fp); // closing file

    
}
