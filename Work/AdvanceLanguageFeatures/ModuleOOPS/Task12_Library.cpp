#include<iostream>
#include <string>
#include <vector>

class Item{
    protected:
        int id;
        std::string title;
    public:
        Item(){}
        Item(int id, std::string title){
            if(id <= 0){
                throw std::invalid_argument("ID has to be greater than 0.");
            }
            if(title.empty()){
                throw std::invalid_argument("Title of the Item cannot be empty.");
            }
            this -> id = id;
            this -> title = title;
        }


        int getId(){return id;}
        std::string getTitle(){return title;}
        virtual void display() = 0;
};

class Book : public Item{
    private:
        std::string bookName;
        int bookPages;
    public:
        Book(){}
        Book(int id) : Item(id, "Book"){
            
        }
        void setBookName (std::string bookName){this -> bookName = bookName;}
        void setBookPages(int pages){
            if(pages > 0){
                bookPages = pages;
            }
            else{
                std::cout<<"Error! Pages of the book are less than 0! "<<std::endl;
                return;
            }
        }
       


        std::string getBookName(){return bookName;}
        int getBookPages(){return bookPages;}

        void display() override{
            std::cout<<"Book Name: "<<bookName<<" and Book Pages: "<<bookPages<<std::endl;
        }
};
class Magazine : public Item{
    private:
        std::string magazineName;
        int magazinePages;
    public:
        Magazine(){}
        Magazine(int id) : Item(id, "Magazine"){
            
        }
        void setMagazineName(std::string magazineName){this -> magazineName = magazineName;}
        void setMagazinePages(int magazinePages){
            if(magazinePages > 0){
                this -> magazinePages = magazinePages;
            }
            else {
                std::cout<<"Magazine pages are less than 0!"<<std::endl;
                return;
            }
        }
        

        std::string getMagazineName(){return magazineName;}
        int getMagazinePages(){return magazinePages;}

        void display() override{
            std::cout<<"Magazine Name: "<<magazineName<<" and Magazine Pages: "<<magazinePages<<std::endl;
        }
};

class DVD : public Item{
    private:
        std::string dvdName;
        int duration;
    public:
        DVD(){}
        DVD(int id):Item(id, "DVD"){
            
        }
        void setDVDName(std::string dvdName){this->dvdName = dvdName;}
        void setDVDDuration(int duration){
            if(duration > 0){
                this->duration = duration;
            }
            else{
                std::cout<<"DVD duration is less than 0!"<<std::endl;
                return;
            }
        }
        

        std::string getDVDName(){return dvdName;}
        int getDVDDuration(){return duration;}

        void display() override{
            std::cout<<"DVD Name: "<<dvdName<<" and DVD Duration: "<<duration<<std::endl;
        }
};

int main(){
    std::vector<Item *> ptrList;
    Book book(101);
    book.setBookName("Lets C++");
    book.setBookPages(300);
    Item * bookPtr = &book;
    ptrList.push_back(bookPtr);

    Magazine magazine(202);
    magazine.setMagazineName("Forbes 100");
    magazine.setMagazinePages(100);
    Item * magazinePtr = &magazine;
    ptrList.push_back(magazinePtr);

    DVD dvd(303);
    dvd.setDVDName("C++ Tutorials");
    dvd.setDVDDuration(100);
    Item * dvdPtr = &dvd;
    ptrList.push_back(dvdPtr);

    for(int i = 0 ; i < ptrList.size() ; i++){
        ptrList[i]->display();
        std::cout<<"Item ID: "<<ptrList[i]->Item::getId()<<std::endl;
        std::cout<<"Item Title: "<< ptrList[i]->Item::getTitle()<<std::endl;
    }
    return 0;

    

    




}

