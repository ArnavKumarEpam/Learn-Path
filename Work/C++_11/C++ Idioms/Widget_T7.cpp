#include "Widget_T7.h"
#include <iostream>
#include <cstring>

// Full definition hidden in source
struct Widget::Impl {
    std::string name;
    char *buffer;
    Impl() : buffer(new char[100]) {
        std::cout << "[Impl] Allocated buffer at " << static_cast<void*>(buffer) << std::endl;
    }
    ~Impl() {
        std::cout << "[Impl] Deleting buffer at " << static_cast<void*>(buffer) << std::endl;
        delete[] buffer;
    }
};

Widget::Widget() : impl(std::make_unique<Impl>()) {}

Widget::~Widget() = default;

void Widget::setName(const std::string &name) {
    impl->name = name;
    std::strncpy(impl->buffer, name.c_str(), 99);
    impl->buffer[99] = '\0'; // Ensure null termination
}

void Widget::printData() const {
    std::cout << "Widget name: " << impl->name << ", buffer: " << impl->buffer << std::endl;
}
