#include<iostream>
using namespace std;

int main(){

    cout<<"Welcome to the Calculator! "<<endl;
    cout<<"For Addition enter [1]";
    cout<<"\nFor Subtraction enter [2]";
    cout<<"\nFor Multiplication enter [3]";
    cout<<"\nFor Division enter [4]"<<endl;


    int choice;
    cout<<"Enter your choice: ";
    cin>>choice;
    cout<<"Enter the first number: ";
    double num1, num2;
    cin>>num1;
    cout<<"Enter the second number: ";
    cin>>num2;
    double result; // output can be in decimals
    /*Test Case 1
    Addition
    Input:
    choice: 1
    num1: 10
    num2: 5
    Output:
    Result: 15
    */

    /*Test Case 2
    Subtraction
    Input:
    choice: 2
    num1: 10
    num2: 5
    Output:
    Result: 5
    */

    /*Test Case 3
    Multiplication
    Input:
    choice: 3
    num1: 10
    num2: 5
    Output:
    Result: 50
    */

    /*Test Case 4
    division
    Input:
    choice: 4
    num1: 10
    num2: 5
    Output:
    Result: 2
    */

    switch(choice){
        case 1: // Addition
            result = num1 + num2;
            cout<<"Result: "<<result<<endl;
            break;

        case 2: // Subtraction
            result = num1 - num2;
            cout<<"Result: "<<result<<endl;
            break;

        case 3: // Multiplication
            result = num1 * num2;
            cout<<"Result: "<<result<<endl;
            break;

        case 4: // Division
            if(num2 == 0){
                cout<<"Error: Division by zero is not allowed."<<endl;
            }

            else {
                result = num1 / num2;
                cout<<"Result: "<<result<<endl;
            }
            break;

        default: // Invalid choice
            cout<<"Invalid choice! Please select a valid operation."<<endl;
            break;
    }
}