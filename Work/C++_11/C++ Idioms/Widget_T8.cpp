#include "Widget_T8.h"
#include <iostream>
#include <cstring>

// Impl definition
struct Widget::Impl {
    std::string name;
    char* buffer;

    Impl() : buffer(new char[100]) {
        std::cout << "[Impl] Allocated buffer at " << static_cast<void*>(buffer) << std::endl;
    }
    Impl(const Impl& other) : name(other.name), buffer(new char[100]) {
        std::cout << "[Impl] Copy ctor, buffer at " << static_cast<void*>(buffer) << std::endl;
        std::strcpy(buffer, other.buffer);
    }
    Impl& operator=(const Impl& other) {
        if (this != &other) {
            name = other.name;
            std::strcpy(buffer, other.buffer);
        }
        return *this;
    }
    ~Impl() {
        std::cout << "[Impl] Deleting buffer at " << static_cast<void*>(buffer) << std::endl;
        delete[] buffer;
    }
};

// Widget implementations
Widget::Widget() : impl(std::make_unique<Impl>()) {}

Widget::~Widget() = default;

// Copy constructor (deep copy)
Widget::Widget(const Widget& other)
    : impl(std::make_unique<Impl>(*other.impl)) {}

// Copy assignment (deep copy)
Widget& Widget::operator=(const Widget& other) {
    if (this != &other) {
        *impl = *other.impl;
    }
    return *this;
}

// Move constructor
Widget::Widget(Widget&& other) noexcept
    : impl(std::move(other.impl)) {}

// Move assignment
Widget& Widget::operator=(Widget&& other) noexcept {
    if (this != &other) {
        impl = std::move(other.impl);
    }
    return *this;
}

void Widget::setName(const std::string& name) {
    impl->name = name;
    std::strncpy(impl->buffer, name.c_str(), 99);
    impl->buffer[99] = '\0';
}

void Widget::printData() const {
    std::cout << "Widget name: " << impl->name << ", buffer: " << impl->buffer << std::endl;
}
