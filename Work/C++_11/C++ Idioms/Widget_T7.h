#pragma once
#include <memory>
#include <string>

class Widget {
public:
    Widget();
    ~Widget();

    void setName(const std::string &name);
    void printData() const;

private:
    struct Impl;
    std::unique_ptr<Impl> impl;
};
