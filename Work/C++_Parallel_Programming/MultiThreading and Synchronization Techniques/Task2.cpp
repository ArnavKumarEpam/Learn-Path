#include<iostream>
#include<thread>
#include<chrono>

void worker(){
    std::this_thread::sleep_for(std::chrono::seconds(2)); // Simulate work by sleeping for 2 second
    std::cout<<"Worker thread completed! "<<std::endl;
}

int main(){
    std::thread t(worker); // Create a thread to run the worker function
    std::cout<<"Main thread is doing other work... "<<std::endl;
    // If we use join here, then the main thread will wait for the worker thread to finish before proceeding, which is not desired in this case- worker function message will be printed before main ends
    t.detach(); // Detach the worker thread to allow it to run independently, main thread continues without waiting for worker to finish
    std::this_thread::sleep_for(std::chrono::seconds(4)); // to check if worker thread is still running after main thread ends, we can add a sleep here to ensure main thread doesn't end immediately, allowing us to see the worker thread's output before the program exits
    std::cout<<"Main ends\n";
}