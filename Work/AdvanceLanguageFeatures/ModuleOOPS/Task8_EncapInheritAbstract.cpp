    #include<iostream>

    /*
        Multilevel inheritance : In this base class in inherited in child class
        and that child class is further inherited in its child class and now constructor calling
        is done such that first the constructor of top most base class is called then its child and successive child
        
        Vehicle -> Car -> ElectricCar
        is the order of constrctor in this example and the destructor will be called in opposite fashion
        ElectricCar -> Car -> Vehicle
    */

    class Vehicle{
        std::string make;
        std::string model;
        public:
            Vehicle(std::string make, std::string model){
                this -> make = make;
                this -> model = model;
                std::cout<<"Vehicle Make: "<<make <<", Vehicle Model: "<<model<<std::endl;
                std::cout<<"Vehicle constructor called "<<std::endl;
            }
            std::string getMake(){return make;} // getter function for make
            std::string getModel(){return model;} // setter function for model

    };

    class Car : public Vehicle{
        int doors;
        public:
            Car(std::string make, std::string model, int door) : Vehicle(make, model){ //constructor chaining of Vehicle class
                
                doors = door;
                std::cout<<"Car constructor called "<<std::endl;
            }
            int getDoors(){return doors;} // getter function for doors

            virtual void res(){
                std::cout<<getMake()<<" "<<getModel()<<" "<<doors<<std::endl;
            }

    };

    class ElectricCar : public Car{
        double batteryCapacity;
        public:
            ElectricCar(std::string make, std::string model,int doors, double battery) :
            Car(make, model, doors) { // constructor chaining of Car class
                batteryCapacity = battery;
                std::cout<<"ElectricCar constructor called "<<std::endl;
            }
            void res() override{ // function to display all the attributes
                std::cout<<"Vehicle Make: "<<
                getMake()<<", Vehicle Model: "<<getModel()<<", Vehicle's Doors: "<<getDoors()<<", Vehicle's Battery: "<<batteryCapacity<<std::endl;

            }
    };

    int main(){
        ElectricCar eC("Merc", "AMG", 2, 78); // ElectricCar constructor having all the information
        eC.res(); // calling the res function to display all the attributes
        return 0;
    }