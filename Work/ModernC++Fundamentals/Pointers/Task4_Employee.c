#include<stdio.h>
#include<stdlib.h>
struct Employee{
    int empId;
    char name[50];
    float salary;
};

void displayEmployee(struct Employee *emp){
    printf("\n--- Employee Details ---\n");
    printf("Employee ID: %d\n", emp->empId);
    printf("Name: %s\n", emp->name);
    printf("Salary: %.2f\n", emp->salary);
}
int main(){

    struct Employee *ptr;
    int numEmployees;
    printf("Enter the number of Employee records you want to create: ");
    scanf("%d", &numEmployees);
    ptr = (struct Employee*)(malloc(numEmployees * sizeof(struct Employee)));
    if(ptr == NULL){
        printf("Memory allocation failed!\n");
        return 1;
    }
    for(int i = 0 ; i < numEmployees; i++){
        printf("\n--- Enter details for Employee %d ---\n", i + 1);
        printf("Employee ID: ");
        scanf("%d", &ptr[i].empId);
        printf("Name: ");
        scanf(" %[^\n]", ptr[i].name); // to read string with spaces
        printf("Salary: ");
        scanf("%f", &ptr[i].salary);
        if(ptr[i].salary < 0){
            printf("Invalid salary! Enter a valid salary.\n");
            i--; // retry current index
        }
    }
    printf("\n=== Employee Records Before Updating Salary ===\n");
    for(int i = 0 ; i < numEmployees ; i++){
        displayEmployee(&ptr[i]);
    }
    printf("Enter the Employee ID whose salary you want to update: ");
    int searchId;
    scanf("%d", &searchId);
    float newSalary;
    printf("Enter the new Salary: ");
    scanf("%f", &newSalary);
    int found = 0;
    for(int i = 0 ; i < numEmployees ; i++){
        if(ptr[i].empId == searchId){
            ptr[i].salary = newSalary;
            printf("Salary updated successfully.\n");
            found = 1;
        }
    }
    if (!found) {
    printf("Employee ID not found.\n");
    } 
    printf("\n=== Employee Records After Updating Salary ===\n");
    for(int i = 0 ; i < numEmployees ; i++){
        displayEmployee(&ptr[i]);
    }
    free(ptr);
    ptr = NULL;
    return 0;

    
}