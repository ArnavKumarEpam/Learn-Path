#include <iostream>
#include <thread>
#include <semaphore>
#include <chrono>
#include <mutex>

// Counting semaphore with initial count of 2
// Allows maximum 2 threads to access the resource simultaneously
std::counting_semaphore<2> sem{2};

// Mutex for synchronized console output (prevents interleaved messages)
std::mutex cout_mutex;

// Thread-safe print function
void print(const std::string& message) {
    std::lock_guard<std::mutex> lock(cout_mutex);
    std::cout << message << std::endl;
}

void Worker(int id) {
    // Phase 1: Waiting to acquire semaphore
    print("Thread " + std::to_string(id) + " is WAITING for semaphore...");
    
    // Phase 2: Acquire semaphore (blocks if counter = 0)
    sem.acquire();
    print("Thread " + std::to_string(id) + " has ACQUIRED the semaphore (entered critical section)");
    
    // Phase 3: Working with the resource
    {
        print("Thread " + std::to_string(id) + " is WORKING on the resource...");
        std::this_thread::sleep_for(std::chrono::seconds(2));
        print("Thread " + std::to_string(id) + " finished work");
    }
    
    // Phase 4: Exiting critical section
    print("Thread " + std::to_string(id) + " is EXITING critical section");
    
    // Phase 5: Release semaphore (increments counter, wakes up waiting threads)
    sem.release();
    print("Thread " + std::to_string(id) + " has RELEASED the semaphore");
}

int main() {
    std::cout << "Counting Semaphore Demo\n";
    std::cout << "Semaphore initialized with count = 2\n";
    std::cout << "Maximum 2 threads can work concurrently\n";
    std::cout << "Starting 5 threads...\n" << std::endl;
    
    // Create 5 threads competing for 2 semaphore slots
    std::thread t1(Worker, 1);
    std::thread t2(Worker, 2);
    std::thread t3(Worker, 3);
    std::thread t4(Worker, 4);
    std::thread t5(Worker, 5);
    
    // Wait for all threads to complete
    t1.join();
    t2.join();
    t3.join();
    t4.join();
    t5.join();
    
    std::cout << "\nAll threads completed" << std::endl;
    
    return 0;
}