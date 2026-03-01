#include<iostream>

template<typename...Args>
void process(int& x) {
    std::cout << "int lvalue: " << x << "\n";
}

void process(int&& x) {
    std::cout << "int rvalue: " << x << "\n";
}
void process(double& x) {
    std::cout << "double lvalue: " << x << "\n";
}

void process(double&& x) {
    std::cout << "double rvalue: " << x << "\n";
}

void process(const std::string& s) {
    std::cout << "string lvalue: " << s << "\n";
}

void process(std::string&& s) {
    std::cout << "string rvalue: " << s << "\n";
}

template<typename...Args>
void forwardAll(Args &&...args){
    process(std::forward<Args>(args)...);
    
}

int main(){
    int x = 10;
    forwardAll(x, 2.5, std::string("Hello"), 100); // lvalue as well as rvalue
    std::cout<<std::endl;
    forwardAll(std::string("temp"), x + 1); // rvalues
}