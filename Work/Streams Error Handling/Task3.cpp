#include<iostream>
#include<fstream> // includes functions of ifstream and ofstream

int main(){
    std::cout<<"Enter the name of the file: ";
    std::string fileName;
    getline(std::cin,fileName); // takes input of the file name having spaces

    std::ofstream writeObject(fileName, std::ios::out);
    if(!writeObject.is_open()){
        std::cerr<<"Unable to open the file! "<<std::endl;
        return 1;
    }
    
    writeObject << "This is the file!";
    writeObject.close();
    std::ifstream readObject(fileName, std::ios::in);
    if(!readObject.is_open()){
        std::cerr<<"Unable to open the file! "<<std::endl;
        return 1;
    }
    std::string data;
    getline(readObject, data); // to read the complete string including the spaces
    std::cout<<"The data of the file: "<<data<<std::endl;
    readObject.close();
}