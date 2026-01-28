#include<stdio.h>
#include<stdlib.h>

struct Student{
    int rollno;
    char name[50];
    float marks;
};

int main(){
    struct Student *student;
    printf("Enter the roll number of the student. \n");
    int rollno;
    scanf("%d", &rollno);
    if(rollno <= 0){ // validate roll number
        printf("Invalid roll number! \n");
        return 1;
    }
    printf("Enter the name of the student. \n");
    char name[50];
    scanf(" %[^\n]", name);
    printf("Enter the marks of the student. \n");
    float marks;
    if(scanf("%f", &marks) != 1 || marks < 0 || marks > 100){ // check whether marks are valid or not
        printf("Invalid input for marks! \n");
        return 1;
    }
    
    student = (struct Student *)(malloc(sizeof(struct Student)));
    if(student == NULL){ // check memory allocation
        printf("Memory allocation failed! \n");
        return 1;
    }
    FILE *file = fopen("student.dat", "r+b");
    if(file == NULL){ // file opened or not
        printf("File not found. \n");
        return 1;
    }
    int recordIndex = 1;
    int found = 0;
    fseek(file, 0, SEEK_END); // go to end of the file
    if(ftell(file) == 0){ // if file is empty
        printf("No records found in the file. \n");
        fclose(file);
        return 1;
    }
    rewind(file); // go to the beginning of the file
    while(fread(student, sizeof(struct Student), 1, file)){
        if(student -> rollno == rollno){
            printf("\n--- Student Details ---\n");
            printf("Roll Number: %d\n", student->rollno);
            printf("Name: %s\n", student->name);
            printf("Marks: %.2f\n", student->marks);
            // Update marks
            // int position = (recordIndex - 1) * sizeof(struct Student);
            student->marks = marks;
            if(marks < 0 || marks > 100){
                printf("Invalid marks! Marks should be between 0 and 100. \n");
                fclose(file);
                free(student);
                return 1;
            }
            long position  = ftell(file) - sizeof(struct Student); // calculate position of the record
            fseek(file, position, SEEK_SET); // move file pointer to the record position
            if(fwrite(student, sizeof( struct Student), 1, file) != 1){ // write updated record back to file
                printf("Error updating the record. \n");
                fclose(file);
                free(student);
                return 1;
            }
            
            printf("Marks updated successfully.\n");
            found = 1;
            break;
        }
        recordIndex++;
    }
    if(found == 1){
        printf("Record updated successfully.\n");
        printf("\n--- Updated Student Details ---\n");
        printf("Roll Number: %d\n", student->rollno);   
        printf("Name: %s\n", student->name);
        printf("Marks: %.2f\n", student->marks);
    }
    else if(!found){
        printf("Student with Roll Number %d not found. \n", rollno);
    }
    fclose(file);
    

}