#include<iostream>
#include<limits>
using namespace std;

static double balance = 0.0; // bank balance initialized to zero

void deposit(double amount){ // deposit function

    if(amount <= 0){ // validate positive amount
        cout<<"Deposit amount must be positive!"<<endl;
        return;
    }

    else {
        balance += amount;
        cout<<"Successfully deposited Rs. "<<amount<<". New balance: Rs. "<<balance<<endl;
    }
}

void withdraw(double amount){ // withdraw function
    
    if(amount <= 0){ // validate positive amount
        cout<<"Withdrawal amount must be positive!"<<endl;
        return;
    }
    else if(amount > balance){
        cout<<"Insufficient balance! Current balance: Rs. "<<balance<<endl;
    }
    else{
        balance -= amount;
        cout<<"Successfully withdrew Rs. "<<amount<<". New balance: Rs. "<<balance<<endl;
    }
}

float checkBalance(){ // display balance function
    return balance;
}

int main(){
    cout<<"Welcome to Banking System!"<<endl;
    
    int choice;
    bool continueMenu = true;
    
    while(continueMenu){ // loop until user chooses to exit
        cout<<"\n--- Banking Menu ---"<<endl;
        cout<<"For Deposit enter [1]"<<endl; // deposit option
        cout<<"For Withdrawal enter [2]"<<endl; // withdraw option
        cout<<"For Balance Enquiry enter [3]"<<endl; // check balance option
        cout<<"To Exit enter [4]"<<endl; // exit option
        cout<<"Enter your choice: "; // user's choice
        cin>>choice;
        if(cin.fail()) { // input validation
            cin.clear(); // clear error flag
            cin.ignore(numeric_limits<streamsize>::max(), '\n'); // discard invalid input
            cout << "Invalid input! Please enter a number between 1 and 4." << endl;
            continue;
        }
        switch(choice){
            case 1: { // deposit case
                double amount;
                cout<<"Enter amount to deposit: Rs. ";
                cin>>amount;
                deposit(amount);
                break;
            }
            case 2: { // withdraw case
                double amount;
                cout<<"Enter amount to withdraw: Rs. ";
                cin>>amount;
                withdraw(amount);
                break;
            }
            case 3: { // balance enquiry case
                float currentBalance = checkBalance();
                cout<<"Current balance: Rs. "<<currentBalance<<endl;
                break;
            }
            case 4: { // exit case
                cout<<"Thank you for using Banking System! Goodbye."<<endl;
                continueMenu = false;
                break;
            }
            default: // invalid choice case
                cout<<"Invalid choice! Please select a valid option."<<endl;
        }
    }
    return 0;

}