// #include<iostream>
// #include<fstream>
// class Book{
//     private:
//         std::string title;
//         std::string author;
//         double price;
//     public:
//         Book(std::string title, std::string author, double price) : 
//                             title(title), author(author), price(price){}
//     friend std::istream &operator >>(std::istream& is, Book& book);
//     friend std::ostream& operator<<(std::ostream& os, const Book& book);

// };

// std::istream &operator >>(std::istream& is, Book& book){
//     std::cout << "Before read: " << book.title << '\n';

//     std::getline(is >> std::ws, book.title);
//     std::getline(is, book.author);
//     is >> book.price;

//     std::cout << "After read: " << book.title << '\n';
//     return is;
// }

// std::ostream& operator<<(std::ostream& os, const Book& book){
//     os << book.title << '\n'
//        << book.author << '\n'
//        << book.price << '\n';
//     return os;
// }

// int main(){
//     Book book("Lets C++", "ABC", 200);
//     std::ifstream readFile("CopiedFile", std::ios::in);
//     readFile >> book;
//     std::ofstream writeFile("NEW File", std::ios::out);
//     writeFile << book;

// }

#include<iostream>
#include <vector>

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
        friend std::istream& operator>>(std::istream& is, Book& book);
        friend std::ostream& operator<<(std::ostream& os, const Book& book);
};
std::istream& operator>>(std::istream& is, Book& book){
    std::cout<<"Enter the Title of the Book: \n";
    getline(is >> std::ws, book.title); // to handling the leading whitespaces

    std::cout<<"Enter the Author of the Book: \n";
    getline(is, book.author);

    std::cout<<"Enter the Price of the Book: \n";
    is>>book.price;

    return is;
}

std::ostream& operator<<(std::ostream& os, const Book& book){
    os << "Title: "<<book.title<<"\n"<<
    "Author: "<<book.author<<"\n"<<
    "Price: "<<book.price<<"\n";
    return os;
}

int main(){
    int n;
    std::cout<<"\nEnter the Number of Books: ";
    std::cin>>n;
    std::vector<Book> books(n);
    for(int i = 0 ; i < n ; i++){
        std::cout<<"\nEnter the details of Books: \n";
        std::cin>>books[i];
    }
    std::cout<<"Printing the details of Books: \n";
    for(int i = 0 ; i < n ; i++){
        std::cout<<books[i];
    }
}
