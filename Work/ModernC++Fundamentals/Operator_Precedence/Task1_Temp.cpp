#include<iostream>
using namespace std;

float fahrenheitToCelsius(float fahrenheitTemp){ // function to convert Fahrenheit to Celsius
    return (fahrenheitTemp  - 32) * 5.0 / 9.0;
}

int main(){
    cout<<"Welcome to Temperature Calculator! "<<endl;
    float fahrenheitTemp;
    cout<<"Enter temperature in Fahrenheit: ";
    cin>>fahrenheitTemp;
    if(cin.fail()){ // input validation
        cout<<"Invalid input! Please enter a numeric value."<<endl;
        cin.clear(); // clear error flag
        return 0;
    }
    float celsiusTemp = fahrenheitToCelsius(fahrenheitTemp); // calling conversion function
    cout<<"Temperature in Fahrenheit: "<<fahrenheitTemp<<endl;
    cout<<"Temperature in Celsius: "<<celsiusTemp<<endl;
    return 0;
}