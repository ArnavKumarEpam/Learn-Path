#include<iostream>
#include <fstream>
int main(){
    std::string fileRead; // file to store data from user
    std::cout<<"Enter the File which content you want to copy: \n";
    getline(std::cin, fileRead);

    // std::ofstream writeFile(fileRead, std::ios::out); // writing data in that file
    // if(!writeFile.is_open()){
    //     std::cerr<<"Unable to open the file! \n";
    // }
    // std::cout<<"Enter the data you want to enter in the file: ";
    // std::string data;
    // getline(std::cin, data); // taking input from the user 
    // writeFile<<data; // writing data in that file
    // writeFile.close();
    std::ifstream readFile(fileRead, std::ios::in); // open file in read mode
    if(!readFile.is_open()){
        std::cerr<<"Unable to open the file! \n";
    }
    
    std::string fileWrite; // file to copy data
    std::cout<<"Enter the File Name to which you want to copy the data:  ";
    getline(std::cin, fileWrite);
    std::ofstream write(fileWrite, std::ios::out);
    if(!write.is_open()){
        std::cerr<<"Unable to Open the File! \n";
    }
    std::string copyData;
    if(readFile && write){
        while(getline(readFile, copyData)){ // copying data from file
            write<<copyData<<std::endl;
        }
    }
    if(readFile.eof()) std::cout<<"Successfully copied data! \n";
    // closing the files
    readFile.close();
    write.close();
}