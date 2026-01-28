#include<stdio.h>

void attendanceRecord(int empId, char timespamp[]){ // function to add attendance in the file
    FILE *file = fopen("attendance.txt", "a");
    if(file == NULL){
        printf("Error opening file!\n");
        return;
    }
    fprintf(file, "Employee ID: %d, Timestamp: %s", empId, timespamp);
    printf("Attendance recorded successfully.\n");
    fclose(file);
}
void displayAttendanceLog(){ // function to display attendance log from the file
    FILE *file = fopen("attendance.txt", "r");
    if(file == NULL){
        printf("No attendance records found.\n");
        return;
    }
    char line[100];
    while(fgets(line, sizeof(line), file) != NULL){
        printf("%s", line);
    }
}

int main(){
    printf("Enter Employee ID: ");
    int empId;
    scanf("%d", &empId); // input of employee ID
    getchar(); // clear buffer
    printf("Enter Timestamp (e.g., 2025-09-20 09:30 AM): ");
    char timespamp[20];
    fgets(timespamp, sizeof(timespamp), stdin); // input of the timestamp
    timespamp[strcspn(timespamp, "\n")] = '\0'; // remove newline character
    attendanceRecord(empId, timespamp);
    // printf("Attendance recorded successfully.\n");
    printf("Attendance Log\n");
    displayAttendanceLog();
    return 0;
}