#include <stdio.h>
#include <limits.h>
#include <stdlib.h>

void inputScore(int* , int); // function to take input from the user
double calculateAverage(const int* , int ); // function to calculate the average of game score
int findHighest(const int* , int ); // function to find the highest score

int main() {
    int n; 
    printf("Enter the total number of innings played (must be positive): ");
    scanf("%d", &n);
    while (n <= 0) { // Makes sure user enter valid number of games
        printf("Number of games must be positive. Please re-enter.\n");
        scanf("%d" , &n);
    }

    int * innigsScores = malloc(n * sizeof(int)); // dynamic allocation
    if (innigsScores == NULL) { // validation check whether memory got allocated or not
        printf("Bad Allocation \n");
        return 1;
    }
    inputScore(innigsScores , n); // taking input
    printf("Average of scores %.2f \n" , calculateAverage(innigsScores , n)); // displaying average score
    printf("Highest Score : %d" , findHighest(innigsScores,n)); // displaying highest score
    free(innigsScores); // freeing the memory
    innigsScores = NULL; // make sure we prevent dangling pointer
}

void inputScore( int* scoresPtr , int size) {
    printf("Enter the scores of each game in the range 0 - 100 ! \n");
    for (int i = 0 ; i < size ; i++) {
        int score = - 1;
        printf("Enter the score for Game #[%d] ", i + 1);
        while(score < 0 || score > 100){ // while loop to enter a valid score
            if(score != -1) printf("Invalid score. Must be between 0 and 100. Please re-enter.\n");
            scanf("%d", &score);
            
        }
        // implementation using do - while loop as well
        // do{
        //     scanf("%d", &score);
        // }
        // while(score < 0 || score > 100);
        scoresPtr[i] = score;
    }
}

double calculateAverage(const int* scoresPtr, int size) {
    if (scoresPtr == NULL) {
        printf("Invalid array");
        return -1;
    }
    int sum = 0;
    for (int i = 0; i < size; ++i) {
        sum += scoresPtr[i];
    }
    double avg = (double)(sum)/size;
    return avg;
}

int findHighest(const int* scoresPtr, int size) {
    if (scoresPtr == NULL) {
        printf("Invalid array");
        return -1;
    }
    int max = INT_MIN;
    for (int i = 0 ; i < size ; i++) {
        if (scoresPtr[i] > max) max = scoresPtr[i];
    }
    return max;
}