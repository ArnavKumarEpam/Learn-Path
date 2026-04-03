#include<iostream>
#include<vector>

int main(){
    std::vector<int> vec;
    // check if the vector is empty and print it
    if(vec.empty()){
        std::cout<<"The vector is empty. \n";
    }
    else{
        std::cout<<"The vector is not empty. \n";
    }
    // Adding grades
    vec.push_back(85);
    vec.push_back(90);
    vec.push_back(78);
    vec.push_back(92);
    vec.push_back(88);
    vec.push_back(95);
    // printing all the grades
    for(auto it : vec){
        std::cout<<"Grades: "<<it<<"\n";
    }
    // size of the vector
    std::cout<<"Size of the vector: "<<vec.size()<<"\n";

    // Accessing and Modifying the elements
    std::cout<<"First grade: "<<vec.front()<<"\n";
    std::cout<<"Last grade: "<<vec.back()<<"\n";

    // Modifying 2nd element using [] and .at()
    vec[2] = 100;
    std::cout<<"Element at index 2 after modification by []: "<<vec[2]<<"\n";
    vec.at(2) = 98;
    std::cout<<"Element at index 2 after modification by .at(): "<<vec.at(2)<<"\n";
    // .at() is safer than [] because it checks for out of bound errors and throws an exception if the index is invalid, while [] does not perform bounds checking and can lead to undefined behavior if accessed out of bounds.
    try{
        std::cout<<"Trying to access out of bounds index using .at(): "<<vec.at(10)<<"\n";
    }
    catch(const std::out_of_range& e){
        std::cout<<"Caught an exception: "<<e.what()<<"\n";
    }

    // Adding more grades
    vec[5] = 101; // Modifying the last element using []
    // printing all the grades
    for(auto it : vec){
        std::cout<<"Grades: "<<it<<"\n";
    }
    std::cout<<"The size of Vector after modyfing: "<<vec.size()<<"\n"; // Size remains the same as we are modifying an existing element, not adding a new one.
    
    // clearing the vector
    vec.clear();
    
    std::cout<<"The size of Vector after clearing: "<<vec.size()<<"\n";
    if(vec.empty()){
        std::cout<<"The vector is empty after clearing. \n";
    }
    else{
        std::cout<<"The vector is not empty after clearing. \n";
    }
}