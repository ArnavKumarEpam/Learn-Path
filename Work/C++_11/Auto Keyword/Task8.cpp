#include <iostream>
#include <vector>
#include <string>

int main() {
    std::vector<std::pair<int, std::string>> v{{1, "A"}, {2, "B"}};
    
     for (auto &[num, str] : v) {
        std::cout << "num: " << num << ", str: " << str << std::endl;
    }
    
    return 0;
}