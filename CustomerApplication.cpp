#pragma once
#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <stdexcept>
#include "CustomerManagement.cpp"
#include "DataValidInput.cpp"

class CustomerApplication {
private:
    enum ChoiceMenu { ADD = 1, UPDATE, VIEW, DELETE, RETURN };

    void displayMenu() {
        std::cout << "\n=== Customer customerManagement Menu ===\n"
                  << "1. Add Customer\n"
                  << "2. Update Customer\n"
                  << "3. View Customers\n"
                  << "4. Delete Customer\n"
                  << "5. Return\n"
                  << "================================\n";
    }

public:
    void run() {
        CustomerManagement customerManagement;
        int choice;
        bool done = false;

        while (!done) {
            displayMenu();
            choice = DataValidInput::getIntInput("Enter your choice: ");
            try {
                switch (choice) {
                    case ADD:
                        customerManagement.addCustomer();
                        break;
                    case UPDATE:
                        customerManagement.updateCustomer();
                        break;
                    case VIEW:
                        customerManagement.viewCustomer();
                        break;
                    case DELETE:
                        customerManagement.deleteCustomer();
                        break;
                    case RETURN:
                        done = true;
                        break;
                    default:
                        std::cout << "Invalid choice. Please try again.\n";
                }
            } catch (const std::exception& e) {
                std::cout << "Error! " << e.what() << std::endl;
            }
        }
    }
};