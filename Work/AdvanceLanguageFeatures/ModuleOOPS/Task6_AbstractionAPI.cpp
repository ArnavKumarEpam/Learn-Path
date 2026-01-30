#include<iostream>
using namespace std;

class Car{
    private:
        bool engineOn;
        int speed;
        int rpm;
    public:
        void start(){
            if(!engineOn) engineOn = true; // checks the engine if off then turn it on
            cout<<"Engines is started! Speed and Rpm are at 0. "<<endl;
            // initialize speed and rpm
            speed = 0;
            rpm = 1000; // idle engine rpm
        }
        void accelerate(){
            if(!engineOn) { // check if the Car is OFF or not
                cout<<"Car is OFF! "<<endl;
                return;
            }
            
        
            speed += 20;
            rpm += 2000;
            if(speed >= 140){ // Speed Cap so that Speed doesn't go past 140
                cout<<"Slow Down Speed Thrills but Kills! Speed capped at 140"<<endl;
                speed = 140;
                return;
            }
            cout<<"Speed and RPM of the Car: "<<speed<<" "<<rpm<<endl;
        }
        void brake(){
            if(!engineOn){ // checks if car engine is off or nor
                cout<<"Car is OFF! "<<endl;
                return;
            }
            if(speed == 0){ // if the car is already at halt cannot decrease speed 
                cout<<"Car already came to halt! "<<endl;
                return;
            }

            rpm -= 1000;
            if(rpm < 1000){ // as the car engine is ON rpm cannot dip below idle rpm - 1000
                rpm = 1000;
            }
            speed -= 20;
            if(speed <= 0){
                speed = 0;
            }
            
            
            cout<<"Car slowing down! Current Speed and Rpm: "<<speed <<" "<<rpm<<endl;
            
            
        }

};

int main(){
    Car driver;

    driver.start();
    // increasing the speed and rpm of the car
    driver.accelerate();
    driver.accelerate();
    driver.accelerate();
    driver.brake();
    return 0;
    
}