// #include<iostream>
// #include<thread>
// #include<mutex>

// using namespace std;


// int globalC = 0;
// mutex m;
// void Increment(){
//     for(int i = 0 ; i < 1000000000 ; i++){
//         m.lock();
//         globalC++;
//         m.unlock();
//     }
// }

// void dunc(int x, int y){
//     cout<<"Ehlladfa"<<endl;
// }

// int main(){
//     // thread t([](){
//     //     cout<<"Hello from thread! "<<endl;
//     // });
//     // t.join();
//     thread t(Increment);
//     thread t1(Increment);
//     thread t2(Increment);
//     t.join();
//     t1.join();
//     t2.join();
//     // cout<<thread::hardware_concurrency();
//     cout<<globalC<<endl;
// }

#include<iostream>
#include<mutex>
#include<thread> 
#include<vector>


void printMessage(const std::string&msg){ // Function to print a message along with the thread ID
    
    std::cout<<msg<< " " << std::this_thread::get_id()<<std::endl;
}

int main(){
    std::vector<std::thread> threads;
    for(int i = 0 ; i < 10 ; i++){ // Launch multiple threads with unique messages
        threads.emplace_back(printMessage, "Hello from thread ");
    }
    for(auto &it : threads){  // Join all threads before exiting
        it.join();
    }
}