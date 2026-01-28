#include <stdio.h>

int main() {
    /* Variable declarations for 3 students */
    char name1[20], name2[20], name3[20];
    int age1, age2, age3;
    float gpa1, gpa2, gpa3;

    /* Input for Student 1 */
    printf("Enter name of student 1: ");
    scanf("%19s", name1);
    printf("Enter age of student 1: ");
    scanf("%d", &age1);
    printf("Enter GPA of student 1: ");
    scanf("%f", &gpa1);

    /* Input for Student 2 */
    printf("\nEnter name of student 2: ");
    scanf("%19s", name2);
    printf("Enter age of student 2: ");
    scanf("%d", &age2);
    printf("Enter GPA of student 2: ");
    scanf("%f", &gpa2);

    /* Input for Student 3 */
    printf("\nEnter name of student 3: ");
    scanf("%19s", name3);
    printf("Enter age of student 3: ");
    scanf("%d", &age3);
    printf("Enter GPA of student 3: ");
    scanf("%f", &gpa3);

    /* 
    Basic representation of the table 
    Test Case 1:
    Input:
    Alice 20 3.75
    Bob 19 3.60
    Charlie 21 3.90
    
    Output:
    |---------------|-----|-------|
    |     Name      | Age |  GPA  |
    |---------------|-----|-------|
    | Alice         |  20 |  3.75 |
    | Bob           |  19 |  3.60 |
    | Charlie       |  21 |  3.90 |
    |---------------|-----|-------|
    */
  
    /* Display table */
    printf("\n");
    printf("|---------------|-----|-------|\n");
    printf("|     Name      | Age |  GPA  |\n");
    printf("|---------------|-----|-------|\n");

    printf("| %-13s | %3d | %5.2f |\n", name1, age1, gpa1);
    printf("| %-13s | %3d | %5.2f |\n", name2, age2, gpa2);
    printf("| %-13s | %3d | %5.2f |\n", name3, age3, gpa3);

    printf("|---------------|-----|-------|\n");

    return 0;
}
