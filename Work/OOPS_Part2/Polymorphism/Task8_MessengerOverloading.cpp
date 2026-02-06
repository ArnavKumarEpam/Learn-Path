#include<iostream>

class Messenger{
    public:
        void send(const std::string &msg){
            std::cout<<msg<<std::endl;
        }
        void send(const std::string &msg, int priority = 1){
            std::cout<<"Priority: "<<priority << ": "<<msg<<std::endl;
        }
};

int main(){
    Messenger messenger;
    // messenger.send("Hello");
    messenger.send("World", 5);
    std::string msg = "HEELLOO";
    // messenger.send(msg);
    /*
        send function with only string msg call is ambigious as compiler gets confused which version to run
        So, to correct it
            1. Remove the single argument send function 
            2. Remove the default argument from the send function
        The compiler gets confused with both send function as it results in:
            1. Single argument: send(msg)
            2. Two argument: send(msg) as by default priority is 1
    */
}