#include<iostream>
#include<exception>

class BankAccount{
    private:
        std::string owner;
        int accountNumber;
        double balance;
    public:
        BankAccount(std::string owner, int accountNumber, double balance) :
            owner(owner), accountNumber(accountNumber), balance(balance){}
        void deposit(double amount){
            if(amount < 0) throw std::invalid_argument("Deposit amount cannot be negative.");
            else{
                balance += amount;
                std::cout<<amount<<" deposited in account: "<<accountNumber<<std::endl;
            }
        }
        void withdraw(double amount){
            if(amount < 0) throw std::invalid_argument("Deposit amount cannot be negative.\n");
            else if(amount > balance) throw std::runtime_error("Withdraw amount is more than current balance! \n");
            else {balance -= amount;
                std::cout<<amount<<" withdrawn from account: "<<accountNumber<<std::endl;
            }
        }

        bool transferTo(BankAccount& targetAccount, double amount) noexcept{
            if(amount > balance || amount <= 0) return false;
            withdraw(amount);
            targetAccount.deposit(amount);
            return true;
        }
        double getBalance() const {
            return balance;
        }
        void print(){
            std::cout<<"Account Holder: "<<owner<<std::endl;
            std::cout<<"Account Number: "<<accountNumber<<std::endl;
            std::cout<<"Balance: "<<balance<<std::endl;
        }
};

int main(){
    BankAccount alice("Alice", 1001, 500.0); 
    BankAccount bob("Bob", 1002, 300.0);
    std::cout<<"<- - - -Deposit Operation:- - - -> "<<std::endl;
    try{
        alice.deposit(2000);
        alice.print();
        alice.deposit(-1000);
    }
    catch(const std::exception &e){
        std::cout<<e.what()<<std::endl;
    }
    alice.print();
    std::cout<<"<- - - -Withdraw Operation:- - - -> "<<std::endl;
    try{
        alice.withdraw(250);
        alice.print();
        alice.withdraw(10000);
    }
    catch(const std::exception &e){
        std::cout<<e.what();
    }
    alice.print();
    std::cout<<"<- - - - Transfer Operation:- - - -> "<<std::endl;
    try{
        if(alice.transferTo(bob, 400)) std::cout<<"Transfer Successfull! "<<std::endl;
        else std::cout<<"Transfer Unsuccessfull! "<<std::endl;
        alice.print();
        bob.print();
        if(alice.transferTo(bob, 20000)) std::cout<<"Transfer Successfull! "<<std::endl;
        else std::cout<<"Transfer Unsuccessfull! "<<std::endl;
            
        
    }
    catch(const std::exception &e){
        std::cout<<e.what();
    }
    alice.print();
    bob.print();

}
