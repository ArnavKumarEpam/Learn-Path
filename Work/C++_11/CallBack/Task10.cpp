#include<iostream>
#include<functional>
void invokeCallback(void(*cb)(const std::string &), const std::string &user){
    cb(user); // calls the function 
}

int main(){
    int f = 10;
    invokeCallback([f](const std::string &user){ // this lambda expression represent the callback function to be called in invokeCallback function
        std::cout<<"Lambda callback says: welcomes, "<<user<<"!"<<std::endl;
    }, "LambdaUser");


}