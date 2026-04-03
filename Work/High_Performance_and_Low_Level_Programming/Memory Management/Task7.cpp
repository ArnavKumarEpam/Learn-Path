#include<iostream>
#include<memory>
#include<cstdio>
auto deleter = [](FILE * ptr){
    if(ptr){
        fclose(ptr);
        std::cout<<"File closed by custom deleter\n";
    }
};

int main(){
    FILE* file = fopen("log.txt", "w");
    if(file){
        std::unique_ptr<FILE, decltype(deleter)> filePtr(file, deleter);
        fprintf(filePtr.get(), "Log started\n");
    }
    else {
        std::cerr<<"Failed to open file\n";
    }
    
}