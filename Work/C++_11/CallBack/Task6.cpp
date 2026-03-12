#include<iostream>
#include<vector>
#include<algorithm>

int main(){
    std::vector<int> v = {1, 2, 3, 4, 5, 6};
    std::for_each(v.begin(), v.end(), [](int &x){
        x *= 2;
    });
    std::cout<<"Modified Vector: ";
    for(auto it : v){
        std::cout<< it<<" ";
    }
    std::cout<<"\n";
    
    
    

}