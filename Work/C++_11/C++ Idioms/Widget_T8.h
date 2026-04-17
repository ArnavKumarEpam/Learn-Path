#pragma once
#include <memory>
#include <string>

class Widget {
public:
    Widget();
    ~Widget();

    // Rule of 5 for PIMPL
    Widget(const Widget& other);            // Copy ctor
    Widget& operator=(const Widget& other); // Copy assign
    Widget(Widget&& other) noexcept;        // Move ctor
    Widget& operator=(Widget&& other) noexcept; // Move assign

    void setName(const std::string& name);
    void printData() const;

private:
    struct Impl;
    std::unique_ptr<Impl> impl;
};
