#include<iostream>
#include<vector>
#include<string>
#include<algorithm>

int main(){
    // declaring vector of string names 
    std::vector<std::string> names = {"Alice", "Bob", "Charlie", "Diana", "Eve"};

    // displaying the names in the vector
    std::cout<<"Names in the vector: "<<std::endl;
    for(const auto &name : names){
        std::cout<<name<<" ";
    }
    std::cout<<std::endl;

    // removing an element from the vector
    auto iterator = std::find(names.begin(), names.end(), "Charlie"); // finding the element to remove
    if(iterator != names.end()){
        names.erase(iterator); // removing the element
        std::cout<<"Charlie removed from the vector."<<std::endl;
    }
    else std::cout<<"Charlie not found in the vector."<<std::endl;

    std::cout<<"Names after removing Charlie: "<<std::endl;
    for(const auto &name : names){
        std::cout<<name<<" ";
    }
    std::cout<<std::endl;

    // finding an element in the vector
    auto it = std::find(names.begin(), names.end(), "Eve");
    if(it != names.end()){ // checking if the element is found or not
        std::cout<<"Eve found in the vector."<<std::endl;
    } else {
        std::cout<<"Eve not found in the vector."<<std::endl;
    }

    // Sorting the vector
    sort(names.begin(), names.end());

    // displaying the names after sorting
    std::cout<<"Names after sorting: "<<std::endl;
    for(const auto &name : names){
        std::cout<<name<<" ";
    }
    std::cout<<std::endl;

    // clearing the vector
    names.clear();
    if(names.empty()){
        std::cout<<"Vector is empty after clearing! "<<std::endl;
    }


}