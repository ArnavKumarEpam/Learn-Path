#include<stdio.h>

struct Employee{
    int empId;
    char name[50];
    float basicSalary;
};

void processEmployeeRecords(){
    // Function to process employee data
    struct Employee employee;
    FILE *ptr = fopen("employee.dat", "rb");
    if(ptr == NULL){
        printf("Error! employee.dat not found or cannot be opened.\n");
        return;
    }
    int found = 0;
    while(fread(&employee, sizeof(struct Employee), 1, ptr)){
        printf("Employee ID: %d\n", employee.empId);
        printf("Employee Name: %s\n", employee.name);
        printf("Basic Salary: %.2f\n", employee.basicSalary);
        printf("--------------------------\n");
        float DA  = employee.basicSalary * 0.50;
        float HRA = employee.basicSalary * 0.20;

        float netSalary = employee.basicSalary + DA + HRA;
        char fileName[20];  
        sprintf(fileName, "emp%d_slip.txt", employee.empId);
        FILE *slipPtr = fopen(fileName, "w");
        if(slipPtr == NULL){
            printf("Error creating salary slip file for Employee ID: %d\n", employee.empId);
            continue;
        }
        fprintf(slipPtr, "Salary Slip for Employee %s (ID: %d)\n", employee.name, employee.empId);  
        fprintf(slipPtr, "-----------------------------------------\n");  
        fprintf(slipPtr, "%-25s : %.2f\n", "Basic Salary", employee.basicSalary);
        fprintf(slipPtr, "%-25s : %.2f\n", "Dearness Allowance", DA);
        fprintf(slipPtr, "%-25s : %.2f\n", "House Rent Allowance", HRA);
        fprintf(slipPtr, "%-25s : %.2f\n", "Net Salary", netSalary);
        fprintf(slipPtr, "-----------------------------------------\n");  
        fclose(slipPtr);
        found = 1;

    }
    if(!found){
        printf("No employee records found!\n");
    }
    fclose(ptr);
    

}
int isDuplicate(int empId){
    struct Employee employee;
    FILE *fp = fopen("employee.dat", "rb");
    if(fp == NULL){
        return 0;
    }
    while(fread(&employee, sizeof(struct Employee), 1, fp)){
        if(employee.empId == empId){
            printf("Employee ID already exists! Please use a unique Employee ID.\n");
            fclose(fp);
            return 1;
        }
    }
    fclose(fp);
    return 0;
}
int main(){
    struct Employee employee;
    

    printf("Enter Employee ID: "); 
    scanf("%d", &employee.empId);
    if(employee.empId <= 0){
        printf("Invalid Employee ID! ID must be positive.\n");
        
        return 0;
    }
    if(isDuplicate(employee.empId)){
        return 0;
    }
    printf("Enter Employee Name: ");
    scanf("%49s", employee.name);
    printf("Enter Basic Salary: ");
    if(scanf("%f", &employee.basicSalary) != 1 || employee.basicSalary < 0){
        printf("Invalid Salary! \n");
        
        return 0;
    }
    
    FILE *fptr;
    fptr = fopen("employee.dat", "ab");
    if(fptr == NULL){
        printf("Error! employee.dat not found or cannot be opened.\n");
        return 0;
    }
    else{
        
        fwrite(&employee, sizeof(struct Employee), 1, fptr);
        fclose(fptr);
        processEmployeeRecords();
    }
    return 0;
}
