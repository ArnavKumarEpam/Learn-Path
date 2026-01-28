#include <stdio.h>

// check if student id is valid
int validateStudentID(int id) {
    if (id >= 101 && id <= 999)
        return 1;
    return 0;
}

// check if grade is valid
int validateGrade(int grade) {
    if (grade >= 0 && grade <= 100)
        return 1;
    return 0;
}

// show feedback based on average
void showFeedback(float avg) {
    if (avg >= 90)
        printf("Excellent!\n");
    else if (avg >= 70)
        printf("Good job!\n");
    else if (avg >= 50)
        printf("Needs improvement.\n");
    else
        printf("At risk.\n");
}

int main() {
    int studentID, numAssignments;
    char choice;

    printf("Student Grade Analyzer\n");

    do {
        int total = 0, count = 0;

        // student id input
        while (1) {
            printf("\nEnter Student ID (101-999): ");
            if (scanf("%d", &studentID) != 1) {
                while (getchar() != '\n');
                printf("Invalid input.\n");
                continue;
            }

            if (!validateStudentID(studentID)) {
                printf("Student ID must be between 101 and 999.\n");
                continue;
            }
            break;
        }

        // number of assignments
        printf("Enter number of assignments: ");
        if (scanf("%d", &numAssignments) != 1 || numAssignments < 0) {
            while (getchar() != '\n');
            numAssignments = 0;
        }

        // grades input
        for (int i = 1; i <= numAssignments; i++) {
            int grade;
            printf("Grade for assignment %d: ", i);

            if (scanf("%d", &grade) != 1) {
                while (getchar() != '\n');
                printf("Invalid grade, skipped.\n");
                continue;
            }

            if (!validateGrade(grade)) {
                printf("Grade must be 0-100. Skipped.\n");
                continue;
            }

            total += grade;
            count++;
        }

        // results
        if (count == 0) {
            printf("\nNo valid grades entered.\n");
        } else {
            float avg = (float) total / count;
            printf("\nAverage grade: %.2f%%\n", avg);
            showFeedback(avg);
        }

        // continue?
        printf("\nProcess another student? (Y/N): ");
        while (getchar() != '\n');
        choice = getchar();

    } while (choice == 'Y' || choice == 'y');

    printf("\nProgram ended.\n");
    return 0;
}
