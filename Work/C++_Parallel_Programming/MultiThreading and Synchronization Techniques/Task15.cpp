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
    // promise is a class template that provides a mechanism to set a value or an exception that will be retrieved by a future. It is used to communicate between threads, allowing one thread to produce a value and another thread to consume it.
    std::promise<int> prom;
    std::future<int> res = prom.get_future();
    std::thread t([&prom](){
        prom.set_value(longComputation());
    });
    int result = res.get(); // get() blocks the calling thread until the result is available and then returns it. If the asynchronous operation has already completed, it returns the result immediately. If the asynchronous operation threw an exception, get() will rethrow that exception in the calling thread.
    std::cout<<"Result of long computation: "<<result<<std::endl;
    t.join(); // Ensure the thread has finished before exiting main
}