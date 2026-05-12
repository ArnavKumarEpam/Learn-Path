#include<iostream>
#include<thread>
#include<mutex>
#include<atomic>

std::atomic<int> value{10};

int main(){
    int prev = value.fetch_add(5); // Atomically add 5 to value and return the previous value
    std::cout<<"Previous Value: "<<prev<<std::endl; // Output the previous value
    std::cout<<"Current Value: "<<value.load()<<std::endl; // Output the current value after adding 5 to the value

    prev = value.fetch_sub(3); // Atomically subtract 3 from value and return the previous value
    std::cout<<"Previous Value: "<<prev<<std::endl; // Output the previous value

    std::cout<<"Current Value: "<<value.load()<<std::endl; // Output the current value after subtracting 3 from the value

    prev = value.exchange(42); // Atomically set value to 42 and return the previous value
    std::cout<<"Previous Value: "<<prev<<std::endl; // Output the previous value
    std::cout<<"Current Value: "<<value.load()<<std::endl; // Output the current value after exchanging the value
}
