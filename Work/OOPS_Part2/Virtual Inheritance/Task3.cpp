// #include<iostream>

// class Device{
//     public:
//         Device(){
//             std::cout << "Device constructor\n";
//         }
// };

// class Phone : virtual public Device{
//     public:
//         Phone(){
//             std::cout << "Phone constructor\n";
//         }
// };

// class Camera : virtual public Device{
//     public:
//         Camera(){
//             std::cout << "Camera constructor\n";
//         }
// };

// class SmartPhone : public Phone, Camera{
//     public:
//         SmartPhone() : Phone(), Camera(){
//             std::cout<<"SmartPhone constructor\n";
//         }
// };

// int main(){
//     SmartPhone smartPhone;
// }


#include<iostream>

class Device{
    public:
        
        Device(int id){
            std::cout << "Device constructor\n";
            std::cout<<"Device having ID: "<<id<<std::endl;
        }
};

class Phone : virtual public Device{
    public:
        Phone(int id) : Device(id){
         
            std::cout << "Phone constructor\n";
        }
};

class Camera : virtual public Device{
    public:
        Camera(int id) : Device(id){
           
            std::cout << "Camera constructor\n";
        }
};

class SmartPhone : public Phone, Camera{
    public:
        SmartPhone(int id) :Device(id), Phone(id), Camera(id){
            
            std::cout<<"SmartPhone constructor\n";
        }
};

int main(){
    SmartPhone smartPhone(101);
}
