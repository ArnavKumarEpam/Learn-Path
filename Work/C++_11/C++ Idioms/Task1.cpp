// #include<iostream>
// #include<memory>

// int main(){
//     std::shared_ptr<int> p1 = std::make_shared<int> (42);
//     std::cout<<p1.use_count()<<std::endl;
//     std::weak_ptr<int> wp = p1;
//     std::cout<<wp.lock().use_count();
// }
#include<iostream>
#include<fstream>
#include<string>

class FileWrapper{
    std::ofstream file;
    public:
        FileWrapper(const std::string &s){
            file.open(s);
            if(!file.is_open()){
                throw std::runtime_error("Failed to open file");
            }
            std::cout<<"File opened: "<<s<<std::endl;
        }
        ~FileWrapper(){
            if(file.is_open()){
                file.close();
                std::cout<<"File closed\n";
            }

        }
        std::ofstream &get(){return file;}
};

int main(){
    try{
        FileWrapper file1("Example.txt");
        file1.get()<<"First Line"<<std::endl;
        throw std::runtime_error("Simulated Exception");
        file1.get()<<"Second Line"<<std::endl;
    }
    catch(const std::exception &e){
        std::cerr<<"Exception "<<e.what()<<std::endl;
    }
    std::cout<<"Back in main, after fileWrapper scope ends\n";

}