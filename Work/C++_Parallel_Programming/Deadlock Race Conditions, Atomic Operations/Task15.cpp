#include <iostream>
#include <thread>
#include <shared_mutex>
#include <mutex>
#include <chrono>
#include <vector>
#include <iomanip>
#include <sstream>

// Shared data
int data = 0;

// Reader-Writer mutex (C++17)
std::shared_mutex rw_mutex;

// Mutex for synchronized console output
std::mutex cout_mutex;

// Thread-safe print function with timestamp
void print(const std::string& message) {
    std::lock_guard<std::mutex> lock(cout_mutex);
    
    auto now = std::chrono::system_clock::now();
    auto ms = std::chrono::duration_cast<std::chrono::milliseconds>(
        now.time_since_epoch()
    ) % 1000;
    
    std::cout << "[" << std::setfill('0') << std::setw(3) << ms.count() << "ms] " 
              << message << std::endl;
}

void reader(int id, int iterations) {
    for (int i = 0; i < iterations; ++i) {
        // Acquire SHARED lock - multiple readers can hold this simultaneously
        std::shared_lock<std::shared_mutex> lock(rw_mutex);
        
        // Read the shared data
        int value = data;
        
        std::ostringstream oss;
        oss << "  [Reader " << id << "] reads  data = " << value 
            << " (shared lock acquired)";
        print(oss.str());
        
        // Simulate read operation
        std::this_thread::sleep_for(std::chrono::milliseconds(100));
        
        // Lock automatically released when scope ends
    }
    
    print("  [Reader " + std::to_string(id) + "] finished all reads");
}

void writer(int id, int iterations) {
    for (int i = 0; i < iterations; ++i) {
        // Acquire EXCLUSIVE lock - blocks all readers and other writers
        std::unique_lock<std::shared_mutex> lock(rw_mutex);
        
        // Modify the shared data
        data++;
        
        std::ostringstream oss;
        oss << "[Writer " << id << "] writes data = " << data 
            << " (exclusive lock acquired) *** WRITING ***";
        print(oss.str());
        
        // Simulate write operation
        std::this_thread::sleep_for(std::chrono::milliseconds(250));
        
        // Lock automatically released when scope ends
    }
    
    print("[Writer " + std::to_string(id) + "] finished all writes");
}

int main() {
    std::cout << "Reader-Writer Problem with std::shared_mutex\n" << std::endl;
    
    const int num_readers = 3;
    const int num_writers = 1;
    const int reader_iterations = 5;
    const int writer_iterations = 5;
    
    std::vector<std::thread> threads;
    
    // Launch reader threads
    for (int i = 1; i <= num_readers; ++i) {
        threads.emplace_back(reader, i, reader_iterations);
    }
    
    // Small delay to let readers start
    std::this_thread::sleep_for(std::chrono::milliseconds(50));
    
    // Launch writer thread
    for (int i = 1; i <= num_writers; ++i) {
        threads.emplace_back(writer, i, writer_iterations);
    }
    
    // Wait for all threads to complete
    for (auto& t : threads) {
        t.join();
    }
    
    std::cout << "\nAll threads completed" << std::endl;
    std::cout << "Final data value: " << data << std::endl;
    
    return 0;
}