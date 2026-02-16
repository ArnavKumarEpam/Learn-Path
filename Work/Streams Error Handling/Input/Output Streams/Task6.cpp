#include<iostream>
#include<fstream>
#include <vector>
#include<limits>
class Book{
    private:
        std::string title;
        std::string author;
        double price;

    public:
        Book(){}
        Book(std::string title,
        std::string author,
        double price) : title(title), author(author), price(price){}
        void show(){
            std::cout<<title<<" "<<author<<" "<<price;
        }
        friend void saveToFile(const Book& book, std::ofstream& ofs);
        friend Book loadFromFile(std::ifstream& ifs);
};

void saveToFile(const Book& book, std::ofstream& ofs){
   ofs << book.title << '\n' << book.author << '\n' << book.price << '\n';
}
Book loadFromFile(std::ifstream& ifs){
    if(!ifs.is_open()){
        std::cout<<"The File isn't open! \n";
        return Book();
    }
    std::string title, author;
    double price;
    std::getline(ifs, title);
    std::getline(ifs, author);
    ifs >> price;
    ifs.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    return Book(title, author, price);
}

int main(){
    std::cout<<"Enter the Number of Books you want to add: ";
    int n;
    std::cin>>n;
    std::vector<Book> list(n);
    std::ofstream ofs("newFile", std::ios::out);
    for(int i = 0 ; i < n ; i++){
        std::cout<<"Enter the details of Book: "<<i + 1<<std::endl;
        std::string title;
        std::cout<<"Enter the Title of the Book: ";
        getline(std::cin >> std::ws, title);

        std::string author;
        std::cout<<"Enter the Author of the Book: ";
        getline(std::cin, author);

        double price;
        std::cout<<"Enter the Price of the Book: ";
        std::cin>>price;

        Book book(title, author, price);
        saveToFile(book, ofs);
        
    }
    ofs.close();
    std::ifstream ifs("newFile", std::ios::in);
    for(int i = 0 ; i < n ; i++){

        Book savedBook = loadFromFile(ifs);
        savedBook.show();
        std::cout<<std::endl;
    }
    // Book book("LEts C++", "ABC", 200);
    // saveToFile(book, ofs);
    ifs.close();
    return 0;
}

