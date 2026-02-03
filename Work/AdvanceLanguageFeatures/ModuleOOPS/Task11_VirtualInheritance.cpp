#include<iostream>

class Device{
    public:
        int id;
        Device(){}
        Device(int id): id(id){ // Device constructor
            std::cout<<"Device class Constructor!"<<std::endl;
            
        }
        void showAddressId(){
            std::cout<<"Showing ID and address of Device instance: "<<id<<" "<<this<<std::endl;
        }

};
class Phone : virtual public Device{
    public:
        Phone():Device(0){ // Phone constructor
            std::cout<<"Phone class Constructor! "<<std::endl;
        }
};
class Camera : virtual public Device{
    public:
        Camera():Device(0){ // Camera constructor
            std::cout<<"Camera class Constructor! "<<std::endl;
        }
};

class SmartPhone : public Phone, public Camera{
    public:
        // single instance of Device is there and its initialized from SmartPhone's constructor 
        SmartPhone(int id) : Device(id), Phone(), Camera(){ // SmartPhone constructor calling Device constructor
            std::cout<<"SmartPhone class Constructor! "<<std::endl;
        }
        void showDeviceInfo(){ // this function demonstrates only one copy is there of device among smartPhone, Phone and Camera
            std::cout<<"Accessing information via SmartPhone: "<<std::endl;
            SmartPhone::showAddressId();

            std::cout<<"Accessing information via Phone: "<<std::endl;
            Phone::showAddressId();

            std::cout<<"Accessing information via Camera: "<<std::endl;
            Camera::showAddressId();
        }
};

int main(){
    SmartPhone smartPhone(101); // initializing value of id in the Device
    // smartPhone.showAddressId();
    smartPhone.showDeviceInfo(); // Display the id and address 

    



}