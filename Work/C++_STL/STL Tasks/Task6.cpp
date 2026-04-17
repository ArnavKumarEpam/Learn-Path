#include<iostream>
#include<list>
#include<algorithm>

int main(){
    std::list<int> ls = {1, 2, 3, 4, 5, 2, 3, 4, 5, 6}; // list
    std::cout<<"List before removing "<<": "<<std::endl;
    for(const auto &element : ls){ // printing the list after removing the number
        std::cout<<element<<" ";
    }
    std::cout<<std::endl;
    std::cout<<"Enter the number to remove from the list: "; // prompting the user to enter a number to remove frmo the list
    int num;
    if(!(std::cin >> num)) {
    std::cerr << "Invalid input!" << std::endl;
    return 1;
    }
    else{
        ls.remove(num); // removing the number from the list using remove function of list
        std::cout<<"List after removing "<<num<<": "<<std::endl;
        for(const auto &element : ls){ // printing the list after removing the number
            std::cout<<element<<" ";
        } 
        std::cout<<std::endl;
        std::cout<<"Size of the list after removing "<<num<<": "<<ls.size()<<std::endl; // printing the size of the list after removing the number

    }

    std::cout<<"Enter the number to remove from the list: "; // prompting the user to enter a number to remove from the list
    int num2;
    if(!(std::cin >> num2)) {
    std::cerr << "Invalid input!" << std::endl;
    return 1;
    }
    else{
        auto it2 = ls.begin();
        while(it2 != ls.end()){
            if(*it2 == num2){
                it2 = ls.erase(it2);
            }
            else ++it2;
        }
        std::cout<<"List after removing "<<num2<<": "<<std::endl;
        for(const auto &element : ls){ // printing the list after removing the number
            std::cout<<element<<" ";
        }
        std::cout<<std::endl;
        std::cout<<"Size of the list after removing "<<num2<<": "<<ls.size()<<std::endl; // printing the size of the list after removing the number 
    }

    

}