#include <stdio.h>
#include<stdlib.h>

int main() {
    
    int *pTheme = (int*)(malloc(sizeof(int)));
    if(pTheme == NULL){ // check if memory got allocated or not
        printf("Memory Allocation got failed! ");
        return 1;
    }
    *pTheme = 0; // initialized to 0 after allocation
    printf("Enter your desired Theme colour code: ");
    scanf("%d", pTheme); // take input from the user
    
    printf("Theme code entered by you: %d", * pTheme);
    
    free(pTheme); // free the pointer
    pTheme = NULL; // point the pointer to null to prevent dangling pointer
    return 0;
    

}