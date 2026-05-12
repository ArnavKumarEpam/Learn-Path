#include <iostream>
#include <thread>
#include <vector>
#include <queue>
#include <functional>
#include <mutex>
#include <condition_variable>
#include <chrono>
#include <string>

class ThreadPool {
private:
    // Worker threads
    std::vector<std::thread> workers;
    
    // Task queue (stores callable objects)
    std::queue<std::function<void()>> tasks;
    
    // Synchronization primitives
    std::mutex queue_mutex;              // Protects the task queue
    std::condition_variable condition;   // Notifies workers about new tasks
    
    // Shutdown flag
    bool stop;

public:
    // Constructor: Launch 'num_threads' worker threads
    ThreadPool(size_t num_threads) : stop(false) {
        std::cout << "Creating ThreadPool with " << num_threads << " workers\n" << std::endl;
        
        // Launch worker threads
        for (size_t i = 0; i < num_threads; ++i) {
            workers.emplace_back([this, i] {
                worker_thread(i);
            });
        }
    }

    // Destructor: Clean shutdown
    ~ThreadPool() {
        std::cout << "Shutting down ThreadPool..." << std::endl;
        
        {
            std::unique_lock<std::mutex> lock(queue_mutex);
            stop = true;  // Signal all threads to stop
        }
        
        condition.notify_all();  // Wake up all waiting threads
        
        // Wait for all threads to finish
        for (std::thread& worker : workers) {
            if (worker.joinable()) {
                worker.join();
            }
        }
        
        std::cout << "ThreadPool shutdown complete" << std::endl;
    }

    // Submit a task to the pool
    template<typename F>
    void submit(F&& task) {
        {
            std::unique_lock<std::mutex> lock(queue_mutex);
            
            // Don't accept new tasks after stopping
            if (stop) {
                throw std::runtime_error("Cannot submit task to stopped ThreadPool");
            }
            
            // Add task to queue
            tasks.emplace(std::forward<F>(task));
        }
        
        // Notify one waiting worker
        condition.notify_one();
    }

private:
    // Worker thread function
    void worker_thread(size_t id) {
        std::cout << "Worker " << id << " started" << std::endl;
        
        while (true) {
            std::function<void()> task;
            
            {
                std::unique_lock<std::mutex> lock(queue_mutex);
                
                // Wait until there's a task or stop signal
                condition.wait(lock, [this] {
                    return stop || !tasks.empty();
                });
                
                // Exit if stopping and no tasks remain
                if (stop && tasks.empty()) {
                    std::cout << "Worker " << id << " exiting" << std::endl;
                    return;
                }
                
                // Get task from queue
                task = std::move(tasks.front());
                tasks.pop();
            }
            
            // Execute task outside the lock
            std::cout << "Worker " << id << " executing task" << std::endl;
            task();
            std::cout << "Worker " << id << " completed task" << std::endl;
        }
    }
};


void simple_task(int id) {
    std::cout << "  [Task " << id << "] Running simple task" << std::endl;
    std::this_thread::sleep_for(std::chrono::milliseconds(500));
    std::cout << "  [Task " << id << "] Simple task done" << std::endl;
}

void computation_task(int a, int b) {
    std::cout << "  [Computation] Computing " << a << " + " << b << std::endl;
    std::this_thread::sleep_for(std::chrono::milliseconds(300));
    std::cout << "  [Computation] Result: " << (a + b) << std::endl;
}

void heavy_task(const std::string& name) {
    std::cout << "  [Heavy Task: " << name << "] Starting heavy computation..." << std::endl;
    std::this_thread::sleep_for(std::chrono::seconds(1));
    std::cout << "  [Heavy Task: " << name << "] Completed!" << std::endl;
}


int main() {
    std::cout << "Thread Pool Demo" << std::endl;
    std::cout << "Main thread ID: " << std::this_thread::get_id() << "\n" << std::endl;
    
    {
        // Create thread pool with 3 workers
        ThreadPool pool(3);
        
        std::cout << "Submitting tasks" << std::endl;
        
        // Submit various tasks
        pool.submit([] {
            simple_task(1);
        });
        
        pool.submit([] {
            simple_task(2);
        });
        
        pool.submit([] {
            computation_task(10, 20);
        });
        
        pool.submit([] {
            heavy_task("Alpha");
        });
        
        pool.submit([] {
            heavy_task("Beta");
        });
        
        pool.submit([] {
            computation_task(100, 200);
        });
        
        pool.submit([] {
            std::cout << "  [Lambda Task] Quick lambda execution" << std::endl;
        });
        
        // Let tasks run for a bit
        std::this_thread::sleep_for(std::chrono::seconds(3));
        
        std::cout << "Main thread continues working" << std::endl;
        std::this_thread::sleep_for(std::chrono::milliseconds(500));
        
        // Pool destructor called here (RAII cleanup)
    }
    
    std::cout << "All tasks completed" << std::endl;
    
    return 0;
}