#include<iostream>
#include<filesystem>

namespace fs = std::filesystem;

void recursiveDirectoryTraversal(const char *path, int level){
    for(const auto &entry : fs::directory_iterator(path)){
        for(int i= 0 ; i < level ; i++) std::cout<<" ";

        if(fs::is_directory(entry.status())){  
            std::cout << entry.path().filename().string() << ":\n";

            // Recursive call
            recursiveDirectoryTraversal(entry.path().string().c_str(), level + 2);  
        } else {
            std::cout << entry.path().filename().string() << std::endl;
        }
    }
}


int main(int argc, char*argv[]) {
    if (argc < 2) {
        std::cout << "Usage: program <directory_path>\n";
        return 0;
    }
    std::cout << "Root:\n";
    recursiveDirectoryTraversal(argv[1], 2);

    return 0;
}