#include<iostream>
#include<mutex>
#include<thread>
#include<condition_variable>

int counter = 1;
std::mutex mtx;
std::condition_variable cv;

void printOdd(){
    while(counter <= 20){
        std::unique_lock<std::mutex> lock(mtx);
        cv.wait(lock, [](){ return counter % 2 != 0; }); // wait accepts lock, and a lambda function (predicate) which returns true or false.
        // So when its true it prints odd number and when its false it unlocks the mutex and allows other thread to acquire the lock and check the condition again.
        std::cout<<"Odd Number: "<<counter<<"\n";
        counter++;
        cv.notify_one();

    }
}

void printEven(){
    while(counter <= 20){
        std::unique_lock<std::mutex> lock(mtx);
        cv.wait(lock, [](){ return counter % 2 == 0; }); // When predicate return true it prints even number when not it unlocks the lock and allows other thread to acquire the lock and check the condition again.
        std::cout<<"Even Number: "<<counter<<"\n";
        counter++;
        cv.notify_one();

    }
}


int main(){
    std:: thread odd(printOdd);
    std::thread even(printEven);
    odd.join();
    even.join();

}
