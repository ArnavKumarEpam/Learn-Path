#include<iostream>
#include<vector>
#include<initializer_list>

class Numbers{
    private:
        std::vector<int> data;
    public:
        Numbers(std::initializer_list<int> list) : data(list){};
        void print() const{
            std::cout<<"Numbers: ";
            for(auto it : data){
                std::cout<<it<<" ";
            }
        }
};

int main(){
    Numbers N{1,2,4,5,6};
    N.print();
}