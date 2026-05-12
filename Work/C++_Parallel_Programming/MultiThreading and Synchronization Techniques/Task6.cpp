#include<iostream>
#include<thread>
#include<mutex>
#include<optional>
#include<condition_variable>

// This task explains the producer-consumer problem using condition variables in C++. The producer thread generates data and puts it into a shared buffer, while the consumer thread takes data from the buffer and processes it.
// The condition variable is used to synchronize access to the shared buffer, ensuring that the producer waits when the buffer is full and the consumer waits when the buffer is empty

std::optional<int> buffer; // Shared buffer for producer-consumer
std::mutex mtx;
std::condition_variable cv; 

void producer(){
    for(int i = 0 ; i < 10 ; i++){
        std::unique_lock<std::mutex> lock(mtx);

        cv.wait(lock, [](){ return !buffer.has_value();}); // wait till the buffer is empty, producer will wait if buffer has a value

        buffer = i;
        std::cout<<"Produced: "<<i<< " thread_id: "<< std::this_thread::get_id()<< std::endl;
        lock.unlock();
        cv.notify_one(); // Notify the consumer that a new item is produced
    }
}

void consumer(){
    for(int i = 0 ; i < 10 ; i++){
        std::unique_lock<std::mutex> lock(mtx);

        cv.wait(lock, [](){return buffer.has_value();}); // wait till the buffer has a value, consumer will wait if buffer is empty
        std::cout<<"Consumed: "<<buffer.value()<< " thread_id: "<< std::this_thread::get_id()<< std::endl;
        buffer.reset();
        lock.unlock();
        cv.notify_one(); // Notify the producer that the item has been consumed and buffer is empty
    }
}

int main(){
    std::thread prod(producer);
    std::thread cons(consumer);

    prod.join();
    cons.join();


}