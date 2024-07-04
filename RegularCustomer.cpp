#pragma once
#include <vector>
#include <iostream>
#include <algorithm>
#include <string>
#include <stdexcept>
#include "Customer.cpp"
class RegularCustomer : public Customer {
public:
    RegularCustomer(const std::string& name, int id, bool freeService, bool fullService)
        : Customer(id, freeService, fullService, name) {}

    std::string getType() const override {
        return "Regular Customer";
    }
};
