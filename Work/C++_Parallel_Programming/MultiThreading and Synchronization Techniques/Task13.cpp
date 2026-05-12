#include<iostream>
#include<mutex>
#include<thread>

std::mutex mtx1;
std::mutex mtx2;

void deadlockA(){
    mtx1.lock();
    std::cout<<"Locked mtx1 in thread 1 \n";
    std::this_thread::sleep_for(std::chrono::milliseconds(100)); // Simulate some work
    std::cout<<"T1 trying to lock mtx2 \n";
    mtx2.lock();
    std::cout<<"Locked mtx2 in thread 1 \n";
    mtx2.unlock();
    mtx1.unlock();
}
void deadlockB(){
    mtx2.lock();
    std::cout<<"Locked mtx2 in thread 2 \n";
    std::this_thread::sleep_for(std::chrono::milliseconds(100)); // Simulate some work
    std::cout<<"T2 trying to lock mtx1 \n";
    mtx1.lock();
    std::cout<<"Locked mtx1 in thread 2 \n";
    mtx1.unlock();
    mtx2.unlock();  
}



void safeA(){
    std::cout<<"Trying to lock in A \n";
    // Scoped lock is a RAII lock object that locks multiple mutexes safely and unlocks then automatically when the lock goes out of scope 
    // Internally it uses lock(mtx1, mtx2) which locks both mutexes together without risking deadlock, even if another thread is trying to lock them in a different order.
    std::scoped_lock lock(mtx1, mtx2); // Lock both mutexes without risking deadlock
    std::cout<<"Locked mtx1 and mtx2 in thread 1 \n";
    std::this_thread::sleep_for(std::chrono::milliseconds(100)); // Simulate some work
    std::cout<<"Releasing locks in thread 1 \n";
}

void safeB(){
    std::cout<<"Trying to lock in B \n";
    std::scoped_lock lock(mtx1, mtx2); // Lock both mutexes without risking deadlock
    std::cout<<"Locked mtx1 and mtx2 in thread 2 \n";
    std::this_thread::sleep_for(std::chrono::milliseconds(100)); // Simulate some work
    std::cout<<"Releasing locks in thread 2 \n";
}

int main(){
    // This will works perfectly fine as both threads will acquire locks in the same order (mtx1 followed by mtx2) preventing deadlock.
    std::thread t3(safeA);
    std::thread t4(safeB);
    
    t3.join();
    t4.join();
    // Will cause deadlock as t1 locks mtx1 and waits for mtx2 but t2 locks mtx2 and waits for mtx1
    std::thread t1(deadlockA);
    std::thread t2(deadlockB);
    t1.join();
    t2.join();
}