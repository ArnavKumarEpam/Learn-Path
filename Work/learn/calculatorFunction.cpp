#include<iostream>
using namespace std;

float add(float num1, float num2){ // addition function
    return num1 + num2;
}

float subtract(float num1, float num2){ // subtraction function
    return num1 - num2;
}
float multiply(float num1, float num2){ // multiplication function
    return num1 * num2;
}
float divide(float num1, float num2){ // division function
    if(num2 == 0){
        cout<<"Error: Division by zero!"<<endl;
        return 0; // return 0 or handle error as needed
    }
    return num1 / num2;
}

int main(){
    cout<<"Welcome to Calculator! "<<endl;
    bool continueCalc = true;
    int choice;
    while(continueCalc){
        cout<<"For Addition enter [1]";
        cout<<"\nFor Subtraction enter [2]";
        cout<<"\nFor Multiplication enter [3]";
        cout<<"\nFor Division enter [4]";
        cout<<"\nTo Exit enter [5]"<<endl;

        cout<<"Enter your choice: ";
        cin>>choice;


        cout<<"Enter the first number: ";
        double num1, num2;
        cin>>num1;
        if(cin.fail()){
            cout<<"Invalid input! Please enter numeric values."<<endl;
            cin.clear(); // clear error flag
            continue;
        }
        cout<<"Enter the second number: ";
        cin>>num2;
        if(cin.fail()){
            cout<<"Invalid input! Please enter numeric values."<<endl;
            cin.clear(); // clear error flag
            continue;
        }
        double result; // output can be in decimals

        switch(choice){
            case 1:
                result = add(num1, num2); // addition
                cout<<"The Result of Addition is: "<<result<<endl;
                break;
            case 2:
                result = subtract(num1, num2); // subtraction
                cout<<"The Result of Subtraction is: "<<result<<endl;
                break;
            case 3:
                result = multiply(num1, num2); // multiplication
                cout<<"The Result of Multiplication is: "<<result<<endl;
                break;
            case 4:
                result = divide(num1, num2); // division
                cout<<"The Result of Division is: "<<result<<endl;
                break;
            case 5:
                continueCalc = false;
                cout<<"Exiting Calculator. Goodbye!"<<endl;
                break;
            default:
                cout<<"Invalid choice! Please try again."<<endl;
        }
    }


}