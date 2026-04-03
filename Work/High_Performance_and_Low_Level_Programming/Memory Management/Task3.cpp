#include<iostream>
#include<memory>
class SensorReport{
    int value;
    std::string sensorName;
    public:
        SensorReport(int value, std::string sensorName) : value(value), sensorName(sensorName){
            std::cout<<"SensorReport for "<<sensorName<<" created"<<std::endl;
        }
        void displayDetails(){
            std::cout<<"Sensor: "<<sensorName<<", Value: "<<value<<std::endl;
        }
        ~SensorReport(){
            std::cout<<"SensorReport for "<<sensorName<<" destroyed"<<std::endl;
        }

};

int main(){
    int rawSensorValue = 75;
    std::string sensorIdentifier = "Pressure_A01";
    std::unique_ptr<SensorReport> criticalReportPtr = std::make_unique<SensorReport>(rawSensorValue, sensorIdentifier);
    std::cout << "Processing critical sensor report:" << std::endl; 
    criticalReportPtr->displayDetails();
    // std::unique_ptr<SensorReport> anotherReport = criticalReportPtr; // This line should cause a compile-time error!

}