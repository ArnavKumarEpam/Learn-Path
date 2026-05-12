#include<iostream>
#include<thread>
#include<mutex>

std::mutex mtx1;
std::mutex mtx2;

void Task1(){
    mtx1.lock();
    std::cout<<"Task1 is running..."<<std::endl;
    std::this_thread::sleep_for(std::chrono::milliseconds(100)); // Simulate some work
    std::cout<<"Task1 is trying to acquire mtx2..."<<std::endl;
    mtx2.lock();
    std::cout<<"Task1 acrquired mtx2..."<<std::endl;
    std::cout<<"Task1 completed!"<<std::endl;
    mtx2.unlock();
    mtx1.unlock();
}

void Task2(){
    
    mtx2.lock();
    std::cout<<"Task2 is running..."<<std::endl;
    std::this_thread::sleep_for(std::chrono::milliseconds(100)); // Simulate some work
    std::cout<<"Task2 is trying to acquire mtx1..."<<std::endl;
    mtx1.lock();
    std::cout<<"Task2 acuired mtx1..."<<std::endl;
    std::cout<<"Task2 completed!"<<std::endl;
    mtx1.unlock();
    mtx2.unlock();
}

int main(){
    std::thread t1(Task1);
    std::thread t2(Task2);
    t1.join();
    t2.join();

}