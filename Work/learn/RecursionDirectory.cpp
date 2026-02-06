#include<iostream>
#include<filesystem>

namespace fs = std::filesystem; // short alias for std::filesystem


void recursiveDirectoryTraversal(const fs::path &path, int level){

    // iterate through files/folder in current directory
    for(const auto &entry : fs::directory_iterator(path)){
        for(int i= 0 ; i < level ; i++) std::cout<<" ";

            if(fs::is_directory(entry)){ // check if current entry is directory
                std::cout << entry.path().filename().string() << ":\n";

            // Recursive call
            recursiveDirectoryTraversal(entry.path(), level + 2);
        } else {// if its a file print its name
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