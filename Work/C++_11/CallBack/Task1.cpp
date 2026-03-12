#include<iostream>
#include<functional>
int x = 20;
//Callback function
void greet(const std::string &name){
    x += 20;
    std::cout << "Hello, " << name << "!" << std::endl;
}
// pointer to function having return type void parameter as string
// void invokeCallback(std::function<void(const std::string &)> callback, const std::string &name){
//     callback(name);
// } // modern way type safe 
void invokeCallback(void(*callback)(const std::string &), const std::string &name){
    callback(name); // old way
}

int main(){
    // Calling function having pointer to greet function 
    invokeCallback(greet, "ABC");
}