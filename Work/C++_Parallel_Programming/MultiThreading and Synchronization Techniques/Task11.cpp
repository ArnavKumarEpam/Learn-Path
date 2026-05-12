#include<iostream>
#include<shared_mutex>
#include<thread>
#include <mutex>


int sharedValue = 0;
std::shared_mutex mtx;

void reader(){
    for(int i = 0 ; i < 5 ; i++){
        std::shared_lock<std::shared_mutex> lock(mtx);
        std::cout<<"Reader Thread ID: "<<std::this_thread::get_id()<<", Shared Value: "<<sharedValue<<std::endl;
        std::this_thread::sleep_for(std::chrono::milliseconds(100)); // Simulate some work
    }
}

void writer(){
    for(int i = 0 ; i < 5 ; i++){
        std::unique_lock<std::shared_mutex> lock(mtx);
        sharedValue++;
        std::cout<<"Writer Thread ID: "<<std::this_thread::get_id()<<", Shared Value: "<<sharedValue<<std::endl;
        std::this_thread::sleep_for(std::chrono::milliseconds(100)); // Simulate some work
    }
}

int main(){
    std::thread t1(reader);
    std::thread t2(reader);
    std::thread t3(reader);
    std::thread t4(reader);
    std::thread t5(writer);
    std::thread t6(reader);
    t1.join();
    t2.join();
    t3.join();
    t4.join();
    t5.join();
    t6.join();

}