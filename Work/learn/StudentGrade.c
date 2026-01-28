#include<stdio.h>

int totalStudents = 0; // global variable to keep track of total students analyzed
int main(){
    printf("Welcome to Student Grade Analyzer!\n");
    char choice; // variable to store user choice
    static int sessionCount = 0; // static variable to count sessions
    do{ // Do while loop to repeat the process based on user choice
        sessionCount++;
        totalStudents++;

        int studentId = 0;
        while(1){
            printf("Enter the student id: ");
            scanf("%d", &studentId);
            if(studentId >= 101 && studentId <= 999){
                break;
            }
            else{
                printf("Invalid student id! ");
            }
        }
        int numAssignments;
        printf("Enter the assignments student has: ");
        scanf("%d", &numAssignments);

        int totalGrade = 0; // to store total grade
        int validCount = 0; // to count valid grades entered

        for(int i = 0 ; i < numAssignments ; i++){ // for loop to input grades
            int grade;
            printf("Enter the grade of Assignment #%d: ", i + 1);
            scanf("%d", &grade);

            if(grade < 0 || grade > 100){ // validate grade
                printf("Invalid grade! Must be between 0 and 100. Skipping this assignment.\n");
                continue;
            }
            totalGrade += grade; // adding valid grades to totalGrade
            validCount++; // incrementing count of valid grades

        }
        if(validCount == 0){ // no valid grades entered
            printf("No valid grades entered! \n");
        }
        else{
            float average = (float) totalGrade / validCount; // calculating average grade
            printf("The average grade of the student is: %.2f \n", average);

            // performance analsysis based on average
            if(average >= 90){ 
                printf("Performance: Excellent! \n");
            }
            else if(average >= 70){
                printf("Performance: Good! \n");
            }
            else if(average >= 50){
                printf("Performance: Needs Improvement! \n");
            }
        
            else{
                printf("At Risk! \n");
            }
        }

        printf("Do you want to analyze another student? (Y/N): "); // asking user to stop or keep going
        scanf(" %c", &choice);
        if(choice == 'N' || choice == 'n'){ // exit the loop
            break;
        }
    }
    while(choice == 'Y' || choice == 'y');
    printf("Total students analyzed in this session: %d \n", totalStudents); // total students analyzed
    printf("Total sessions in this run: %d \n", sessionCount); // total sessions
    printf("\n Exiting Student Grade Analyzer. Goodbye! \n");  // end message
    return 0;
}