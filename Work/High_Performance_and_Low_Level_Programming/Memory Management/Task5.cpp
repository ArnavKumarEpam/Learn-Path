#include<iostream>
#include<memory>

class FileHandler{
    public:
        FileHandler(){
            std::cout<<"File Opened! "<<std::endl;
        }
        ~FileHandler(){
            std::cout<<"File Closed! "<<std::endl;
        }
        void write(const std::string &message){
            std::cout<<"Writing to file: "<<message<<std::endl;
        }
        

};
std::unique_ptr<FileHandler> createFileHandler(){
    return std::make_unique<FileHandler>();
}

void processFileHandler(std::unique_ptr<FileHandler> handler) {
    std::cout<<"Processing file handler..."<<std::endl;
    handler->write("Processing data...");
    std::cout<<"Finished processing file handler."<<std::endl;
}

int main(){
    std::unique_ptr <FileHandler> handler = createFileHandler();
    processFileHandler(std::move(handler));
    if (handler) {
        handler->write("This will cause an error!"); // This will cause an error because handler is now empty (nullptr)
    }
    else {
        std::cout<<"Handler is empty (nullptr) after being moved to processFileHandler."<<std::endl;
    }

}