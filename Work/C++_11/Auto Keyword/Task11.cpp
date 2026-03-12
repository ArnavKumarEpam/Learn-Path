#include<iostream>
#include<vector>
#include<initializer_list>

class Numbers{
   
    public:
    std::vector<int> data;
        Numbers(std::initializer_list<int> list) : data(list){};
        
};

int main(){
    Numbers N{1,2,4,5,6};
    
    std::cout<<"Numbers: ";
    for(auto it : N.data){ // auto deduces elements as integers
        std::cout<<it<<" ";
    }
}