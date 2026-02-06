#include<iostream>

class BaseLogger{
    public:
        virtual ~BaseLogger(){
            std::cout<<"Destructor of BaseLogger! "<<std::endl;
        }
};

class FileLogger : public BaseLogger{
    public: 
        ~FileLogger(){
            std::cout<<"Destructor of FileLogger! "<<std::endl;
        }
};

class ConsoleLogger : public BaseLogger{
    public:
        ~ConsoleLogger(){
            std::cout<<"Destructor of ConsoleLogger! "<<std::endl;
        }
};

int main(){
    FileLogger *fL = new FileLogger();
    BaseLogger * bF = fL;
    ConsoleLogger *cL = new ConsoleLogger();
    BaseLogger * bC = cL;
    delete(bF);
    // Destructor of FileLogger will be called and then Destructor of Logger be called
    delete(bC);
    // Destructor of ConsoleLogger will be called and then Destructor of Logger be called
    
    
}