// #include<iostream>
// #include<exception>

// class A{
//     public:
//         A(){
//             std::cout<<"Conts\n";
//         }
//         ~A(){
//             std::cout<<"Destructor of Base\n";
//         }
// };
// class MyException : public A{
//     std::string msg;
//     // A a;
//     public:
//         MyException(std::string msg) : msg(msg){
//             throw std::runtime_error("Runtime");
//         }
//         ~MyException(){
//             std::cout<<"Destructor of Child\n";
//         }

// };

// int main(){
//    try{MyException myException("Hello");}
//    catch(const std::runtime_error &e){
//     std::cout<<e.what()<<std::endl;
//    }

// }

#include<iostream>
#include<exception>
#include<limits>
#include<string>
#include<vector>
#include <cmath>

class InvalidPriceException : public std::runtime_error{
    public:
        InvalidPriceException(const char* message) : std::runtime_error(message){}
        InvalidPriceException(std::string &message) : std::runtime_error(message){}
};

class Product{
    private:
        std::string name;
        double price;
        int stock;
    public:
        Product(std::string name, double price, int stock) : name(name), price(price), stock(stock){}
        std::string getName(){return name;}
        double getPrice(){return price;}
        int getStock(){return stock;}

        void setPrice(double price){
            this -> price = price;
        }

        void display(){
            std::cout<<"Name: "<<name<<", Price: "<<price<<", Stock: "<<stock<<std::endl;
        }
        friend void updateProductPrice(Product &product);
};

double getNewPrice(){
    std::cout<<"Enter the new Price: ";
    double price;
    std::cin>>price;
    if(std::cin.fail()){
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        throw InvalidPriceException("Error: Invalid product selection. \n");
    }
    else if(price < 0){
        throw InvalidPriceException("Error: Price cannot be in negative!\n");
    }
    else if(price > 10000){
        throw InvalidPriceException("Error: Price cannot be more than 10000!\n");
    }
    double scaled = price * 100;
    if (std::floor(scaled) != scaled)
        throw InvalidPriceException("Error: Maximum 2 decimal places allowed.");

    std::cin.clear();
    return price;

}

void updateProductPrice(Product &product){
    bool stillgo = false;
    while(!stillgo){
        try{
            double currentPrice = product.getPrice();
            double newPrice = getNewPrice();
            if(newPrice > 1.5 * currentPrice) throw InvalidPriceException("Error: Price change cannot exceed 50% in single update.\n");
            else{

                product.setPrice(newPrice);
                currentPrice = product.getPrice();
                std::cout<<"Successfully updated the price! The new price: "<<currentPrice<<std::endl;
                stillgo = true;
            }
        }
        catch(InvalidPriceException &e){
            std::cout<<e.what();
        }
    }

}
void displayInventory(std::vector<Product> &list){
    int size = list.size();
    for(int i = 0 ; i < size ; i++){
        std::cout<<"Displaying the Records of item: "<<i + 1<<std::endl;
        list[i].display();
    }
}

int main(){
    std::cout<<"Welcome to Inventory Management! \n";
    std::vector<Product> list = {{"ABC", 1000, 1}, {"DEF", 2000, 2}, {"GHI", 3000, 3}};
    char continueUpdate ;
    do{
    try {
            displayInventory(list);

            std::cout << "Select product number to update: ";
            int choice;
            std::cin >> choice;

            if (std::cin.fail() ||
                choice < 1 ||
                choice > list.size()) {

                std::cin.clear();
                std::cin.ignore(
                    std::numeric_limits<std::streamsize>::max(), '\n');

                throw InvalidPriceException(
                    "Error: Invalid product selection.");
            }

            updateProductPrice(list[choice - 1]);

        } catch (const InvalidPriceException& e) {
            std::cout << e.what() << "\n";
        }

        std::cout << "\nContinue updating? (y/n): ";
        std::cin >> continueUpdate;
    
    } while (continueUpdate == 'y' || continueUpdate == 'Y');

    std::cout << "\nFinal Inventory State:\n";
    displayInventory(list);

    std::cout << "Exiting program.\n";
    return 0;
}