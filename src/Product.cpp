#include "Product.h"
#include <iostream>

Product::Product(int id, const std::string& name, int quantity, double price)
    : id(id), name(name), quantity(quantity), price(price) {}

void Product::display() const {
    std::cout << "ID: " << id
              << ", Name: " << name
              << ", Quantity: " << quantity
              << ", Price: $" << price << "\n";
}
