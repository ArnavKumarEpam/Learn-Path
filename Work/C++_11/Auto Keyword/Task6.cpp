#include<iostream>
#include<vector>

int main(){
    std::vector<int> v = {1,2,3,4,5};
    std::cout<<"Without Reference! \n";
    for(auto it : v){
        it *= 2;
    }
    std::cout<<"Displaying Vector after Modifying it (Reference)! \n";
    for(auto it : v){
        std::cout<<it<<" ";
    }
    std::cout<<std::endl;
    std::cout<<"With Reference! \n";
    for(auto &it : v){
        it *= 2;
    }
    std::cout<<"Displaying Vector after Modifying it (without Reference)! \n";
    for(auto it : v){
        std::cout<<it<<" ";
    }
    

}