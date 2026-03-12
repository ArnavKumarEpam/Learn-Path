#include<iostream>
#include<string>
#include<functional>

void greet(const std::string& name) {
    std::cout << "Hello, " << name << "!" << std::endl;
}

void invokeCallback(std::function<void(const std::string &)>callback, const std::string &s){
    callback(s);
}   

int main(){
    invokeCallback(greet, "ABC");
    invokeCallback([](const std::string &message){
        std::cout << "Lambda says hi to " << message << "!" << std::endl;
    }, "ABCD");

}