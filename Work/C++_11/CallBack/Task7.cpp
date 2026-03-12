#include<iostream>
#include<vector>
#include<algorithm>

int main(){
    std::vector<int> v = {1, 2, 3, 4, 5, 6};

    int factor = 3;

    std::cout<<"Original Vector: ";
    for(auto it : v){std::cout<<it<<" ";}
    std::cout<<std::endl;

    std::for_each(v.begin(), v.end(), [factor](int &x){
        x *= factor;
    });

    std::cout<<"Modified Vector: ";
    for(auto it : v){std::cout<<it<<" ";}
    std::cout<<std::endl;

    factor = 10;

    std::cout<<"Modified Again: ";
    std::for_each(v.begin(), v.end(), [&factor](int &x){
        factor += 2;
        x *= factor;
    });
    for(auto it : v){std::cout<<it<<" ";}
    std::cout<<std::endl;
}