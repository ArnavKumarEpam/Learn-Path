#include<iostream>
#include<thread>
#include<vector>

int counter = 0;

void increment(){
    for(int i = 0 ; i < 1000; i++){
        counter++;
    }
}

int main(){
    std::vector<std::thread> threads(4);
    for(int i = 0 ; i < 4 ; i++){
        threads[i] = std::thread(increment);
    }
    for(auto &it : threads){
        it.join();
    }
    std::cout<<"Final Counter Value: "<<counter<<std::endl;
}