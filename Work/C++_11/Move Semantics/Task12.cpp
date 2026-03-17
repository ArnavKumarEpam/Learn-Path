#include<iostream>
#include<vector>
#include<chrono>
#include<utility>

class LargeArray{
    std::vector<int> data;
    public:
        LargeArray(size_t n) : data(n, 42){
            std::cout<<"Constructed LargeArray of size "<<n<<" at "<<static_cast<void*>(data.data())<<std::endl;
        }
        LargeArray(const LargeArray &other) : data(other.data){
            std::cout<<"Copied LargeArray (deep copy)"<<std::endl;
        }
        LargeArray(LargeArray &&other) noexcept : data(std::move(other.data)) { // if use const then it will secretly call copy constructor secretly move will be called and then copy will be called
            std::cout<<"Moved LargeArray (Move)"<<std::endl;
        }


};

int main() {
    const size_t N = 10'000'000;
    LargeArray arr1(N);

    auto start = std::chrono::high_resolution_clock::now();
    LargeArray arr2 = arr1; // Copy
    auto end = std::chrono::high_resolution_clock::now();
    std::cout << "Copy time: "
              << std::chrono::duration<double, std::milli>(end - start).count() << " ms\n";

    start = std::chrono::high_resolution_clock::now();
    LargeArray arr3 = std::move(arr1); // Move
    end = std::chrono::high_resolution_clock::now();
    std::cout << "Move time: "
              << std::chrono::duration<double, std::milli>(end - start).count() << " ms\n";

    return 0;
}
