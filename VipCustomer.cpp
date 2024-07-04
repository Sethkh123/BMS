#pragma once
#include <vector>
#include <iostream>
#include <algorithm>
#include <string>
#include <stdexcept>
#include "Customer.cpp"

class VipCustomer : public Customer {
private:
    bool getDiscount;

public:
    VipCustomer(const std::string& name, int id, bool freeService, bool fullService, bool getDiscount)
        : Customer(id, freeService, fullService, name), getDiscount(getDiscount) {}

    std::string getType() const override {
        return "Vip Customer";
    }

    bool hasDiscount() const {
        return getDiscount;
    }

    void setDiscount(bool discount) {
        getDiscount = discount;
    }

    void display() const override {
        Customer::display();
        std::cout << std::setw(15) << (getDiscount ? "Yes" : "No") << std::endl;
    }
};