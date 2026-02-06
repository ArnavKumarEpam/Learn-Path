#include<stdio.h>
#include<stdlib.h>

char *StringCopy(const char *source){
    if(source == NULL) return NULL;
    int length = 0; // to calculate the length of the source string

    while(source[length] != '\0'){
        length++; // calculating the length 
    }

    char *copy = (char *)(malloc((length + 1) * sizeof(char))); // allocate memory for copy
    if(copy == NULL){ // check if memory allocation was successful
        printf("Memory allocation failed!\n");
        return NULL;
    }
    for(int i = 0; i <= length; i++){
        copy[i] = source[i]; // copying each character 
    }
    if(copy[length] != '\0'){ // ensuring null terminator is present
        copy[length] = '\0';
    }
    return copy;
}

int main(){
    const char *source = "Hello, World!"; // original string 1
    const char *secondSource = "Pointers in C"; // original string 2

    const char *copy1 = StringCopy(source); // copy string 1
    const char *copy2 = StringCopy(secondSource); // copy string 2

    if(copy1 && copy2){ // both the copies were successful
        printf("Original String 1: %s | Copy String 1: %s" , source, copy1);
        printf("\n Original String 2; %s | Copy String 2: %s", secondSource, copy2);
        free(copy1); // freed the allocated memory of copy 1
        free(copy2); // freed the allocated memory of copy 2
    }
    else if(copy1){ // only copy1 was successful
        printf("Original String 1: %s | Copy String 1: %s" , source, copy1);
        free(copy1); // freed the allocated memory of copy 1
    }
    else if(copy2){ // only copy2 was successful
        printf(" Original String 2; %s | Copy String 2: %s", secondSource, copy2);
        free(copy2); // freed the allocated memory of copy 2
    }
    else{ // both copies failed
        printf("String copy failed for both strings!\n");
    }
    
    return 0;
}