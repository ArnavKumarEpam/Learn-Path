#include<iostream>
#include<exception>
class LogSession{
    int id;
    public:
        LogSession(int id): id(id){
            std::cout<<"[LogSession ID: "<<id<<"] started"<<std::endl;
        }
        ~LogSession(){
            std::cout<<"Log Session ID: "<<id<<"] ended"<<std::endl;
        }
};

void performDataValidation(){
    int id = 3;
    LogSession log(id);
    if(id >= 2) throw std::invalid_argument("Invalid Data\n");
    else  std::cout<<"Log Session ID: "<<id<<"] data validated successfully."<<std::endl;
}

void processTransaction(){
    int id = 2;
    LogSession log(id);
    performDataValidation();
    std::cout<<"Log Session ID: "<<id<<"] transaction processed."<<std::endl;
}

void startCriticalOperation(){
    int id = 1;
    LogSession log(id);
    processTransaction();
    std::cout<<"Log Session ID: "<<id<<"] critical operation completed."<<std::endl;
}

int main(){
    std::cout<<"Starting main block\n";
    try{
        startCriticalOperation();
    }
    catch(std::exception &e){
        std::cout<<"Inside the main catch handler.\n";
        std::cout<<e.what();
    }
    catch(...){}

}