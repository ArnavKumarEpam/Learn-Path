#include<iostream>
#include<thread>
#include<mutex>
#include<optional>
#include<condition_variable>
#include<queue>

std::queue<int> buffer;
std::mutex mtx; // mutex is used to protect shared resources (like the buffer in this case) from concurrent access by multiple threads, ensuring that only one thread can access the critical section of code that modifies the shared resource at a time, preventing data corruption and ensuring thread safety.
std::condition_variable cv; // allows one thread to sleep effeciently untill another thread notifies it to wake up, which is useful for synchronizing access to shared resources between threads and avoiding busy-waiting, where a thread continuously checks for a condition to be true without sleeping, which can lead to high CPU usage and inefficient resource utilization.
bool producer_done = false;

void producer(){
    for(int i = 1 ; i <= 20 ; i++){
        std::unique_lock<std::mutex> lock(mtx);
        buffer.push(i);
        std::cout<<"Produced: "<<i<< " thread_id: "<< std::this_thread::get_id()<< std::endl;
        cv.notify_one(); // Notify the consumer that a new item is produced
    }

    {
        std::unique_lock<std::mutex> lock(mtx);
        producer_done = true;
    }
    cv.notify_one();
    std::cout<<"Producer done producing!"<<std::endl;
}

void consumer(){
    while(true){
        
        std::unique_lock<std::mutex> lock(mtx);
        
        cv.wait(lock, [](){return producer_done || !buffer.empty();}); // Wait until the producer is done producing or buffer is not empty
        while(!buffer.empty()){
            int item = buffer.front();
            buffer.pop();
            std::cout<<"Consumed: "<<item<< " thread_id: "<< std::this_thread::get_id()<< std::endl;
        }
        if(producer_done && buffer.empty()){
            break; // Exit the loop if producer is done and buffer is empty
        }
}
    std::cout<<"Consumer done consuming!"<<std::endl;
}

int main(){
    std::thread prod(producer);
    std::thread cons(consumer);

    prod.join();
    cons.join();
}