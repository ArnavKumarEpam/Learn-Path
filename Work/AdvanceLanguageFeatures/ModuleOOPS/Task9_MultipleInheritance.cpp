#include<iostream>

class Printable{
    public:
    virtual void print() const = 0;
};

class Savable{
    public:
    virtual void save() const = 0;
};

class Document : public Printable, public Savable{
    public:
    void print() const{
        std::cout<<"Document printing! "<<std::endl;
    }
    void save() const{
        std::cout<<"Document Saving! "<<std::endl;
    }
};

int main(){
    Printable *printable = new Document();
    Savable *savable = new Document();
    std::cout<<"Pointer of Printable! "<<std::endl;
    printable -> print();
    std::cout<<"Pointer of Savable! "<<std::endl;
    savable -> save();
    return 0;
}