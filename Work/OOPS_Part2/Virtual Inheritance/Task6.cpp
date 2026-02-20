#include<iostream>

class Logger{
    public:
        virtual void log(std::string &message) = 0;
        virtual ~ Logger(){
            std::cout<<"Logger destroyed! "<<std::endl;
        }
};

class FileLogger : public Logger{
    public:
        void log(std::string &message){
            std::cout<<message<<std::endl;
        }

        ~FileLogger(){
            std::cout<<"FileLogger destroyed! "<<std::endl;
        }
};

class ConsoleLogger : public Logger{
    public:
        void log(std::string &message){
            std::cout<<message<<std::endl;
        }

        ~ConsoleLogger(){
            std::cout<<"ConsoleLogger destroyed! "<<std::endl;
        }
};

int main(){
    Logger * filePtr = new FileLogger();
    std::string message = "FileLogger";
    filePtr -> log(message);

    Logger * consolePtr = new ConsoleLogger();
    std::string message2 = "ConsoleLogger";
    consolePtr -> log(message2);
    delete(filePtr);
    delete (consolePtr);

}