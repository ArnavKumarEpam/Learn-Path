#include<iostream>
#include<functional>
void invokeCallback(void(*cb)(const std::string &), const std::string &user){
    cb(user); // calls the function 
}

int main(){
    int f = 10;
    // If use capture value then it wont work as it wont be converted to void (*)(const std::string&)
    // But if we use std::function then it will work 
    invokeCallback([](const std::string &user){ // this lambda expression represent the callback function to be called in invokeCallback function
        std::cout<<"Lambda callback says: welcomes, "<<user<<"!"<<std::endl;
    }, "LambdaUser");


}