#include<iostream>
#include<thread>
#include<mutex>
#include<condition_variable>

bool ready = false;
std::mutex mtx;
std::condition_variable cv;

void Waiter(){
    std::unique_lock<std::mutex> lock(mtx);
    cv.wait(lock, []{ return ready; }); // Wait until ready is true
    std::cout<<"Waiter: Ready is true, proceeding..."<<std::endl; // Proceed after being notified
}

void Signaler(){
    std::this_thread::sleep_for(std::chrono::seconds(1)); // Simulate work
    {
        std::lock_guard<std::mutex> lock(mtx);
        ready = true; // Set ready to true
    }
    cv.notify_one(); // Notify the waiting thread
    std::cout<<"Signaler: Set ready to true and notified waiter."<<std::endl; // Notify that the signal has been sent
}

int main(){
    std::thread t1(Waiter);
    std::thread t2(Signaler);
    t1.join();
    t2.join();
    
}