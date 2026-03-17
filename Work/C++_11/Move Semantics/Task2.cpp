// #include<iostream>

// class MyClass{
//     int *ptr;
//     int size;
//     public:
//         MyClass(){}
//         MyClass(int * ref, int size){
//             ptr = new int[size];
//             this->size = size;
//             for(int i = 0 ; i < size ; i++){
//                 ptr[i] = ref[i];
//             }
//         }
//         MyClass& operator = (int * ref){
//             if(ptr == nullptr) delete[] ptr;
//             ptr = new int[size];
//             for(int i = 0 ; i < size ; i++){
//                 ptr[i] = ref[i];
//             }
//             return *this;
//         }

//         void print(){
//             for(int i = 0 ; i < size ; i++){
//                 std::cout<<ptr[i]<<" ";
//             }
//         }
// };

// int main(){
//     int arr[5] = {1, 2, 3, 5, 6};
//     MyClass m(arr, 5);
//     MyClass C;
//     C = arr;
//     m.print();
//     std::cout<<std::endl;
//     C.print();


// }


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
        }
        MyString(const MyString &s){
            data = new char[std::strlen(s.data) + 1];
            strcpy(data, s.data);
        }
        MyString& operator =(const MyString &s){
            if(this != &s){
                delete []data;
                int len = std::strlen(s.data);
                data = new char[len + 1];
                strcpy(data, s.data);
            }
           
            return *this;
        }
        ~MyString(){
            delete [] data;
        }
        void print(const char * label){
            std::cout<<label<< " String: " << data <<" at Address: "<<static_cast<void*>(data)<<std::endl;
        }
};

int main(){
    MyString myString("HEllo");
    myString.print("myString");
    MyString copiedString;
    copiedString = myString;
    copiedString.print("Copy=");
    MyString c2 (myString);
    c2.print("CopyConstructor");
}