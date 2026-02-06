#include<stdio.h>

int add(int a, int b){ // function to calculate the addition of two numbers
    return a + b;
}

int subtract(int a, int b){ // function to calculate the subtraction of two numbers
    return a - b;
}

int multiply(int a, int b){ // function to calculate the product of two numbers
    return a * b;
}

int main(){
    int a = 10, b = 20; 
    /*int here represents the return type of the function ,
     it points to a function having two int parameters,
    *functionPointer is a pointer = add means it points to add function*/
    int (*functionPointer) (int, int) = add;
    printf("Addition of two numbers is: %d \n", functionPointer(a, b));

    functionPointer = subtract;
    printf("Subtraction of two numbers is: %d \n", functionPointer(a, b));

    functionPointer = multiply;
    printf("Multiplication of two numbers is: %d", functionPointer(a, b));

    return 0;


}