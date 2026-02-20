#include<iostream>
#include<vector>
#include <memory>
using namespace std;

class Payment{ // Abstract class Payment
    public:
        virtual void processPayment(double amount) = 0; // pure vitual processPaymeny function
};

class CreditCardPayment : public Payment{ // CreditCardPayment class inheriting abstract Payment class
    public:
        void processPayment(double amount) override{ // overriding processPayment function using pointer of base class
            cout<<"Processing Credit Card Payment of Amount: "<<amount<<endl;
        }
};

class PayPalPayment : public Payment{ // PayPalPayment class inheriting abstract Payment class
    public:
        void processPayment(double amount) override{ // overriding processPayment function using base class pointer
            cout<<"Processing PayPal Payment of Amount: "<<amount<<endl;
        }
};

 // Polymorphism and Abstraction
    // In polymorphism the base class pointer points to derived object and with the help of virtual derived function is called and executed
int main(){
    vector<shared_ptr<Payment>> arr; // array of pointers
    CreditCardPayment creditCardPayment;
    PayPalPayment payPalPayment;
    // Payment class pointer points to child class objects
    shared_ptr<Payment> creditCard = make_shared<CreditCardPayment> (); // use of smart pointers for automatic memory deallocation
    shared_ptr<Payment> payPal = make_shared<PayPalPayment> (); // use of smart pointers for automatic memory deallocation

    arr.push_back(creditCard);
    arr.push_back(payPal);
    for(int i = 0 ; i < arr.size() ; i++){
        arr[i]->processPayment(10000);
    }

    return 0;


}