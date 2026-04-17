#include"CLaas.h"
#include<iostream>

struct CLaas::Impl{
    int data;
    Impl(int x) : data(x) {
        std::cout << "Impl Constructor! Data: " << data << std::endl;
    }
    ~Impl() {
        std::cout << "Impl Destructor! Data: " << data << std::endl;
    }
};

CLaas::CLaas(int x): pimpl(new Impl(x)){
    std::cout << "CLaas Constructor!" << std::endl;
}
CLaas::~CLaas(){
    std::cout << "CLaas Destructor!" << std::endl;
    delete pimpl;
}

void CLaas::display(){
    std::cout << "Data: " << pimpl->data << std::endl;
}