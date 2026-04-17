#include <iostream>
#include <memory>

class Widget {
public:
    Widget() { std::cout << "Widget constructed at " << this << std::endl; }
    ~Widget() { std::cout << "Widget destructed at " << this << std::endl; }
    void greet() const { std::cout << "Hello from Widget at " << this << std::endl; }
};
std::unique_ptr<Widget> makeWidget(){
    auto ptr = std::make_unique<Widget>();
    ptr -> greet();
    return ptr;
}

int main(){
    std::cout<<"Smart Pointer Example \n";
    {
        auto ptr = makeWidget();
        ptr -> greet();
    }
    std::cout<<"Raw pointer example \n";
    {
        Widget *wPtr = new Widget();
        wPtr -> greet();
        delete wPtr; // Manually deleting the raw pointer to avoid memory leak, if this line is skipped then there will be memory leak
    }
    std::cout<<"End of main function \n";
}