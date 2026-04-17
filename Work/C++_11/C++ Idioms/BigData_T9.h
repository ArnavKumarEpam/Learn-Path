#pragma once
#include <memory>

class BigData {
public:
    BigData();
    ~BigData();

    void process();
    size_t getSize() const;
private:
    struct Impl;                // Forward declaration only!
    std::unique_ptr<Impl> impl; // No heavy includes here
};
