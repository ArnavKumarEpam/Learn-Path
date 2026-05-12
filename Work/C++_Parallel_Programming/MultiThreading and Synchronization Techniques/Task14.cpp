#include<iostream>
#include<mutex>
#include<thread>
#include<future>
#include<chrono>

int longComputation(){
    std::this_thread::sleep_for(std::chrono::seconds(2)); // Simulate a long computation
    return 42; // Return some result after computation
}

int main(){
    // future is a class template that provides a mechanism to access the result of asynchronous operations. It is used in conjunction with std::async to retrieve the result of a function that is executed asynchronously.
    std::future<int> res = std::async(std::launch::async, longComputation); // Launch longComputation in a separate thread and return a future object to retrieve the result later
    int result = res.get(); // get() blocks the calling thread until the result is available and then returns it. If the asynchronous operation has already completed, it returns the result immediately. If the asynchronous operation threw an exception, get() will rethrow that exception in the calling thread.
    std::cout<<"Result of long computation: "<<result<<std::endl;
}