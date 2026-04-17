#include<iostream>
#include<vector>

int main(){
    std::vector<int> vec; // declaring an empty vector of integers
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

    // Accessing 2nd element using [] and .at()
    
    std::cout<<"Element at index 2 by []: "<<vec[2]<<"\n";
    std::cout<<"Element at index 2 by .at(): "<<vec.at(2)<<"\n";
    // .at() is safer than [] because it checks for out of bound errors and throws an exception if the index is invalid, while [] does not perform bounds checking and can lead to undefined behavior if accessed out of bounds.
    try{
        std::cout<<"Trying to access out of bounds index using .at(): "<<vec.at(10)<<"\n";
    }
    catch(const std::out_of_range& e){
        std::cout<<"Caught an exception: "<<e.what()<<"\n";
    }

    // Adding more grades
    vec.insert(vec.begin(), 10001); // Insert at the beginning
    vec.insert(vec.end() - 1, 10002); // Insert at the second last position
    // printing all the grades
    for(auto it : vec){
        std::cout<<"Grades: "<<it<<"\n";
    }
    std::cout<<"The size of Vector after modyfing: "<<vec.size()<<"\n"; // Size remains the same as we are modifying an existing element, not adding a new one.
    
    // Popping ELements
    vec.pop_back(); // removes the last element
    vec.erase(vec.begin() + 1); // removes the second element
    // printing all the grades
    for(auto it : vec){
        std::cout<<"Grades: "<<it<<"\n";
    }
    std::cout<<"The size of Vector after modyfing: "<<vec.size()<<"\n";


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