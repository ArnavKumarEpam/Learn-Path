#include<iostream>
#include<cstdio>
using namespace std;

struct Employee{
    int empId;
    char name[50];
    float salary;
};

int main(){

    FILE *employee = fopen("employee.data", "rb");

    if(employee == NULL){
        printf("File not found!\n");
        return 1;
    }   
    FILE *temp = fopen("temp.data", "wb");
    if(temp == NULL){
        printf("File not found!\n");
        return 1;
    }   
    int empId;
    printf("Enter Employee ID: ");
    scanf("%d", &empId);
    struct Employee emp;
    int found = 0;
    while(fread(&emp, sizeof(struct Employee), 1, employee) == 1){
        if(emp.empId == empId){
            found = 1;
            continue; // skip writing this record to temp file
        }
        if(fwrite(&emp, sizeof(struct Employee), 1, temp) != 1){
            printf("Error writing to temporary file!\n");
            fclose(employee);
            fclose(temp);
            return 1;
        }
    }
    if(!found){
        printf("That %d record was not in the file. \n", empId);
    }
    else printf("That %d record was found in the file and skipped/deleted. \n", empId);
    
    fclose(employee);
    fclose(temp);
    remove("employee.dat");
    employee = NULL;

    if(rename("temp.data", "employee.data") != 0){
        cout<<"Rename couldn't happend"<<endl;
        return 1;
    }
    else cout<<"Rename Successfull!"<<endl;
    printf("Employee record deleted successfully.\n");
    return 0;

}