#include<iostream>
#include<thread>
#include<vector>
#include<mutex>

int counter = 0;
std::mutex mtx;

// manual lock and unlock can lead to issues like forgetting to unlock, which can cause deadlocks if an exception occurs before the unlock is called. Using std::lock_guard ensures that the mutex is automatically released when the lock goes out of scope, even if an exception is thrown, providing a safer and more robust way to manage mutexes in C++.
// automatically releases the lock when the lock_guard<mutex> object goes out of scope, ensuring that the mutex is properly released even if an exception occurs, preventing potential deadlocks and ensuring thread safety without the risk of forgetting to unlock the mutex manually.
// unique lock is more flexible than lock_guard as it allows for deferred locking, timed locking, and manual unlocking, making it suitable for more complex synchronization scenarios where you may need to lock and unlock the mutex multiple times or conditionally. However, for simple cases where you just need to ensure that a mutex is locked and automatically released, std::lock_guard is often preferred for its simplicity and efficiency.
void increment(){
    for(int i = 0 ; i < 1000; i++){
        std::lock_guard<std::mutex> lock(mtx); // Lock the mutex for the duration of this block, ensuring that only one thread can modify the counter at a time
        counter++;
        
    }
}

int main(){
    std::vector<std::thread> threads(4);
    for(int i = 0 ; i < 4 ; i++){
        threads[i] = std::thread(increment);
    }
    for(auto &it : threads){
        it.join();
    }
    std::cout<<"Final Counter Value: "<<counter<<std::endl;
}