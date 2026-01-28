#include<iostream>
using namespace std;

class BankAccount{
    private: // private access specifier 
        // private members cannot be accessed outside the class it can be accessed using getter and setter
        int accountNumber;
        double balance;
    public:
        void deposit(double amount){ 
            if(amount <= 0) { // checks if deposit amount is less than 0
                cout<<"Deposit Amount is less than 0!"<<endl;
                return;
            }
            balance += amount; // adds up the balance
            cout<<"Amount deposited: "<<amount<<endl;
            cout<<"Current Balance after deposit: "<<balance<<endl;
        }
        double getBalance(){ // getter method of balance
            return balance;
        }
        void withdraw(double amount){ // function to withdraw 
            if(amount > balance){ // check if withdraw amount is less than balance
                cout<<"The withdraw amount is greater than Balance! "<<endl;
                return;
            }
            if(amount <= 0){
                cout<<"Withdrawl amount is less than zero!"<<endl;
                return;
            }
            balance -= amount; // reduce the amount from balance 
            cout<<"Amount withdrawn: "<<amount<<endl;
            cout<<"Current Balance after withdrawl: "<<balance<<endl;
        }
};

int main(){
    BankAccount bankAccount;
    // cout<<bankAccount.accountNumber; this will cause compilation error
    bankAccount.deposit(10000);
    bankAccount.withdraw(500);
    cout<<"Current balance: "<<bankAccount.getBalance();
}