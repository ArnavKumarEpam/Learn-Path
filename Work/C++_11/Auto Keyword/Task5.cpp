#include<iostream>
#include<vector>

int main(){
    std::vector<int> v = {2,3,1,4,5,6};
    
    std::cout<<"Range Based For Loop Output \n"; // 'it' here is copy of each element in the vector 
    for(auto it : v){
        std::cout<<it<<" "; // We cannot change the actual vector from this
    }
    std::cout<<std::endl;
    std::cout<<"Iterator Based For Loop Output \n"; // 'it' here is the iterator
    for(auto it = v.begin() ; it != v.end() ; it++){
        std::cout<<*it<<" "; // We can change the actual value of the elements of the vector
    }
    std::cout<<std::endl;
}
