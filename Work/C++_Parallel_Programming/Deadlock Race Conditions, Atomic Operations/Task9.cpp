#include<iostream>
#include<thread>
#include<atomic>

std::atomic<bool> ready{false}; // signals when the data is ready
int data = 0;
void setData(){
    data = 42;
    ready.store(true, std::memory_order_release); // release the data to other threads
}
void increment(){
    while(!ready.load(std::memory_order_acquire)){ // acquire the data, wait until it's ready
        std::this_thread::yield(); // Yield to other threads while waiting
    }
    std::cout<<"Data: "<<data<<std::endl; // Increment the data after it's ready
}

int main(){
    std::thread t1(setData);
    std::thread t2(increment);
    t1.join();
    t2.join();
    
}