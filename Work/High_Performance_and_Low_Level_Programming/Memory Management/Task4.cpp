#include<iostream>
#include<memory>

class LogMessage{
    private:
        std::string message_content;
    public:
        LogMessage(const std::string & message) : message_content(message){
            std::cout << "LogMessage '" << message_content << "' created. Address: " << this << std::endl;
        }
        ~LogMessage(){
            std::cout << "LogMessage '" << message_content << "' destroyed. Address: " << this << std::endl;
        }
        void printContent() const{
            std::cout << "LogMessage content: " << message_content << std::endl;
        }

};

void handleLegacyLog(LogMessage* rawMessage){
    if(rawMessage == nullptr){
        std::cout << "Legacy system received a nullptr log.\n"; return; 
    }
    std::cout<<"Legacy system is now handling log: "<< std::endl;
    rawMessage->printContent();
    delete rawMessage; // Manually delete the message after handling
    std::cout<<"Legacy system finished processing and deleting the message.\n";
}

int main(){
    std::unique_ptr<LogMessage> myLog = std::make_unique<LogMessage>("System Startup Event");
    std::cout<<"Unique Pointer created and managing LogMessage.\n";
    myLog->printContent();
    LogMessage * handedOverLog = myLog.release();
    std::cout<<"myLog unique_ptr has released ownership. Handed over log address: " << handedOverLog << std::endl;
    if(myLog == nullptr){
        std::cout<<"myLog unique_ptr is now empty (nullptr) after release().\n";
    }else std::cout << "Error: myLog unique_ptr is NOT empty after release()!\n";
    handleLegacyLog(handedOverLog);

}