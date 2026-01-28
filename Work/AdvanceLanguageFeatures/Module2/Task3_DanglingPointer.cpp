#include<iostream>
using namespace std;

int *allocate(){
    int *variable = new int(10);
    return variable;
}
/* Dangling pointer is the pointer which is deleted but still has address of the variable
    by having the address it can access that memory space also if someone tries to delete it again may crash the program or corrupt the heap memory
    to resolve this issue we point the pointer to null after deletion or make smart pointers
*/

int main(){
    int *pointer = allocate();
    int *pointer2Null = allocate();
    cout<<"Value of the variable dynamically allocated variable 1: "<<*pointer<<endl;
    cout<<"Value of the variable dynamically alloted variable 2: "<<*pointer2Null<<endl;
    delete pointer2Null; // deleting the pointer
    delete pointer; // deleting the pointer
    cout<<"Value of the pointer dynamically alloted variable 2 before pointing to null: "<<*pointer2Null<<endl;
    pointer2Null = nullptr; // pointing to null
    cout<<"Value of the pointer dynamically allocated variable 1: "<<*pointer<<endl;
    cout<<"Value of the pointer dynamically alloted variable 2: "<<*pointer2Null<<endl; // return nothing as dereferencing a nullpointer gives nothing


}