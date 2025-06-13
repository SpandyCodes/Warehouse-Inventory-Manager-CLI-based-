#include "InventoryManager.h"
#include <fstream>
#include <sstream>
#include <iostream>

void loadProductsFromFile(const std::string& filename, InventoryManager& manager) {
    std::ifstream file(filename);
    if (!file.is_open()) {
        std::cerr << "Failed to open " << filename << "\n";
        return;
    }

    std::string line;
    while (std::getline(file, line)) {
        std::istringstream iss(line);
        int id, quantity;
        std::string name;
        double price;
        if (iss >> id >> std::ws && std::getline(iss, name, ',') && iss >> quantity >> price) {
            manager.addProduct(id, name, quantity, price);
        }
    }
    file.close();
}

void displayMenu() {
    std::cout << "\n--- Warehouse Inventory Menu ---\n";
    std::cout << "1. Add Product\n";
    std::cout << "2. Search Product by ID\n";
    std::cout << "3. Search Product by Name\n";
    std::cout << "4. Update Product\n";
    std::cout << "5. Place Order\n";
    std::cout << "6. Process Order\n";
    std::cout << "7. View Orders\n";
    std::cout << "8. Display All Products\n";
    std::cout << "9. Exit\n";
    std::cout << "Enter your choice: ";
}

int main() {
    InventoryManager manager;
    loadProductsFromFile("data/products.txt", manager);

    int choice;
    do {
        displayMenu();
        std::cin >> choice;

        switch (choice) {
            case 1: {
                int id, quantity;
                double price;
                std::string name;
                std::cout << "Enter Product ID, Name, Quantity, Price: ";
                std::cin >> id >> std::ws;
                std::getline(std::cin, name, ',');
                std::cin >> quantity >> price;
                manager.addProduct(id, name, quantity, price);
                break;
            }
            case 2: {
                int id;
                std::cout << "Enter Product ID: ";
                std::cin >> id;
                manager.searchById(id);
                break;
            }
            case 3: {
                std::string name;
                std::cout << "Enter Product Name: ";
                std::cin.ignore();
                std::getline(std::cin, name);
                manager.searchByName(name);
                break;
            }
            case 4: {
                int id, quantity;
                double price;
                std::cout << "Enter Product ID to update: ";
                std::cin >> id;
                std::cout << "Enter new Quantity and Price: ";
                std::cin >> quantity >> price;
                manager.updateProduct(id, quantity, price);
                break;
            }
            case 5: {
                int id, qty;
                std::cout << "Enter Product ID and Quantity to order: ";
                std::cin >> id >> qty;
                manager.placeOrder(id, qty);
                break;
            }
            case 6:
                manager.processOrder();
                break;
            case 7:
                manager.viewOrders();
                break;
            case 8:
                manager.displayAllProducts();
                break;
            case 9:
                std::cout << "Exiting...\n";
                break;
            default:
                std::cout << "Invalid choice. Try again.\n";
        }
    } while (choice != 9);

    return 0;
}
