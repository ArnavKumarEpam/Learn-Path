#include <iostream>
#include <mutex>
#include <shared_mutex>
#include <thread>
#include <chrono>

std::string sharedData = "Start";

// shared_mutex allows multiple readers or one writer
std::shared_mutex rw_mutex;

// Mutex for synchronized console output
std::mutex cout_mutex;

// Thread-safe print
void print(const std::string& message) {
    std::lock_guard<std::mutex> lock(cout_mutex);
    std::cout << message << std::endl;
}

// Writer: Acquires exclusive lock
void writer(int id) {
    // unique_lock for writing - blocks all readers and other writers
    std::unique_lock<std::shared_mutex> lock(rw_mutex);
    
    print("[Writer " + std::to_string(id) + "] writing...");
    
    for (int i = 0; i < 5; ++i) {
        sharedData += "W";
    }
    
    std::this_thread::sleep_for(std::chrono::milliseconds(100));
    
    print("[Writer " + std::to_string(id) + "] done, data = \"" + sharedData + "\"");
}

// Reader: Acquires shared lock
void reader(int id) {
    // shared_lock for reading - allows multiple readers concurrently
    std::shared_lock<std::shared_mutex> lock(rw_mutex);
    
    print("  [Reader " + std::to_string(id) + "] reading data = \"" + sharedData + "\"");
    
    std::this_thread::sleep_for(std::chrono::milliseconds(100));
}

int main() {
    std::cout << "Reader-Writer Pattern Demo\n" << std::endl;
    
    // Start writer and readers
    std::thread w(writer, 1);
    std::thread r1(reader, 1);
    std::thread r2(reader, 2);
    std::thread r3(reader, 3);
    std::thread r4(reader, 4);
    
    w.join();
    r1.join();
    r2.join();
    r3.join();
    r4.join();
    
    std::cout << "\nAll threads completed" << std::endl;
    std::cout << "Final data: \"" << sharedData << "\"" << std::endl;
    
    return 0;
}