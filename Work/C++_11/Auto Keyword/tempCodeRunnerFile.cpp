#include<iostream>
#include<vector>

int main(){
    std::vector<int> vec{1,2,3,4,5};
    std::cout<<"Elements of the Vector: "<<std::endl;
    for(auto it : vec){
        std::cout<<it<<" ";
    }
}