#ifndef PRODUCT_H
#define PRODUCT_H

#include <string>
#include <iostream>

class Product {
public:
    int id;
    std::string name;
    int quantity;
    double price;

    Product() : id(0), name(""), quantity(0), price(0.0) {}
    Product(int id, const std::string& name, int quantity, double price)
        : id(id), name(name), quantity(quantity), price(price) {}

    void display() const {
        std::cout << "ID: " << id << ", Name: " << name
                  << ", Quantity: " << quantity << ", Price: $" << price << std::endl;
    }
};

#endif // PRODUCT_H
