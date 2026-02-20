#include<iostream>

class Device{
    public:
        int id;
        Device(){}
        Device(int id) : id(id){}
        void showId(){
            std::cout<<id<<std::endl;
        }
};

class Camera : public  Device{
    public:
    Camera(int id) : Device(id){}
};

class Phone : public  Device{
    public:
    Phone(int id) : Device(id){}
    
};

class SmartPhone : public Camera, public Phone{
    public:
    SmartPhone(int id) : Device(id), Camera(id), Phone(id){}
};

int main(){
    SmartPhone sP(5);
    std::cout<<sP.id<<std::endl;
    sP.Camera::showId();
    sP.Phone::showId();

}
