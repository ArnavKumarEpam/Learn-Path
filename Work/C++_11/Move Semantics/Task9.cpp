#include<iostream>
#include<cstring>
class MyString{
    char * data;
    public:
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
        void print(const char * label){
            std::cout<<label<< " String: " << data <<" at Address: "<<static_cast<void*>(data)<<std::endl;
        }
        
};
MyString makeString(){
            MyString temp("Temporary");
            return temp;
}

int main(){
   
    MyString s = makeString();
    s.print("s: ");

}