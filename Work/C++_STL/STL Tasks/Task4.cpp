#include<iostream>
#include<list>
#include<string>
#include<algorithm>

int main(){
    std::list<std::string> Warehouse1 = {"A100", "A200", "A300"}; 
    std::list<std::string> Warehouse2 = {"A150", "A250", "A350"};


    std::cout<<"Lists before merging: "<<std::endl;
    std::cout<<"Warehouse 1: "<<std::endl;
    for(const auto &item : Warehouse1){
        std::cout<<item<<" ";
    }
    std::cout<<std::endl;
    std::cout<<"Warehouse 2: "<<std::endl;
    for(const auto &item : Warehouse2){
        std::cout<<item<<" ";
    }
    std::cout<<std::endl;
    Warehouse1.sort(); // sorting before merging as it checks at each index which comes first after merging
    Warehouse2.sort(); // merging requires sorted lists
    Warehouse1.merge(Warehouse2);
    std::cout<<"Merged Warehouse: "<<std::endl;
    for(const auto &item : Warehouse1){
        std::cout<<item<<" ";
    }
    std::cout<<std::endl;


}