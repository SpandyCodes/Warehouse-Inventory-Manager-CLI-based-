#include "InventoryManager.h"
#include <iostream>

void InventoryManager::addProduct(int id, const std::string& name, int quantity, double price) {
    Product* newProduct = new Product(id, name, quantity, price);
    productIndex.insert(newProduct);
    nameLookup[name] = newProduct;
    std::cout << "Product added: " << name << "\n";
}

void InventoryManager::searchById(int id) {
    Product* p = productIndex.search(id);
    if (p) p->display();
    else std::cout << "Product not found with ID: " << id << "\n";
}

void InventoryManager::searchByName(const std::string& name) {
    if (nameLookup.find(name) != nameLookup.end())
        nameLookup[name]->display();
    else
        std::cout << "Product not found with name: " << name << "\n";
}

void InventoryManager::updateProduct(int id, int quantity, double price) {
    Product* p = productIndex.search(id);
    if (p) {
        p->quantity = quantity;
        p->price = price;
        std::cout << "Product updated: " << p->name << "\n";
    } else {
        std::cout << "Product not found with ID: " << id << "\n";
    }
}

void InventoryManager::deleteProduct(int id) {
    // Deletion in B-Tree is complex and not implemented in this version
    std::cout << "Delete functionality is currently not supported.\n";
}

void InventoryManager::placeOrder(int productId, int quantity) {
    Product* p = productIndex.search(productId);
    if (!p) {
        std::cout << "Product ID " << productId << " not found.\n";
        return;
    }
    if (p->quantity < quantity) {
        std::cout << "Insufficient stock for product: " << p->name << "\n";
        return;
    }
    orderQueue.placeOrder(productId, quantity);
    p->quantity -= quantity;
}

void InventoryManager::processOrder() {
    orderQueue.processOrder();
}

void InventoryManager::viewOrders() {
    orderQueue.viewOrders();
}

void InventoryManager::displayAllProducts() {
    std::cout << "\n--- Product Catalog ---\n";
    productIndex.traverse();
    std::cout << "------------------------\n";
}