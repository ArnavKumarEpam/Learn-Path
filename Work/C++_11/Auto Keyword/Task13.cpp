#include<iostream>
#include<vector>

std::vector<int> getNumbers(){
    return {7, 14, 21, 28, 35};
}

int main(){
    auto nums = getNumbers();
    std::cout<<"Returned Numbers: ";
    for(const auto &it : nums){
        std::cout<<it<<" ";
    }
}