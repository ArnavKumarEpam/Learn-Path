    #include<iostream>
    #include<thread>
    #include<mutex>
    #include<vector>

    int counter = 0;
    std:: mutex mtx;

    void incrLockGuard() { // lock_guard is a simple RAII wrapper that provides automatic locking and unlocking of mutex
        // But it cannot be manually unlocked and it cannot be used be condition variable
        for (int i = 0; i < 1000; ++i) {
            std::lock_guard<std::mutex> lock(mtx);
            ++counter;
        }
    }

    void incrUniqueLock() { // unique_lock is more flexible than lock_guard as it allows both manual and automatic locking and unlocking of mutex, and it can be used with condition variables for more complex synchronization scenarios.
        for (int i = 0; i < 1000; ++i) {
            std::unique_lock<std::mutex> lock(mtx);
            ++counter;
            lock.unlock(); // Manually unlock the mutex before the end of the scope, allowing other threads to acquire the lock while this thread continues to execute
        }
    }

    int main(){
        std::vector<std::thread> threads(4);
        for (int i = 0 ; i < 4 ; i++)
        {
            /* code */
            threads[i] = std::thread(incrLockGuard);
            
        }
        for (auto &it : threads)
        {
            /* code */
            it.join();
        }
        
        std::cout<<"Final Counter Value with lock_guard: "<<counter<<std::endl;
        counter = 0; // Reset counter before starting unique_lock threads
        std::vector<std::thread> unique_threads(4);
        for (int i = 0 ; i < 4 ; i++)
        {
            /* code */
            unique_threads[i] = std::thread(incrUniqueLock);   
            
        }
        for (auto &it : unique_threads)
        {
            /* code */
            it.join();
        }
        
        std::cout<<"Final Counter Value with unique_lock: "<<counter<<std::endl;

    }
