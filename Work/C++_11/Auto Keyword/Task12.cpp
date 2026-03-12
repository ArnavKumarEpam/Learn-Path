#include<iostream>
#include<vector>


int main(){
    std::vector<std::vector<int>> mat{{1, 2}, {3, 4}};

    for(const auto &row : mat){
        for(const auto col : row){
            std::cout<<col<<" ";
        }
        std::cout<<std::endl;
    }

}