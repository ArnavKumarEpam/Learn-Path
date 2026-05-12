#include<iostream>
#include<thread>
#include<mutex>
#include<barrier> 
#include<chrono>


std::barrier<> barrier{3}; // Create a barrier for 3 threads
// Barrier is a synchronization primitive that allows multiple threads to wait until they have all reached a certain point in their execution before any of them can proceed.
void Worker(){
    std::this_thread::sleep_for(std::chrono::seconds(1)); // Simulate work
    std::cout<<"Thread " << std::this_thread::get_id() << " before barrier"<<std::endl; // Output before waiting at the barrier
    barrier.arrive_and_wait(); // Wait for all threads to reach the barrier
    std::cout<<"Thread " << std::this_thread::get_id() << " after barrier"<<std::endl; // Output after passing the barrier
}

int main(){
    std::thread t1(Worker);
    std::thread t2(Worker);
    std::thread t3(Worker);
    t1.join();
    t2.join();
    t3.join();

}