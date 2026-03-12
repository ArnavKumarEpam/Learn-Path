#include<iostream>
#include<vector>
#include<algorithm>
struct MultiplyBy{
    int factor;
    void operator()(int &x) const {
        x *= factor;
    }
};

int main(){
    std::vector<int> v{1, 2, 3, 4, 5};
    std::for_each(v.begin(), v.end(), MultiplyBy{3});
    std::for_each(v.begin(), v.end(), MultiplyBy{4});
    std::cout << "Modified vector: ";
    for (int n : v)
        std::cout << n << " ";
    std::cout << std::endl;
    return 0;
}