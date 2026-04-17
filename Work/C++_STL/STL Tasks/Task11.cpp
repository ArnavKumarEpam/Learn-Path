#include<iostream>
#include<set>

void insertValue(std::set<int> &sId){
    sId.emplace(101);
    sId.emplace(105);
    sId.emplace(103);
    sId.emplace(102);
}

void printRoster(const std::set<int> &sId, const std::string&& title){
    std::cout<<"Title: "<<title<<std::endl;
    for(const auto &value: sId){
        std::cout<<value<<" ";
    }
    std::cout<<std::endl;
}

void checkIfStudentExists(const std::set<int> &sId, int id){
    if(sId.find(id) != sId.end()){
        std::cout<<"Student with ID "<<id<<" Exists in the set! "<<std::endl;
    }
    else{
        std::cout<<"Student with ID "<<id<<" does not exist in the set! "<<std::endl;
    }
}

void removeStudents(std::set<int> &sId, int id){
    auto it = sId.erase(id);
    if(it > 0){
        std::cout<<"Student with ID "<<id<<" removed from the set! "<<std::endl;
    }
    else{
        std::cout<<"Student with ID "<<id<<" not found in the set! "<<std::endl;
    }
}

int main(){
    std::set<int> sId;
    std::cout<<"Set has been declared! Size of Set: "<<sId.size()<<std::endl;
    insertValue(sId);
    std::cout<<"Values inserted into the set! Size of Set: "<<sId.size()<<std::endl;
    auto it = sId.emplace(105); // trying to insert duplicate value int the set 
    if(it.second){
        std::cout<<"Value 105 inserted successfully! "<<std::endl;
    }
    else{
        std::cout<<"Value 105 already exists in the set! "<<std::endl;  
    }

    std::cout<<"Final Size of the Set: "<<sId.size()<<std::endl;

    printRoster(sId, "Student IDs in the set (initial roster):");

    // checking if a student exists in the set
    checkIfStudentExists(sId, 103); // existing student
    checkIfStudentExists(sId, 999); // non existing student

    // removing from the set

    removeStudents(sId, 102); // existing student
    std::cout<<"Size of the set after removing student with ID 102: "<<sId.size()<<std::endl;
    removeStudents(sId, 999); // non existing student
    std::cout<<"Size of the set after trying to remove student with ID 999: "<<sId.size()<<std::endl;

    // finally printing the roster after all the operations
    printRoster(sId, "Student IDs in the set (final roster):");
    std::cout<<"Final Size of the Set: "<<sId.size()<<std::endl;
    
}   
