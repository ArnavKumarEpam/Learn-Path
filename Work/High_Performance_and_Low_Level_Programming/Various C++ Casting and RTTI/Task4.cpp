#include<iostream>

int main(){
    int value = 1000000;
    int * ptr = &value;
    std::cout << "Bytes of value: ";
    char* pchar = reinterpret_cast<char*>(&value);
    for (size_t i = 0; i < sizeof(int); ++i) {
        std::cout << "0x" << std::hex << (0xFF & pchar[i]) << " ";
    }
    std::cout << std::dec << std::endl;
    std::cout<<*pchar<<std::endl; // This will print the first byte of the integer value, which may not be human-readable and can lead to unexpected results if interpreted as a character.

    int a = 42;
    double* pd = reinterpret_cast<double*>(&a); // This is highly unsafe and can lead to undefined behavior since we are treating the memory of an int as if it were a double, which have different sizes and representations in memory.
    std::cout << "Trying to read int memory as double: *pd = " << *pd << std::endl; // This will likely print a meaningless double value, and can cause crashes or other erratic behavior due to the mismatch in data types and memory layout.
   
}