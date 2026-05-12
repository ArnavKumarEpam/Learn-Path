#include<iostream>
#include<memory>
#include<cstdio>
struct FreeDel{
    void operator()(FILE * f) const{
        if(f) fclose(f);
        std::cout<<"Deleted by custom deleter!\n";
    }
};

int main(){
    FILE* file = fopen("log.txt", "w");
    if(file){
        std::unique_ptr<FILE, FreeDel> filePtr(file);
        fprintf(filePtr.get(), "Log started\n");
    }
    else {
        std::cerr<<"Failed to open file\n";
    }
    
}