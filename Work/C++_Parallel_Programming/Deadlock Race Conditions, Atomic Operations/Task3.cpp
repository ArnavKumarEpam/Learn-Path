#include<iostream>
#include<thread>
#include<mutex>

std::mutex m1, m2, m3;
// Maintain an order for acquiring mutexes m1 -> m2 -> m3 in the program to avoid deadlock

void Task1(){
    m1.lock();
    std::cout<<"Task1 has acquired m1"<<std::endl;
    std::this_thread::sleep_for(std::chrono::milliseconds(100)); // Simulate some work
    m2.lock();
    std::cout<<"Task1 has acquired m2"<<std::endl;
    std::this_thread::sleep_for(std::chrono::milliseconds(100)); // Simulate some work
    m3.lock();
    std::this_thread::sleep_for(std::chrono::milliseconds(100)); // Simulate some work
    std::cout<<"Task1 has acquired m3"<<std::endl;
    std::cout<<"Task1 completed!"<<std::endl;
    m3.unlock();
    m2.unlock();
    m1.unlock();
}
void Task2(){
    // Before
    // Deadlock causing code as Task1 locks m1, then m2 and then m3, while Task2 locks m2, then m3 and then m1, if Task1 locks m1 and Task2 locks m2 at the same time, then Task1 will be waiting for m2 to be released by Task2 and Task2 will be waiting for m1 to be released by Task1, resulting in a deadlock where both threads are waiting indefinitely for each other to release the mutexes they need to proceed.
    // m2.lock();
    // std::cout<<"Task2 has acquired m2"<<std::endl;
    // std::this_thread::sleep_for(std::chrono::milliseconds(100)); // Simulate some work
    // m3.lock();
    // std::this_thread::sleep_for(std::chrono::milliseconds(100)); // Simulate some work
    // std::cout<<"Task2 has acquired m3"<<std::endl;
    // m1.lock();
    // std::cout<<"Task2 has acquired m1"<<std::endl;
    // std::this_thread::sleep_for(std::chrono::milliseconds(100)); // Simulate some work
    // Fix for deadlock by locking mutexes in a consistent order across all threads
    // After
    m1.lock();
    std::cout<<"Task2 has acquired m1"<<std::endl;
    std::this_thread::sleep_for(std::chrono::milliseconds(100)); // Simulate some work
    m2.lock();
    std::cout<<"Task2 has acquired m2"<<std::endl;
    std::this_thread::sleep_for(std::chrono::milliseconds(100)); // Simulate some work
    m3.lock();
    std::this_thread::sleep_for(std::chrono::milliseconds(100)); // Simulate some work
    std::cout<<"Task2 has acquired m3"<<std::endl;
    std::cout<<"Task2 completed!"<<std::endl;
    m3.unlock();
    m2.unlock();
    m1.unlock();
}
void Task3(){
    // Before Deadlock causing code
    // m3.lock();
    // std::this_thread::sleep_for(std::chrono::milliseconds(100)); // Simulate some work
    // std::cout<<"Task3 has acquired m3"<<std::endl;
    // m2.lock();
    // std::cout<<"Task3 has acquired m2"<<std::endl;
    // std::this_thread::sleep_for(std::chrono::milliseconds(100)); // Simulate some work
    // m1.lock();
    // std::cout<<"Task3 has acquired m1"<<std::endl;
    // After resolving deadlock code
    m1.lock();
    std::cout<<"Task3 has acquired m1"<<std::endl;
    std::this_thread::sleep_for(std::chrono::milliseconds(100)); // Simulate some work
    m2.lock();
    std::cout<<"Task3 has acquired m2"<<std::endl;
    std::this_thread::sleep_for(std::chrono::milliseconds(100)); // Simulate some work
    m3.lock();
    std::this_thread::sleep_for(std::chrono::milliseconds(100)); // Simulate some work
    std::cout<<"Task3 has acquired m3"<<std::endl;
    std::this_thread::sleep_for(std::chrono::milliseconds(100)); // Simulate some work
    std::cout<<"Task3 completed!"<<std::endl;
    m3.unlock();
    m2.unlock();
    m1.unlock();
}

int main(){
    std::thread t1(Task1);
    std::thread t2(Task2);
    std::thread t3(Task3);
    t1.join();
    t2.join();
    t3.join();
    return 0;
}