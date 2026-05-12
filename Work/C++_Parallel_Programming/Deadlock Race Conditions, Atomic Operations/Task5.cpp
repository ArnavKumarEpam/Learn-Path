#include<iostream>
#include<thread>
#include<mutex>
int counter = 0;
std::mutex mtx;

void increment(){ 
    // RACE CONDITION CAUSE:
        // counter++ is not an atomic operation. It consists of 3 CPU steps:
        // 1. Load: Read value from memory into a register.
        // 2. Increment: Add 1 to the register.
        // 3. Store: Write the register value back to memory.
        // If Thread A is at step 2 while Thread B is at step 1, they both read 
        // the same value, increment it, and write the same result, losing one count.
    for(int i = 0 ; i < 100000 ; i++){
        std::lock_guard<std::mutex> lock(mtx);
        counter++;
    }
}

int main(){
     std::cout << "Initial counter value: " << counter << std::endl;
    // Thread creation
    std::thread t1(increment);
    std::thread t2(increment);
    std::thread t3(increment);
    std::thread t4(increment);
    std::thread t5(increment);
    t1.join();
    t2.join();
    t3.join();
    t4.join();
    t5.join();
    std::cout << "Final counter value expected( " << 100000 * 5 << " ), actual: " << counter << std::endl;
    return 0;
}