#pragma once
#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <stdexcept>
#include "AccountManagement.cpp"
#include "DataValidInput.cpp"

class AccountApplication {
private:
    enum ChoiceMenu { ADD = 1, UPDATE, VIEW, DELETE, DEPOSIT, WITHDRAW, RETURN };

    void displayMenuAccount() {
        std::cout << "\n=== Account Menu ===\n"
                  << "1. Add Account\n"
                  << "2. Update Account\n"
                  << "3. View Accounts\n"
                  << "4. Delete Account\n"
                  << "5. Deposit Money\n"
                  << "6. Withdraw Money\n"
                  << "7. Return to Main Menu\n"
                  << "====================\n";
    }

public:
    void run() {
        AccountManagement management;
        int choice;
        bool done = false;

        while (!done) {
            displayMenuAccount();
            choice = DataValidInput::getIntInput("Enter your choice: ");
            try {
                switch (choice) {
                    case ADD: {
                        int id, type;
                        std::string name, phone;
                        management.addAccount(id, name, type, phone);
                        break;
                    }
                    case UPDATE: {
                        int id;
                        management.updateAccount(id);
                        break;
                    }
                    case VIEW:
                        management.viewAccount();
                        break;
                    case DELETE: {
                        int id;
                        management.deleteAccount(id);
                        break;
                    }
                    case DEPOSIT:
                        depositMoney(management);
                        break;
                    case WITHDRAW:
                        withdrawMoney(management);
                        break;
                    case RETURN:
                        done = true;
                        break;
                    default:
                        std::cout << "Invalid choice. Please try again.\n";
                }
            } catch (const std::exception& e) {
                std::cout << "Error: " << e.what() << std::endl;
            }
        }
    }

private:
    void depositMoney(AccountManagement& management) {
        std::cout << "=========== Deposit Money ===========\n";
        int id = DataValidInput::getIntInput("Enter Account ID: ");
        double amount = DataValidInput::getIntInput("Enter amount to deposit: ");
        management.depositMoney(id, amount);
        std::cout << "Deposit successful.\n";
    }

    void withdrawMoney(AccountManagement& management) {
        std::cout << "=========== Withdraw Money ===========\n";
        int id = DataValidInput::getIntInput("Enter Account ID: ");
        double amount = DataValidInput::getIntInput("Enter amount to withdraw: ");
        management.withdrawMoney(id, amount);
        std::cout << "Withdrawal successful.\n";
    }
};
