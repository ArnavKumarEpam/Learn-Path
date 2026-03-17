#include<iostream>
#include<cstring>
class Buffer{
    private:
        int * data;
        size_t size;
    public:
        Buffer(size_t sz) : size(sz){
            data = new int[size];
            for(int i = 0 ; i < size;  i++) data[i] = i * 10;
            std::cout<<"Constructor Assigning memory: "<<static_cast<void*>(data)<<std::endl;
        }
        Buffer(const Buffer &other) : size(other.size){
            data = new int[size];
            std::memcpy(data, other.data, size * sizeof(int));
            std::cout<<"Copy Constructor assigning: "<<static_cast<void*>(data)<<std::endl;
        }
        Buffer& operator=(const Buffer &other){
            if(this != &other){
                delete [] data;
                size = other.size;
                std::memcpy(data, other.data, size * sizeof(int));
                std::cout<<"Copy Assignment assigning: "<<static_cast<void*>(data)<<std::endl;
            }
            return *this;
        }
        Buffer(Buffer &&other) : size(other.size), data(other.data){
            
            other.data = nullptr;
            other.size = 0;
            std::cout<<"Move Constructor assigning: "<<static_cast<void*>(data)<<std::endl;
            
        }
        Buffer & operator = (Buffer &&other){
            size = other.size;
            if(this != &other){
                delete [] data;
                data = other.data;
                other.data = nullptr;
                other.size = 0;
                std::cout<<"Move Assignment assigning: "<<static_cast<void*>(data)<<std::endl;
            }
            return *this;
        }
        ~Buffer(){
            std::cout<<"Destructor Freeing Memory: "<<static_cast<void*>(data)<<std::endl;
            delete[] data;
        }

        void print(const char * label) const {
             std::cout << label << " [data@" << static_cast<const void*>(data) << "] size=" << size << " values:";
            for (size_t i = 0; i < size; ++i) std::cout << " " << data[i];
            std::cout << std::endl;
        }


};
int main(){
    Buffer B1(5);
    B1.print("B1");
    Buffer CopyB = B1; // Copy Constructor
    Buffer CopyAssignment(4);
    CopyAssignment = B1; // Copy Assignment
    CopyB.print("Copy Constructor ");
    CopyAssignment.print("Copy Assignment");
    Buffer B2 = std::move(B1); // Move Constructor
    B2.print("B2");
    Buffer MoveAssignment(4); // Move Assignment
    MoveAssignment = std::move(CopyB);
}