#include<iostream>
#include<fstream>
#include<limits>
int main(){
    std::ifstream read("Task7.txt");
    if(!read.is_open()){
        std::cout<<"Unable to open the file! \n";
        return 1;
    }
    int value;
    while(true){
        read >> value;    
        std::cout<<"Value: "<<value<<" ";
        if(!read.eof()){
            std::cout<<"Reached the End of the File\n";
            break;
        }
        if(read.fail()){
            std::cout<<"Invalid Token Found Skipping\n";
            read.clear();
            read.ignore(std::numeric_limits<std::streamsize>::max(), ' ');
            continue;
        }
        if(read.bad()){
            std::cerr<<"Serious I/O Error Encountered\n";
            break;
        }

    }
    read.close();
}