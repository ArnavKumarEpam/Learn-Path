#include <iostream>
#include <vector>
#include<memory>
class Book {
public:
    std::string title;
    std::string author;

    Book(const std::string& t, const std::string& a) : title(t), author(a) {}
    void print() const {
        std::cout << "Book: " << title << " by " << author << std::endl;
    }
};

class Library {
    std::vector<std::unique_ptr<Book>> books;
public:
    ~Library() {
        // Clean up all books
        
    }

    void addBook(const std::string& title, const std::string& author) {
        books.push_back(std::make_unique<Book>(title, author));
    }

    Book* findBook(const std::string& title) {
        for (std::unique_ptr<Book> &book : books) {
            if (book->title == title) return book.get();
        }
        return nullptr;
    }

    void removeBook(const std::string& title) {
        for (auto it = books.begin(); it != books.end(); ++it) {
            if ((*it)->title == title) {
                    // delete *it; // Book is deleted here
                books.erase(it);
                return;
            }
        }
    }
};

int main() {
    Library lib;
    lib.addBook("1984", "George Orwell");
    lib.addBook("Brave New World", "Aldous Huxley");

    // Find a book and keep its pointer
    Book* bookPtr = lib.findBook("1984");
    if (bookPtr) {
        bookPtr->print();
    }

    // Remove the book from the library
    lib.removeBook("1984");

    // Dangling pointer: bookPtr now points to deleted memory!
    std::cout << "Trying to access deleted book:" << std::endl;
    if (bookPtr) {
        bookPtr->print(); // Undefined behavior!
        // std::cout << "Warning: Accessing a dangling pointer!" << std::endl;
    }

    return 0;
}
