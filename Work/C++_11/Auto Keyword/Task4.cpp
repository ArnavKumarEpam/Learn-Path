#include<iostream>
#include<vector>

int main(){
    std::vector<int> v = {2,3,5,6,3,1};
    for(auto it = v.begin(); it != v.end() ; it++){
        std::cout<<*it<<" ";
    }
    std::cout<<std::endl;
    return 0;
}