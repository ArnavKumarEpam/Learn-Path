#include<iostream>
#include<list>

void insertGrades(std::list<int> &grades){
    grades.push_back(85);
    grades.push_back(90);
    grades.push_back(78);
    grades.push_back(92);
    grades.push_back(88);
    grades.push_back(95);
}

void print(std::list<int> &grades){
    for(int grade : grades){
        std::cout<<"Grade: "<<grade<<" ";
    }
    std::cout<<std::endl;

}

int main(){
    std::list<int> grades;
    if(grades.empty()){
        std::cout<<"List is empty!"<<std::endl;
    }
    insertGrades(grades);
    print(grades);
    std::cout<<"Size of list: "<<grades.size()<<std::endl;

    // printing first and last element of the list
    std::cout<<"First grade: "<<grades.front()<<std::endl;
    std::cout<<"Last grade: "<<grades.back()<<std::endl;

    // printing third element using iterator
    auto it = grades.begin();
    std::advance(it, 2);
    std::cout<<"Third grade: "<< *it <<std::endl; 
    *it = 99; // modifying the third element
    std::cout<<"Third grade after modifying: "<< *it <<std::endl; 

    try {
    auto it_test = grades.begin();
    std::advance(it_test, 100); // Advances to end(), no exception
    if(it_test == grades.end()) {
        std::cout << "std::advance moved iterator to end() - no exception thrown!" << std::endl;
        std::cout << "Dereferencing would be UB, not an exception." << std::endl;
    }
} catch(...) {
    std::cout << "No exception caught - std::advance doesn't throw for std::list" << std::endl;
}


    // inserting a grade at the beginning of the list
    grades.push_front(80);
    auto it2 = grades.rbegin();
    grades.insert(std::prev(grades.end()), 89); // inserting before the last element using reverse iterator
    std::cout<<"List after making changes: "<<std::endl;
    print(grades);
    std::cout<<"Size of list after changes: "<<grades.size()<<std::endl;


    // Removing grades
    grades.pop_back(); // removing the last grade
    grades.erase(std::next(grades.begin(), 1)); // removing the second grade
    std::cout<<"List after removing grades: "<<std::endl;
    print(grades);
    std::cout<<"Size of list after removing grades: "<<grades.size()<<std::endl;


    // clearing the list
    grades.clear();
    std::cout<<"Size of the list after clearing: "<<grades.size()<<std::endl;
    if(grades.empty()){
        std::cout<<"List is empty after clearing!"<<std::endl;
    }



}