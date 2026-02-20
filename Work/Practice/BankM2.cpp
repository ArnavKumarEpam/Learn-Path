#include<iostream>
using namespace std;

class BankAccount{ // bank account class having private protected and public members and functions
    private:
        int accountNumber = 11223344;
        double balance = 0;
    protected:
        string ownerName;
    public:
        void deposit (double amount){ // function to deposit money in the account
            
            balance += amount;
            cout<<"Successfully deposited the amount: "<< endl;
            cout<<"Current balance: "<< balance << " in the account number: " << accountNumber<<endl;
        }

        void withdraw(double amount){ // function to withdraw money from the account
            if(amount <= balance){
                balance -= amount;
                cout<<"Amount deducted from the bank successfully, current balance: "<< balance <<endl;
            }
            else{
                cout<<"Insufficient balance in the account, current balance: " << balance<<endl;
            }
        }
        double getBalance(){ // returing the balance of the acount
            return balance;
        }
};

class VIPAccount : public BankAccount{ // VIP account class inheriting BankAccount class
    public:
        void setOwnerName(string name){ // setter for setting the owner name of the bankaccount
            ownerName = name; // accessing protected member of the bank account class
        }
        void printOwnerName(){ // access ownerName from BankAccount class
            cout<<"Owner Name derived from BankAccount class: "<<ownerName<<endl;
        }

        // Balance is Inaccessible as its declared private
        // void printBalance(){
        //     cout<<balance;
        // }
};

int main(){
    BankAccount bankAccount;
    
    // trying to access private members like balance
    // bankAccount.balance = 10000; // Member is inaccessible

    // trying to access ownerName which is protected
    // cout<<bankAccount.ownerName; // member is inaccessible
    
    // depositing the amount in the bank account number mentioned 
    bankAccount.deposit(10000);
    bankAccount.withdraw(5000); // withdrawing amount from the bank 
    cout<<"Balance is the Account is:" << bankAccount.getBalance(); // getting the balance of the bank account
    VIPAccount vipAccount;
    vipAccount.setOwnerName("ARNAV KUMAR");
    vipAccount.printOwnerName();
    return 0;


}