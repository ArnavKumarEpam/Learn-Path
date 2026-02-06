#include<iostream>
using namespace std;

double calculateSimpleInterest(double principal, double rate, double time){ // function to calculate simple interest
    // Simple Interest (SI) = (P * R * T) / 100
    return (principal * rate * time) / 100.0;
}

int main(){
    cout<<"Welcome to Simple Interest Calculator! "<<endl;
    cout<<"Enter Principal amount 'P' (in Rs.): ";
    double principal;
    cin>>principal;
    if(cin.fail() || principal < 0){ // input validation for principal amount
        cout<<"Invalid input! Please enter a positive numeric value for principal amount."<<endl;
        cin.clear(); // clear error flag
        return 0;
    }
    cout<<"Enter Rate of Interest 'R' (in %): ";
    double rate;
    cin>>rate;
    if(cin.fail() || rate < 0){ // input validation for rate of interest
        cout<<"Invalid input! Please enter a positive numeric value for rate of interest."<<endl;
        cin.clear(); // clear error flag
        return 0;
    }
    cout<<"Enter Time period 'T' (in years): ";
    double time;
    cin>>time;
    if(cin.fail() || time < 0){ // input validation for time period
        cout<<"Invalid input! Please enter a positive numeric value for time period."<<endl;
        cin.clear(); // clear error flag
        return 0;
    }
    double interest = calculateSimpleInterest(principal, rate, time); // calling interest calculation function
    cout<<"Simple Interest for Principal Rs. "<<principal<<" at Rate "<<rate<<"% " << "for "<<time<<" years is: Rs. "<<interest<<endl; // displaying the simple interest calculated

}
