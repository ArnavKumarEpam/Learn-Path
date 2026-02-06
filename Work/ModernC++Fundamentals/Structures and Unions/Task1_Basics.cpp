#include<stdio.h>
#include<string.h>

struct Employee{ // user defined data type to store the data of the Employees
    char name[50];
    int employee_id;
    float salary;

};

void printEmployeeDetails(struct Employee emp){ // Function to print the details of the Employee
    printf("Printing the details of the Employee! \n");
    printf("\n");
    printf("Name of the Employee : %s \n", emp.name);
    printf("Employee id of the Employee: %d \n", emp.employee_id);
    printf("Salary of the Employee: %.2f \n", emp.salary);
}

int main(){
    struct Employee singleEmployee; // single Employee
    strcpy(singleEmployee.name, "Arnav Kumar"); // using strcpy function to put the name in the structure
    singleEmployee.employee_id = 101;
    singleEmployee.salary = 75000.50;

    printf("Printing the details of the single Employee: \n");
    printf("\n");
    printEmployeeDetails(singleEmployee);

    struct Employee staff[4]; // Array of Employee data type

    // putting the values in the array of Employee
    strcpy(staff[0].name, "ABC"); 
    staff[0].employee_id = 102;
    staff[0].salary = 60000.00;

    strcpy(staff[1].name, "DEF");
    staff[1].employee_id = 103;
    staff[1].salary = 62000.00;

    strcpy(staff[2].name, "GHI");
    staff[2].employee_id = 104;
    staff[2].salary = 65000.00;

    strcpy(staff[3].name, "JKL");
    staff[3].employee_id = 105;
    staff[3].salary = 50000.00;

   
 
    printf("Printing the details of the list of Employees! \n");
    printf("\n");
    for(int i = 0 ; i < 4; i ++){
        printEmployeeDetails(staff[i]); // printing the details of the list of employees
        printf("\n");
    }
  return 0;


}