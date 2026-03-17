#include<iostream>
#include<cstring>
class MyString{
    private:
        char *ptr;
    public:
        MyString(const char * ref){
            int len = std::strlen(ref);
            ptr = new char[len + 1];
            strcpy(ptr, ref);
        }
        MyString(const MyString &st){
            int len = std::strlen(st.ptr);
            ptr = new char[len + 1];
            strcpy(ptr, st.ptr);
           
        }
       
        ~MyString(){
            delete []ptr;
        }
       
        void print() const {
            std::cout << "String: " << ptr << " (at: " << static_cast<const void*>(ptr) << ")\n";
        }

};

int main(){
    MyString myString("Hello");
    myString.print();
    MyString mst = myString;
    mst.print();
    
    
}