#pragma once
#include <memory>
#include <string>

class Widget {
public:
    Widget();
    ~Widget();
    void setName(const std::string& name);
    void printName() const;

private:
    struct Impl;                       // Forward declaration
    std::unique_ptr<Impl> impl;        // PIMPL pointer
};
