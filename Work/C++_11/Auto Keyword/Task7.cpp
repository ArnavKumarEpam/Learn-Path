#include<iostream>
#include<vector>

int main(){
    std::vector<int> v = {1,2,3,4,5};
    for(const auto &it : v){
        // it *= 2; //compile time error the lvalue should be modifiable expression must be a modifiable lvalue
        std::cout<<it<<" ";

    }
    std::cout<<std::endl;
}