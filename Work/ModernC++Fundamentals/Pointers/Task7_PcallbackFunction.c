#include<stdio.h>
#include<stdlib.h>

int add(int a, int b){ // function to add two numbers
    return a + b;
}

int subtract(int a, int b){ // function to subtract two numbers
    return a - b;
}

int multiply(int a, int b){ // function to multiply two numbers
    return a * b;
}

int divide(int a, int b){ // function to divide two numbers
    if(b == 0){ // check for error of divide by 0
        printf("Division by 0 not allowed! \n");
        return 0;
    }
    return a / b; // if valid

}
int calculate(int a, int b, int(*operation)(int, int)){ 
    return operation(a, b); // calling operation function with function pointer
}

int main(){
    int a = 10, b = 2;

    int addition = calculate(a, b, add); 
    printf("Addition of A and B: %d \n", addition);

    int subtraction = calculate(a, b, subtract);
    printf("Subtraction of A and B: %d \n", subtraction);

    int multiplication = calculate(a, b, multiply);
    printf("Multiplication of A and B: %d \n", multiplication);

    int division = calculate(a, b, divide);
    printf("Division of A by B: %d \n", division);

    int division2 = calculate(a, 0, divide);
    printf("Division of A by B: %d \n", division2);

    return 0;
}