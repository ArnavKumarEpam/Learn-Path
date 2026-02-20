#include<iostream>

class Device{
    public:
        int id;
        Device(){}
        Device(int id): id(id){ // Device constructor
            std::cout<<"Device class Constructor!"<<std::endl;
            
        }
        void showId(){
            std::cout<<"Showing ID of the Device: "<<id<<std::endl;
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
        SmartPhone(int id) : Device(id), Phone(), Camera(){
            std::cout<<"SmartPhone class constructor called! "<<std::endl;
        }
        
       
};

int main(){
    SmartPhone smartPhone(101); // initializing value of id in the Device
    // Address will be same for all as only one object is made and its shared among others
    std::cout << "Via Phone: " << static_cast<Device*>((Phone*)&smartPhone) << '\n';
    std::cout << "Via Camera: " << static_cast<Device*>((Camera*)&smartPhone) << '\n';
    std::cout << "Via Camera: " << static_cast<Device*>(&smartPhone) << '\n';
    smartPhone.showId();
    

    



}