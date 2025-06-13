#ifndef INVENTORYMANAGER_H
#define INVENTORYMANAGER_H

#include "Product.h"
#include "BTree.h"
#include "OrderQueue.h"
#include <unordered_map>
#include <string>

class InventoryManager {
private:
    BTree productIndex;
    OrderQueue orderQueue;
    std::unordered_map<std::string, Product*> nameLookup;

public:
    void addProduct(int id, const std::string& name, int quantity, double price);
    void searchById(int id);
    void searchByName(const std::string& name);
    void updateProduct(int id, int quantity, double price);
    void deleteProduct(int id);

    void placeOrder(int productId, int quantity);
    void processOrder();
    void viewOrders();

    void displayAllProducts();
};

#endif // INVENTORYMANAGER_H