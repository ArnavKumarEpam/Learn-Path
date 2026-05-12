#include<iostream>
#include<thread>
#include<atomic>

volatile int volatileCounter = 0; // volatile tells the compiler that this variable can be changed by different threads and prevents certain optimizations, but it does not guarantee atomicity or thread safety.
std::atomic<int> atomicCounter{0}; // signals compiler and CPU that every operation on this variable counter will be indivisible and no thread can see it half done

void atomicIncrement(){
    for(int i = 0 ; i < 100000 ; i++){
        ++atomicCounter;
    }
}
void volatileIncrement(){
    for(int i = 0 ; i < 100000 ; i++){
        ++volatileCounter; // This is not thread-safe and can lead to race conditions
    }
}

int main(){
    std::thread t1(atomicIncrement);
    std::thread t2(atomicIncrement);
    std::thread t3(atomicIncrement);
    std::thread t4(atomicIncrement);

    t1.join();
    t2.join();
    t3.join();
    t4.join();

    std::thread tt1(volatileIncrement);
    std::thread tt2(volatileIncrement);
    std::thread tt3(volatileIncrement);
    std::thread tt4(volatileIncrement);

    tt1.join();
    tt2.join();
    tt3.join();
    tt4.join();



    std::cout<<"Final Volatile Counter Value expected 400000 actual value: "<<volatileCounter<<std::endl;
    std::cout<<"Final Atomic Counter Value expected 400000 actual value: "<<atomicCounter.load()<<std::endl; // Using load() to read the atomic variable
}