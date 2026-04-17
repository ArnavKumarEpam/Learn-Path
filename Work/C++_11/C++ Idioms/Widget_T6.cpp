#include "Widget_T6.h"
#include <iostream>

// Full Impl definition hidden in .cpp
struct Widget::Impl {
    std::string name;
};

Widget::Widget() : impl(std::make_unique<Impl>()) {}

Widget::~Widget() = default;

void Widget::setName(const std::string& name) {
    impl->name = name;
}

void Widget::printName() const {
    std::cout << "Widget name: " << impl->name << std::endl;
}
