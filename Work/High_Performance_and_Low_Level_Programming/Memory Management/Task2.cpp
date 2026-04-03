#include<iostream>
#include<memory>
class Logger{
    std::string name;  
    bool isOpen;
    public:
        Logger(std::string name) : name(name), isOpen(true) {
            std::cout<<"Logger "<<name<<" created"<<std::endl;
        }
        void log(const std::string& name){
            if(!isOpen){
                std::cout<<"Logger '"<<name<<"' is closed. Cannot log."<<std::endl;
                return;
            }
            std::cout<<"["<<name<<"]: Hello from "<<name<<std::endl;
            
        }
        void close(){
            if(isOpen){
                std::cout<<"Logger '"<<name<<"' closing."<<std::endl;
                isOpen = false;
            }
        }
        ~Logger(){
            close();
            std::cout<<"Logger '"<<name<<"' destroyed."<<std::endl;
        }
        std::string getName() const{
            return name;
        }
};

int main(){
    std::unique_ptr<Logger> logger = std::make_unique<Logger>("MainLogger");
    std::string logName = "MainLogger";
    logger->log(logName);
    logger = std::make_unique<Logger>("SecondaryLogger");
    std::string secondLogName = "SecondaryLogger";
    logger->log(secondLogName);
    logger.reset(new Logger("TemporaryLogger"));
    std::string tempLogName = "TemporaryLogger";
    logger->log(tempLogName);
    logger.reset();
    if(logger){
        std::cout<<"Logger is not null"<<std::endl;
    } else {
        std::cout<<"Logger is null"<<std::endl;
    }
    logger = nullptr;
    logger = std::make_unique<Logger>("NewLogger");
    std::string newLogName = "NewLogger";
    logger->log(newLogName);

    std::unique_ptr<Logger> logger2 = std::make_unique<Logger>("Logger2");
    std::string logger2Name = "Logger2";
    logger2->log(logger2Name);
    logger = std::move(logger2);
    std::cout << "logger2 is " << (logger2 ? "not null" : "nullptr") << "\n";
    logger = std::move(logger);
}