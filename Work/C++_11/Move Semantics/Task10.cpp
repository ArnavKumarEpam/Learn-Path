#include<iostream>
#include<cstring>
class MyString{
    public:
    char * data;
        MyString(): data(nullptr){}
        MyString(const char * ref){
            int len = std::strlen(ref);
            data = new char[len + 1];
            strcpy(data, ref);
            std::cout<<"Contructor\n";
        }
        MyString(const MyString &s){
            data = new char[std::strlen(s.data) + 1];
            strcpy(data, s.data);
            std::cout<<"Copy Constructor \n";
        }
        MyString& operator =(const MyString &s){
            if(this != &s){
                delete []data;
                int len = std::strlen(s.data);
                data = new char[len + 1];
                strcpy(data, s.data);
            }
            std::cout<<"copy assignement \n";
            return *this;
        }
        MyString (MyString && other) noexcept{
            data = other.data;
            other.data = nullptr;
            std::cout<<"Move Constructor\n";
        }
        MyString & operator =(MyString &&other) noexcept{
            if(this != &other){
                delete[]data;
                data = other.data;
                other.data = nullptr;
            }
            std::cout<<"Move assignement\n";
            return *this;
        }
        ~MyString(){
            std::cout << "Destructing: " << (data ? data : "null")
                  << " at " << static_cast<const void*>(data) << std::endl;
            delete [] data;
        }
        void printAddress(const char* msg = "") const {
        std::cout << msg << " buffer@" << static_cast<const void*>(data) << std::endl;
    }
        
};
template<typename T>
void forwardToPrint(T&& str) {
    printAddress(std::forward<T>(str));
}

void printAddress(MyString&& s) {
    std::cout << "printAddress receives buffer@" << (void*)s.data << std::endl; // Direct access: s.printAddress(...)
}

int main(){
   
    MyString s1("lvalue");
    printAddress(std::move(s1));  // moves


    printAddress(MyString("rvalue"));            // Moves the temp

    std::cout << "--- Forwarding ---" << std::endl;

    forwardToPrint(MyString("temp"));            // Forwards rvalue (calls move)
    forwardToPrint(std::move(s1));       
}