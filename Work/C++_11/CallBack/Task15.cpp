#include<iostream>
#include<vector>
#include<algorithm>

/*
    Lambda Expression are used when code is simple and small
    Functors are used when we have complex code and reusability is our purpose
*/
struct Square{
    void operator()(int &x){
        x *= x;
    }
};

int main(){
    std::vector<int> v1 = {1, 2, 3, 4, 5, 6};
    std::vector<int> v2 = {1, 2, 3, 4, 5, 6};

    std::for_each(v1.begin(), v1.end(), Square());
    std::for_each(v2.begin(), v2.end(), [](int &x) {x *= x;});

    std::cout<<"Squared by Functor: ";
    for(auto it : v1) {std::cout<<it<< " ";} // Displaying vector which uses Square functor 
    std::cout<<std::endl;
    std::cout<<"Squared by Lambda: ";
    for(auto it : v2) {std::cout<<it<< " ";} // Displaying vector which uses lambda expression

    
}

