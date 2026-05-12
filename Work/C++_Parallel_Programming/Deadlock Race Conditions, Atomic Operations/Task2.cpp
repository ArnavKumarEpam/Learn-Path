#include<iostream>
#include<thread>
#include<mutex>

std::mutex mtx1;
std::mutex mtx2;

void Task1(){
    std::scoped_lock lock(mtx1, mtx2); // lock both mutexes without risking deadlock by locking them in a consistent order and automatically releasing them when the lock goes out of scope
    std::cout<<"Task 1 has acuired both mtx1 and mtx2"<<std::endl;
    std::this_thread::sleep_for(std::chrono::milliseconds(100)); // Simulate some work
    std::cout<<"Task1 completed! mtx1 and mtx2 released"<<std::endl;
    
    // std::lock(mtx1, mtx2); // Lock both mutexes without risking deadlock by locking them in a consistent order
    // std::lock_guard<std::mutex> lock1(mtx1, std::adopt_lock); // Adopt the already locked mutex, in the contructor of lock_guard now it stores the address of mtx1 due to adopt_lock, it skips the calling mtx1.lock() as its already done in previous line
    // std::lock_guard<std::mutex> lock2(mtx2, std::adopt_lock); // Adopt the already locked mutex, in the contructor of lock_guard now it stores the address of mtx2 due to adopt_lock, it skips the calling mtx2.lock() as its already done in previous line
    // std::cout<<"Task1 acquired mtx1 and mtx2"<<std::endl;
    // std::this_thread::sleep_for(std::chrono::milliseconds(100)); // Simulate some work
    // std::cout<<"Task1 completed!"<<std::endl;
    
}

void Task2(){
    std::scoped_lock lock(mtx1, mtx2); // lock both mutexes without risking deadlock by locking them in a consistent order and automatically releasing them when the lock goes out of scope
    std::cout<<"Task 2 has acuired both mtx1 and mtx2"<<std::endl;
    std::this_thread::sleep_for(std::chrono::milliseconds(100)); // Simulate some work
    std::cout<<"Task2 completed! mtx1 and mtx2 released"<<std::endl;
    // std::lock(mtx1, mtx2); // Lock both mutexes without risking deadlock by locking them in a consistent order
    // std::lock_guard<std::mutex> lock1(mtx1, std::adopt_lock); // Adopt the already locked mutex, in the contructor of lock_guard now it stores the address of mtx1 due to adopt_lock, it skips the calling mtx1.lock() as its already done in previous line
    // std::lock_guard<std::mutex> lock2(mtx2, std::adopt_lock); // Adopt the already locked mutex, in the contructor of lock_guard now it stores the address of mtx2 due to adopt_lock, it skips the calling mtx2.lock() as its already done in previous line
    // std::cout<<"Task2 acquired mtx1 and mtx2"<<std::endl;
    // std::this_thread::sleep_for(std::chrono::milliseconds(100)); // Simulate some work
    // std::cout<<"Task2 completed!"<<std::endl;
    
   
}

int main(){
    std::thread t1(Task1);
    std::thread t2(Task2);
    t1.join();
    t2.join();

}