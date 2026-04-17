#include<iostream>
#include<map>
#include<limits>

void clearInputBuffer() { std::cin.clear(); // Clear error flags // Discard all characters in the input buffer up to the newline character 
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); 
}

bool getProductStock(int productId, int& currentStock, const std::map<int, int>& inventoryMap){
    if(inventoryMap.count(productId) > 0){
        currentStock = inventoryMap.at(productId);
        return true;
    }
    else currentStock = 0;
    return false;
}

void displayInventory(const std::map<int, int>& inventoryMap, const std::string& title){
    std::cout<<title<<std::endl;
    for(const auto &entry : inventoryMap){
        std::cout<<"Product ID: "<<entry.first<<", Stock: "<<entry.second<<std::endl;
    }
}

void addNewProduct(std::map<int, int> &inventory){
    int pId, stock;
    std::cout<<"Enter new product ID: ";
    if(!(std::cin >> pId)){
        std::cerr<<"Invalid input for product ID! "<<std::endl;
        clearInputBuffer();
        return;
    }
    std::cout<<"Enter stock for the new product: ";
    if(!(std::cin >> stock)){
        std::cerr<<"Invalid input for stock! "<<std::endl;
        clearInputBuffer();
        return;
    }
    if(inventory.count(pId) > 0){
        std::cout<<"Product ID already exists! Enter new product! "<<std::endl;
        return;
    }   
    if(stock < 0){
        std::cout<<"Stock cannot be negative! Enter new product! "<<std::endl;
        return;
    }
    inventory.emplace(pId, stock);
    std::cout<<"Product added successfully! "<<std::endl;
}


void performSale(std::map<int, int>& inventory){
    std::cout<<"Enter product ID and quantity for sale: ";
    int pId, quantity;
    if(!(std::cin >> pId >> quantity)){
        std::cerr<<"Invalid input! "<<std::endl;
        clearInputBuffer();
        return;
    }
    if(inventory.count(pId) == 0){
        std::cout<<"Product ID not found! "<<std::endl;
        return;
    }
    if(quantity < 0){
        std::cout<<"Quantity cannot be negative! "<<std::endl;
        return;
    }
    if(inventory[pId] < quantity){
        std::cout<<"Insufficient stock! "<<std::endl;
        return;
    }
    inventory[pId] -= quantity;
    std::cout<<"Sale completed successfully! "<<std::endl;
}

void performRestock(std::map<int, int>& inventory){
    std::cout<<"Enter product ID and quantity for restock: ";
    int pId, quantity;
    if(!(std::cin >> pId >> quantity)){
        std::cerr<<"Invalid input! "<<std::endl;
        clearInputBuffer();
        return;
    }
    if(inventory.count(pId) == 0){
        std::cout<<"Product ID not found! "<<std::endl;
        return;
    }
    if(quantity < 0){
        std::cout<<"Quantity cannot be negative! "<<std::endl;
        return;
    }
    inventory[pId] += quantity;
    std::cout<<"Restock completed successfully! "<<std::endl;
}

void checkProductStatus(const std::map<int, int>& inventory){
    std::cout<<"Enter product ID to check status: ";
    int pId;
    if(!(std::cin >> pId)){
        std::cerr<<"Invalid input! "<<std::endl;
        clearInputBuffer();
        return;
    }
    int currentStock;
    if(getProductStock(pId, currentStock, inventory)){
        std::cout<<"Product ID: "<<pId<<", Current Stock: "<<currentStock<<std::endl;
    }
    else{
        std::cout<<"Product ID not found! "<<std::endl;
    }
}


void discontinueProduct(std::map<int, int>& inventory){
    std::cout<<"Enter product ID to discontinue: ";
    int pId;
    if(!(std::cin >> pId)){
        std::cerr<<"Invalid input! "<<std::endl;
        clearInputBuffer();
        return;
    }
    if(inventory.erase(pId) > 0){
        std::cout<<"Product discontinued successfully! "<<std::endl;
    }
    else{
        std::cout<<"Product ID not found! "<<std::endl;
    } 
}

void ActionToPerform(std::map<int, int> &inventory){

    int choice;
    do{
        // "1. Add New Product\n"; // addNewProduct(inventory) 
        // "2. Perform Sale\n"; // performSale(inventory) "
        // 3. Perform Restock\n"; // performRestock(inventory) "
        // 4. Check Product Status\n"; // checkProductStatus(inventory) "
        // 5. Discontinue Product\n"; // discontinueProduct(inventory) "
        // 6. Display All Products\n"; // displayInventory(inventory, "Current Inventory Overview") "
        // 0. Exit\n";
        std::cout<<"Enter your choice: "<<std::endl;
        std::cout<<"1. Add New Product\n";
        std::cout<<"2. Perform Sale\n";
        std::cout<<"3. Perform Restock\n";
        std::cout<<"4. Check Product Status\n";
        std::cout<<"5. Discontinue Product\n";
        std::cout<<"6. Display All Products\n";
        std::cout<<"0. Exit\n";
        
        if(!(std::cin >> choice)){
            std::cerr<<"Invalid input! "<<std::endl;
            clearInputBuffer();
            continue;
        }
        switch(choice){
            case 1:
                addNewProduct(inventory);
                break;
            case 2:
                performSale(inventory);
                break;
            case 3:
                performRestock(inventory);
                break;
            case 4:
                checkProductStatus(inventory);
                break;
            case 5:
                discontinueProduct(inventory);
                break;
            case 6:
                displayInventory(inventory, "Current Inventory");
                break;
            case 0:
                break;
            default:
                std::cout<<"Invalid choice! Please enter a valid option. "<<std::endl;
                break;
        }

    }
    while(choice != 0);
}



int main(){
    std::map<int, int> inventory;
    inventory[101] = 50; 
    inventory[102] = 25; 
    inventory[103] = 100; 
    inventory[104] = 10; 
    inventory[105] = 75;
    displayInventory(inventory, "Initial Inventory:");
    ActionToPerform(inventory);

}