#include<iostream>
#include<thread>
#include<atomic>

std::atomic<int> counter{0}; // signals compiler and CPU that every operation on this variable counter will be indivisible and no thread can see it half done

void increment(){
    for(int i = 0 ; i < 100000 ; i++){
        ++counter;
    }
}

int main(){
    std::thread t1(increment);
    std::thread t2(increment);
    std::thread t3(increment);
    std::thread t4(increment);

    t1.join();
    t2.join();
    t3.join();
    t4.join();

    std::cout<<"Final Counter Value: "<<counter.load()<<std::endl; // Using load() to read the atomic variable
}