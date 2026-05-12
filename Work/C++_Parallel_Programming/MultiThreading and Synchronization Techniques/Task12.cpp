#include<iostream>
#include<mutex>
#include<thread>
#include<vector>
#include<algorithm>
#include <numeric>

std::vector<int> nums;
std::vector<int> ans;
std::mutex mtx;
void worker(int start, int end){
    std::unique_lock<std::mutex> lock(mtx);
    int sum = 0;
    for(int i = start; i < end; i++){
        sum += nums[i];
    }
    ans.push_back(sum);
    lock.unlock();
    std::cout<<"Partial Sum for Thread ID: "<<std::this_thread::get_id()<<", Sum: "<<sum<<std::endl;
}

int main(){
    nums = {1,2,3,4,5,6,7,8,9,10};
    std::thread t1(worker, 0, 2);
    std::thread t2(worker, 2, 4);
    std::thread t3(worker, 4, 6);
    std::thread t4(worker, 6, 8);
    std::thread t5(worker, 8, 10);

    t1.join();
    t2.join();
    t3.join();
    t4.join();
    t5.join();

    int sum = std::accumulate(ans.begin(), ans.end(), 0);
    std::cout << "Total Sum accumulated from all the threads: " << sum << std::endl;
}