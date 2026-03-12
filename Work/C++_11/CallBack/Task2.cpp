#include<iostream>
#include<string>
#include<functional>
void greetMorning(const std::string &name){
    std::cout<<"Good Morning, "<<name<<"!"<<std::endl;
}

void greetEvening(const std::string &name){
    std::cout<<"Good Evening, "<<name<<"!"<<std::endl;
}
int getNum(){
    return 10;
}
void invokeCallback(std::function<void(const std::string &)> callback, const std::string &name){
    callback(name);
}
void invokeCallback(void(*callback)(const std::string &), const std::string &name){
    callback(name);
}
void invokeCallback(int(*number)()){
    std::cout<<number();
}

int main(){
    invokeCallback(greetMorning, "ABC");
    invokeCallback(greetEvening, "DEF");
    invokeCallback(getNum);
}

// template <typename T, typename Func>
// void executeCallback(T a, T b, Func callback) {
//     std::cout << "Result: " << callback(a, b) << std::endl;
// }

// int main() {
//     auto add = [](auto x, auto y) { return x + y; };
//     auto sub = [](auto x, auto y){ return x - y;};
//     executeCallback(10, 20, add); // Compiler "figures out" the types
//     executeCallback(20, 10, sub);
// }