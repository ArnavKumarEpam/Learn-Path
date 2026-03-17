#include<iostream>
#include<cstring>

class MyString{
    char * data;
    public:
        MyString(const char * ref){
            int len = std::strlen(ref);
            data = new char[len + 1];
            strcpy(data, ref);
        }
        MyString(const MyString &s){
            data = new char[std::strlen(s.data) + 1];
            strcpy(data, s.data);
        }
        MyString&operator=(const MyString &s){
            if(this != &s){
                delete[] data;
                data = new char[std::strlen(s.data) + 1];
                strcpy(data, s.data);
            }
            return *this;
        }
        MyString(MyString &&s){
            data = new char[std::strlen(s.data) + 1];
            strcpy(data, s.data);
            s.data = nullptr;
        }
        MyString&operator=( MyString &&s){
            if(this != &s){
                delete[] data;
                data = new char[std::strlen(s.data) + 1];
                strcpy(data, s.data);
                s.data = nullptr;
            }
            return *this;
        }
        ~MyString(){
            delete [] data;
        }
        void print(const char* label) const {
        std::cout << label << " [data@" << static_cast<const void*>(data)
                  << "] " << (data ? data : "null") << std::endl;
    }
    void safeReset(const char* str) {
        delete[] data;
        data = new char[std::strlen(str) + 1];
        std::strcpy(data, str);
    }

};

int main(){
    MyString S1("Hello");
    MyString S3 = std::move(S1); // Move constructor

    S3.print("S3 moved from S1");
    S1.print("S1 after move");

    S1.safeReset("New String");
    S1.print("S1 after reset");
    
}