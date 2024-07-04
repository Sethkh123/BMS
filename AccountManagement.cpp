#pragma once
#include <iostream>
#include <vector>
#include <algorithm>
#include <iomanip>
#include <string>
#include <stdexcept>
#include "Account.cpp"
#include "DataValidInput.cpp"
#include "AccountRepository.cpp"
#include "CheckingAccount.cpp"
#include "SavingAccount.cpp"
#include "display.cpp"

class AccountManagement : public AccountRepository {
private:
    std::vector<Account*> accounts;

    Account* findAccountByID(int id) {
        auto it = std::find_if(accounts.begin(), accounts.end(), [id](Account* account) {
            return account->getId() == id;
        });
        return (it != accounts.end()) ? *it : nullptr;
    }

    bool confirmAction(const std::string& action) {
        std::string input;
        std::cout << "Are you sure you want to " << action << "? (y/n): ";
        std::cin >> input;
        return input == "y" || input == "Y";
    }

public:
    ~AccountManagement() {
        for (auto account : accounts) {
            delete account;
        }
    }

    void addAccount(int id, std::string name, int type, std::string phone) {
        std::cout << "=========== ADD Account ===========\n";
        id = DataValidInput::getIntInput("Enter Account ID: ");
        name = DataValidInput::getStringInput("Enter Account Name: ");
        DataValidInput::validateId(id);
        type = DataValidInput::getIntInput("Enter 1 for Checking Account, 2 for Saving Account: ");
        phone = DataValidInput::getPhoneInput("Enter Account Phone: ");
        
        if (type == 1) {
            bool monthlyFee = DataValidInput::getBoolInput("Enter Monthly Fee (1 for yes, 0 for no): ");
            accounts.push_back(new CheckingAccount(name, id, phone, monthlyFee));
        } else if (type == 2) {
            bool interestRate = DataValidInput::getBoolInput("Enter Interest Rate (1 for yes, 0 for no): ");
            accounts.push_back(new SavingAccount(name, id, phone, interestRate));
        } else {
            throw std::invalid_argument("Invalid Account Type.");
        }
        std::cout << "Account added successfully.\n";
    }

    void updateAccount(int id) {
        id = DataValidInput::getIntInput("Enter Account ID: ");
        DataValidInput::validateId(id);
        Account* account = findAccountByID(id);
        if (account == nullptr) {
            throw std::invalid_argument("Account not found");
            return;
        }

        std::string newPhone = DataValidInput::getPhoneInput("Enter NewAccount Phone: ");
        std::string newName = DataValidInput::getStringInput("Enter NewAccount Name: ");

        std::cout << "You entered:\n"
                  << "Name: " << newName << "\n"
                  << "Phone: " << newPhone << "\n";

        if (confirmAction("update this Account with the new information")) {
            account->setPhone(newPhone);
            account->setName(newName);
            std::cout << "Account updated successfully.\n";
        } else {
            std::cout << "Update canceled.\n";
        }
    }

    void deleteAccount(int id) {
        id = DataValidInput::getIntInput("Enter Account ID: ");
        DataValidInput::validateId(id);
        Account* account = findAccountByID(id);
        if (account == nullptr) {
            throw std::invalid_argument("Account not found");
            return;
        }

        std::cout << "You are about to delete the following Account:\n";
        account->displayname();

        if (confirmAction("delete this Account")) {
            auto it = std::remove_if(accounts.begin(), accounts.end(), [id](Account* account) {
                if (account->getId() == id) {
                    delete account;
                    return true;
                }
                return false;
            });
            accounts.erase(it, accounts.end());
            std::cout << "Account deleted successfully.\n";
        } else {
            std::cout << "Deletion canceled.\n";
        }
    }

    void viewAccount() {
        if (accounts.empty()) {
            throw std::invalid_argument("No Account available");
            return;
        }
        displayAccount();
        for (const auto& account : accounts) {
            account->displayname();
        }
    }

    void depositMoney(int id, double amount) {
        Account* account = findAccountByID(id);
        if (account == nullptr) {
            throw std::invalid_argument("Account not found");
        }
        account->deposit(amount);
    }

    void withdrawMoney(int id, double amount) {
        Account* account = findAccountByID(id);
        if (account == nullptr) {
            throw std::invalid_argument("Account not found");
        }
        account->withdraw(amount);
    }
};
