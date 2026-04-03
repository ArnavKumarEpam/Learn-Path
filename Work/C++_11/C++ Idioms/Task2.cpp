#include<iostream>
#include<stdexcept>

class IntArray{
    int * data;
    size_t size;
    public:
        IntArray(size_t size) : size(size), data(new int[size]){
            std::cout << "Allocated array of size " << size << " at " << static_cast<void*>(data) << std::endl;
            for (size_t i = 0; i < size; ++i) data[i] = static_cast<int>(i * 10);
        }
        ~IntArray(){
            std::cout<<"Destructor called freeing array at "<<static_cast<void*> (data)<<std::endl;
            delete[] data;
        }
        int &operator[] (size_t index){
            return data[index];
        }
        size_t getSize()const {return size;}
};

void TestEarlyReturn(){
    IntArray arr(5);
    arr[0] = 42;
    std::cout<<"testEarlyReturn data[0]: "<<arr[0]<<std::endl;
    return;
}

void TestException(){
    IntArray arr(5);
    throw std::runtime_error("Oops! Exception Triggered \n");
}

int main(){
    try{
        IntArray arr(5);
        std::cout<<"Normal usage arr[1]: "<<arr[1]<<std::endl;
    }
    catch(...){}
    std::cout<<"Testing early return\n";
    TestEarlyReturn();
    
    try{
        std::cout<<"Testing exception handling\n";
        TestException();
    }
    catch(const std::exception &e){
        std::cerr<<"Caught exception: "<<e.what()<<std::endl;
    }
}