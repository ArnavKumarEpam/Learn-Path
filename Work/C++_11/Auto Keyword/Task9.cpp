#include<iostream>
#include<vector>

int main(){
    std::vector<int> vec{1,2,3,4,5};
    // v{1,2,3,4} makes a vector of following elements
    // Uniform Initialization allows consistency, prevents narrowing conversions, avoids ambiguity in some cases like
    // v(), v{} first one is function second is object
    std::cout<<"Elements of the Vector: "<<std::endl;
    for(auto it : vec){
        std::cout<<it<<" ";
    }
}