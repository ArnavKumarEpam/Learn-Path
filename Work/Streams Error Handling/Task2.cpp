#include<iostream>
#include<iomanip>
#include<vector>
#include<string>


int main(){
    std::vector<std::pair<std::string, double>> list;
    list.push_back({"Apple", 30.503453});
    list.push_back({"Banana", 5.53020});

    std::cout << std::left << std::setw(10) << "Item" << std::setw(10) << "Price" << std::endl;
    std::cout<<std::fixed<<std::setprecision(2);
    for(int i = 0 ; i < list.size() ; i++){
        std::cout<< std::setw(10) << list[i].first << std::setw(10) << list[i].second << std::endl;
    }

}