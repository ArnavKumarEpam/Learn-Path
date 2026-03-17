#include<iostream>
#include<vector>
#include<cstring>
class Wrapper{
    public:
        // By using classes like vector and string we dont need to make custom copy and move constructors and assignment operators as they are already implemented in these classes
        std::vector<int>data;
        std::string label;
        Wrapper(std::string s, std::initializer_list<int> list) : data(list), label(std::move(s)){}
        void print(const char* tag) const {
        std::cout << tag << " label: " << label << " data: ";
        for (auto x : data) std::cout << x << " ";
        std::cout << " [data@" << static_cast<const void*>(data.data()) << "]" << std::endl;
    }
};

int main(){
    Wrapper W1("first", {1, 2, 3, 4, 5, 6});
    W1.print("W1");

    Wrapper copyW = W1;
    copyW.label = "Copy";
    copyW.print("Copy");

    Wrapper MoveW = std::move(W1);
    MoveW.label = "Move";
    MoveW.print("Move");
    std::cout<<"W1 After Move operation \n";
    W1.print("W1"); // Empty 
}