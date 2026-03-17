#include<iostream>
#include<cstring>
#include<vector>

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

int main(){
    std::vector<MyString> vec;
    vec.reserve(10);
    MyString a("first");
    MyString b("second");

    std::cout << "\n-- push_back(a) (copy): --" << std::endl;
    vec.push_back(a);         // Calls copy constructor

    std::cout << "\n-- push_back(std::move(b)) (move): --" << std::endl;
    vec.push_back(std::move(b)); // Calls move constructor

    std::cout << "\n-- emplace_back(\"temp\"): --" << std::endl;
    vec.emplace_back("temp"); // Constructs in-place (calls direct constructor)

    std::cout << "\n-- End of main (destructors fire) --" << std::endl;
    return 0;
    // vec.push_back(a);
    // // vec.push_back(std::move(b));
    // vec.push_back(c);
    // vec.emplace_back("HERLL");
    // vec.push_back("SBI"); // MyString (SBI) constructor then move to vec as "SBI is rvalue"
    // vec.emplace_back("SBI"); // Directly constructs in buffer of vec
    // The main difference between emplace and push 
    // push_back with string literal
    // vec.push_back("third");
    // Step 1: MyString temp("third")  ← Constructor    (temp object)
    // Step 2: Move temp into vec       ← Move Constructor
    // 2 operations!

    // emplace_back with string literal  
    // vec.emplace_back("third");
    // Step 1: Constructs "third" DIRECTLY inside vec's buffer
    // 1 operation!  No temp, no move
        
}