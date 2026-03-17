#include<iostream>
#include<cstring>

class ResourceHolder{
    private:
        int * data;
        int size;
    public:
        ResourceHolder(size_t sz) : size(sz){
            std::cout<<"Constructor! \n";
            data = new int[size];
            for(size_t i = 0 ; i < size; i++){
                data[i] = i * 11;
            }   
            std::cout << "Constructor: allocated at " << static_cast<void*>(data) << "\n";
        }
        ResourceHolder(ResourceHolder &other) : size(other.size){
            // std::cout<<"Copy Constructor! \n";
            data = new int[size];
            std::memcpy(data, other.data, size * sizeof(int));
            std::cout << "Copy Constructor: copied to " << static_cast<void*>(data) << "\n";
        }
        ResourceHolder& operator =(const ResourceHolder &other){
            std::cout<<"Copy Assignment! \n";
            size = other.size;
            if(this != &other){
                delete[] data;
                data = new int[size];
                std::memcpy(data, other.data, size * sizeof(int));
                std::cout << "Copy assign: copied to " << static_cast<void*>(data) << "\n";
            }   
            return *this;
        }
        ~ResourceHolder(){
            delete [] data;
        }
        void print(const char* label) const {
        std::cout << label << " data at " << static_cast<const void*>(data) << ": [ ";
        for (size_t i = 0; i < size; ++i) std::cout << data[i] << " ";
        std::cout << "]" << std::endl;
    }
};

int main(){
    ResourceHolder r1(10);
    ResourceHolder r2 = r1;
    ResourceHolder r3(10);
    r3 = r2;

    r1.print("R1");
    r2.print("R2");
    r3.print("R3");
}
