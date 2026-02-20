#include<iostream>
#include<exception>
#include <cmath>

class InsufficientFundsException : public std::runtime_error{
    private:
        std::string accountNumber;
        double currentBalance;
        double requestedAmount;
        std::string message;
    public:
        InsufficientFundsException(const std::string& accountNumber, double currentBalance, double requestedAmount) : 
            std::runtime_error("Insufficient funds"), accountNumber(accountNumber), currentBalance(currentBalance), requestedAmount(requestedAmount){
            message = "Account: " + accountNumber + " having current balance: " + std::to_string(currentBalance) + " but requested amount: " + std::to_string(requestedAmount) + "\n";
        }
        
        const char* what() const noexcept override{
            return message.c_str();
        }
};

class InvalidAmountException  : public std::invalid_argument{
    private:
        double invalidAmount;
        std::string operation;
        std::string message;
    public:
        InvalidAmountException(double amount, const std::string &operation) : std::invalid_argument("Invalid Amount"),
            invalidAmount(amount), operation(operation){
                message = "Invalid Amount!\n";
            }
        const char* what() const noexcept override{
            return message.c_str();
        }
};

class AccountNotFoundException   : public std::out_of_range{
    private:
        std::string accountNumber;
        std::string message;
    public:
        AccountNotFoundException(std::string &accountNumber) : out_of_range("Account not found"), accountNumber(accountNumber){
            message = "Account not found! \n";
        }

        const char* what() const noexcept override{
            return message.c_str();
        }
};
class TransactionLimitExceededException : public std::logic_error{
    private:
        double amount;
        double limit;
        std::string message;
    public:
        TransactionLimitExceededException(double amount, double limit)
        : std::logic_error("Transaction limit exceeded"), amount(amount), limit(limit){
            message = "Transaction limit exceeded! \n";
        }

        const char* what() const noexcept override{
            return message.c_str();
        }
};

class BankSystemException : public std::runtime_error{
    private:
        std::string component;
        std::string error;
        std::string message;
    public:
        BankSystemException(const std::string& component, const std::string& error):
         std::runtime_error("Bank system error"), component(component), error(error){
            message = "Bank system error! \n";
         }

        const char* what() const noexcept override{
            return message.c_str();
        }
};

class BankAccount{
    private:
        std::string accountNumber;
        std::string holderName;
        double balance;
        double withdrawalLimit;
        double withdrawnAmount;
    public:
        BankAccount(std::string accountNumber,
        std::string holderName,
        double balance,
        double withdrawalLimit = 50000,
        double withdrawnAmount = 0) : accountNumber(accountNumber), holderName(holderName), balance(balance),
         withdrawalLimit(withdrawalLimit), withdrawnAmount(withdrawnAmount){
            if(this -> balance < 0) throw InvalidAmountException(balance, "Deposit");
            if(accountNumber.empty() || holderName.empty()) throw std::invalid_argument("Account Number and Account Holder Name cannot be empty! \n");
         }
        void validateAmount(double amount, const std::string& operation) const{
            if(amount <= 0){
                throw InvalidAmountException(amount, operation);
            }
            if(std::isnan(amount) || std::isinf(amount)){
                throw std::invalid_argument("Invalid Amount! \n");
            }
        }
        void deposit(double amount){
            validateAmount(amount, "Deposit");
            if(amount > 1000000) throw BankSystemException("Deposit", "Large Deposit");
            balance += amount;
            std::cout<<"Successfully deposited: "<<amount<<std::endl;
        }
        void withdraw(double amount){
            validateAmount(amount, "withdraw");
            if(amount > balance) throw InsufficientFundsException(accountNumber, balance, amount);
            if(withdrawnAmount + amount > withdrawalLimit) throw TransactionLimitExceededException(withdrawnAmount + amount, withdrawalLimit);
            if(amount > 100000) throw BankSystemException("Fraud Detection", "Not Allowed");
            balance -= amount;
            withdrawnAmount += amount;
            std::cout<<"Successfully withdrawn: "<<amount<<", current balance: "<<balance<<std::endl;
        }
        void transferTo(BankAccount & recipient, double amount){
            validateAmount(amount, "Transfer");
            if(recipient.accountNumber == accountNumber) throw std::logic_error("Invalid Operation Cannot self transfer! ");
            withdraw(amount);
            recipient.deposit(amount);
            std::cout<<"Successfully Transferred amount: "<<amount<<" to account number: "<<recipient.accountNumber<<" current balance: "<<balance<<std::endl;
        }
        std::string getAccountNumber() const { return accountNumber; }
        std::string getHolderName() const { return holderName; }
        double getBalance() const { return balance; }
        double getWithdrawalLimit() const { return withdrawalLimit; }
        double getWithdrawn() const { return withdrawnAmount; }
        void printAccountInfo(){
            std::cout<<"Account Number: "<<accountNumber<<std::endl;
            std::cout<<"Account Holder's Name: "<<holderName<<std::endl;
            std::cout<<"Account Balance: "<<balance<<std::endl;
            std::cout<<"Account's Daily Withdrawal Limit: "<<withdrawalLimit<<std::endl;
            std::cout<<"Amount already withdrawn today: "<<withdrawnAmount<<std::endl;
            std::cout<<"Amount can be withdrawn today: "<<withdrawalLimit - withdrawnAmount<<std::endl;
        }

};

int main(){
    try{
        BankAccount bankAccount("123456", "ABC", 3000);
        
        bankAccount.deposit(2000);
        bankAccount.withdraw(1500);
        
        bankAccount.printAccountInfo();
    }catch (...) {std::cout<<"Something unexpected occured! \n";}
    
    try{
        BankAccount bankAccount("123456", "ABC", 3000);
        BankAccount recipient("654321", "DEF", 2000);
        bankAccount.transferTo(recipient, 1500);
    }
    catch (const std::logic_error& e){std::cout<<e.what();}
    try{
        BankAccount bankAccount("123456", "ABC", 3000);
        bankAccount.withdraw(4000);
    }
    catch (const InsufficientFundsException& e){std::cout<<e.what();}
    try{
        BankAccount bankAccount("123456", "ABC", 3000);
        bankAccount.deposit(-1000);
    }
    catch (const InvalidAmountException& e){std::cout<<e.what();}

    catch (const AccountNotFoundException& e){std::cout<<e.what();}
    try{
        BankAccount bankAccount("123456", "ABC", 3000, 5000);
        bankAccount.deposit(4000);
        bankAccount.withdraw(7000);
    }
    catch (const TransactionLimitExceededException& e){std::cout<<e.what();}
    try{
        BankAccount bankAccount("123456", "ABC", 3000);
        bankAccount.deposit(10000000);
    }
    catch (const BankSystemException& e){std::cout<<e.what();}

    // catch (const std::out_of_range& e){std::cout<<e.what();}
    // catch (const std::invalid_argument& e){std::cout<<e.what();}
    
    // catch (const std::runtime_error& e){std::cout<<e.what();}
    // catch (const std::exception& e){std::cout<<e.what();}
    
    // BankAccount recipient("654321", "DEF", 2000, 5000, 0);
    //     BankAccount other("123456", "POP", 9999, 999, 0);
    //     bankAccount.transferTo(recipient, 1500);
    //     bankAccount.transferTo(other, 1000);
    //     bankAccount.withdraw(4900);
    //     bankAccount.deposit(-1000);
    //     bankAccount.withdraw(8000);
    //     bankAccount.withdraw(100000);

}