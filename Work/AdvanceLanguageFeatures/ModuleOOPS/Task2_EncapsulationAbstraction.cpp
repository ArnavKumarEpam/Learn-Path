#include<iostream>
#include <climits>
using namespace std;

class Temperature{
    /* Access specifiers are very important in context of encapsulation
        Private members cannot be accessed outside the class, they can be accessed using getter and setter methods
        by using private public protected access specifiers we can implement encapsulation
    */
    private:
        double celsius = INT_MAX;
    public:
        void setCelsius(double temp){
            if(temp >= -273.15){ // validation check whether temperature below absolute zero is being set
                celsius = temp;
            }
            else{
                cout<<"Error! Temperature is below absolute zero (-273.15)!";
                return;
            }
        }
        double getCelsius(){
            
            return celsius;
        }
        double getFahrenheit(){
            
            return (celsius * 9/5) + 32;
        }

};

int main(){
    Temperature temperature1;
    // temperature1.celsius = 200; // compilation error as celsius is declared private
    temperature1.setCelsius(100); // setting the value of celsius
    
    if(temperature1.getCelsius() == INT_MAX){// validation check when celsius is not set properly
        cout<<"Temperature not set properly Try Again! "<<endl;
        return 1;
    }
    cout<<"Temperature in Celsius: "<<temperature1.getCelsius()<<endl; // returning the celsius value
    if(temperature1.getFahrenheit() == INT_MAX){ // validation check when celsius is not set properly
        cout<<"Temperature not set properly Try Again! "<<endl;
        return 1;
    }
    cout<<"Temperature in Farenheit: "<<temperature1.getFahrenheit()<<endl; // returning the temperature in farenheit 
    return 0;

}