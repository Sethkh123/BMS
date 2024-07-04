#pragma once

#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <stdexcept>
#include "Customer.cpp" 
#include "DataValidInput.cpp"
#include "CustomerRepository.cpp"
#include "VipCustomer.cpp"
#include "RegularCustomer.cpp"
#include "display.cpp"

class CustomerManagement {
private:
    std::vector<std::unique_ptr<Customer>> Customers;

    Customer* findCustomerbyID(int id) {
        auto it = std::find_if(Customers.begin(), Customers.end(), [id](const std::unique_ptr<Customer>& customer) {
            return customer->getId() == id;
        });
        return (it != Customers.end()) ? it->get() : nullptr;
    }

    bool confirmAction(const std::string& action) {
        std::string input;
        std::cout << "Are you sure you want to " << action << "? (y/n): ";
        std::cin >> input;
        return input == "y" || input == "Y";
    }

public:
    ~CustomerManagement() = default;

    void addCustomer() {
        int id = DataValidInput::getIntInput("Enter Customer ID\nID: ");
        std::string name = DataValidInput::getStringInput("Enter Customer Name\nName: ");
        int type = DataValidInput::getIntInput("Enter 1 for Vip Customer, 2 for Regular Customer\nChoice: ");
        bool freeService = DataValidInput::getBoolInput("Does the customer have free service? (1 for yes, 0 for no)\n");
        bool fullService = DataValidInput::getBoolInput("Does the customer have full service? (1 for yes, 0 for no)\n");

        if (type == 1) {
            bool getDiscount = DataValidInput::getBoolInput("Does the VIP customer get a discount? (1 for yes, 0 for no)\n");
            Customers.push_back(std::make_unique<VipCustomer>(name, id, freeService, fullService, getDiscount));
        } else if (type == 2) {
            Customers.push_back(std::make_unique<RegularCustomer>(name, id, freeService, fullService));
        } else {
            throw std::invalid_argument("Invalid Customer type.");
        }
        std::cout << "Customer added successfully.\n";
    }

    void updateCustomer() {
        int id = DataValidInput::getIntInput("Enter Customer ID\nID: ");
        DataValidInput::validateId(id);
        Customer* customer = findCustomerbyID(id);
        if (customer == nullptr) {
            throw std::invalid_argument("Customer not found");
        }

        std::string newName = DataValidInput::getStringInput("Enter new Customer Name\nName: ");
        bool newFreeService = DataValidInput::getBoolInput("Does the customer have free service? (1 for yes, 0 for no)\n");
        bool newFullService = DataValidInput::getBoolInput("Does the customer have full service? (1 for yes, 0 for no)\n");

        std::cout << "You entered:\n"
                  << "Name: " << newName << "\n"
                  << "Free Service: " << newFreeService << "\n"
                  << "Full Service: " << newFullService << "\n";

        if (confirmAction("update this Customer")) {
            customer->setName(newName);
            customer->setFreeService(newFreeService);
            customer->setFullService(newFullService);
            std::cout << "Customer updated successfully.\n";
        } else {
            std::cout << "Update canceled.\n";
        }
    }

    void deleteCustomer() {
        int id = DataValidInput::getIntInput("Enter Customer ID\nID: ");
        DataValidInput::validateId(id);
        Customer* customer = findCustomerbyID(id);
        if (customer == nullptr) {
            throw std::invalid_argument("Customer not found");
        }

        std::cout << "You are about to delete the Customer with ID: " << id << "\n";
        customer->display();

        if (confirmAction("delete this Customer")) {
            Customers.erase(std::remove_if(Customers.begin(), Customers.end(), [id](const std::unique_ptr<Customer>& customer) {
                return customer->getId() == id;
            }), Customers.end());
            std::cout << "Customer deleted successfully.\n";
        } else {
            std::cout << "Deletion canceled.\n";
        }
    }

    void viewCustomer() {
        if (Customers.empty()) {
            throw std::invalid_argument("No Customer available");
        }
        displayCustomer();
        for (const auto& customer : Customers) {
            customer->display();
        }
    }
};