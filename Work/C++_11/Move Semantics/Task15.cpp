#include<iostream>
#include<vector>
#include<string>
#include<memory>

class ModernResource{
    public:
        std::vector<int> data;
        std::string name;
        std::shared_ptr<int> meta;

        ModernResource(std::string n, std::initializer_list<int> d) : data(d), name(std::move(n)), meta(std::make_shared<int>(123)){}

        void print(const char * tag){
            std::cout<<tag<<" "<<name<<":";
            for(int x : data) std::cout<<" "<< x;
            std::cout<<" | Meta = "<<*meta<<std::endl;
        }

};

int main(){
    ModernResource m1("first", {1,2,3,4,5,6});
    ModernResource m2 = m1; // copy constructor
    ModernResource m3("Third", {7, 8, 9});
    m3.print("m3: ");
    m3 = std::move(m1);
    std::cout<<"After Move\n";
    m3.print("m3: ");
    m2.print("m2: ");
    m1.print("m1: ");

}