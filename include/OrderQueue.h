#ifndef ORDERQUEUE_H
#define ORDERQUEUE_H

#include <queue>
#include <iostream>
#include <string>

struct Order {
    int orderId;
    int productId;
    int quantity;

    Order(int oid, int pid, int qty) : orderId(oid), productId(pid), quantity(qty) {}
};

class OrderQueue {
private:
    std::queue<Order> orders;
    int nextOrderId;

public:
    OrderQueue() : nextOrderId(1) {}

    void placeOrder(int productId, int quantity) {
        orders.emplace(nextOrderId++, productId, quantity);
        std::cout << "Order placed. Order ID: " << nextOrderId - 1 << "\n";
    }

    void processOrder() {
        if (orders.empty()) {
            std::cout << "No pending orders.\n";
            return;
        }
        Order current = orders.front();
        orders.pop();
        std::cout << "Processing Order ID: " << current.orderId
                  << ", Product ID: " << current.productId
                  << ", Quantity: " << current.quantity << "\n";
    }

    void viewOrders() const {
        if (orders.empty()) {
            std::cout << "No pending orders.\n";
            return;
        }
        std::queue<Order> temp = orders;
        while (!temp.empty()) {
            Order o = temp.front();
            temp.pop();
            std::cout << "Order ID: " << o.orderId << ", Product ID: " << o.productId
                      << ", Quantity: " << o.quantity << "\n";
        }
    }
};

#endif // ORDERQUEUE_H