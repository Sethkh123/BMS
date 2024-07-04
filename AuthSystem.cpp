#pragma once

#include <iostream>
#include <vector>
#include <string>
#include <fstream>
#include <iomanip>
#include "DataValidInput.cpp"
#include "User.cpp"
#include "CustomerManagement.cpp"
#include "AccountManagement.cpp"
#include "CustomerApplication.cpp"
#include "AccountApplication.cpp"

class AuthSystem {
private:
    CustomerManagement customerManagement;
    AccountManagement accountManagement;
    std::vector<User> users;
    std::string usersFile = "users.txt";

    void loadUsers() {
        std::ifstream file(usersFile, std::ios::binary);
        if (file.is_open()) {
            User user;
            while (file.read(reinterpret_cast<char*>(&user), sizeof(User))) {
                users.push_back(user);
            }
            file.close();
        }
    }

    void saveUsers() {
        std::ofstream file(usersFile, std::ios::binary | std::ios::trunc);
        if (file.is_open()) {
            for (const auto& user : users) {
                file.write(reinterpret_cast<const char*>(&user), sizeof(User));
            }
            file.close();
        }
    }

    bool authenticate(const std::string& username, const std::string& password, User& authenticatedUser) {
        for (const auto& user : users) {
            if (user.getUsername() == username && user.getPassword() == password) {
                authenticatedUser = user;
                return true;
            }
        }
        return false;
    }

    void displayMainMenu() {
        std::cout << "Main Menu:\n";
        std::cout << "1. Customer Management\n";
        std::cout << "2. Account Management\n";
        std::cout << "3. User Management\n";
        std::cout << "4. Exit\n";
    }

    void adminMenu() {
        enum MainMenu { EXIT, CUSTOMER, ACCOUNT, USER };
        int choice;
        std::cout.setf(std::ios::fixed | std::ios::showpoint);
        std::cout << std::setprecision(2);

        do {
            displayMainMenu();
            choice = DataValidInput::getIntInput("Enter your choice: ");
            switch (choice) {
                case CUSTOMER: {
                    CustomerApplication customerApplication;
                    customerApplication.run();
                    break;
                }
                case ACCOUNT: {
                    AccountApplication accountApplication;
                    accountApplication.run();
                    break;
                }
                case USER: {
                    manageUsers();
                    break;
                }
                case EXIT:
                    std::cout << "Exiting program...\n";
                    break;
                default:
                    std::cout << "Invalid input. Please try again.\n";
            }
        } while (choice != EXIT);
    }

    void userMenu() {
        int choice;
        do {
            std::cout << "\nUser Menu\n";
            std::cout << "1. View Profile\n";
            std::cout << "2. Logout\n";
            std::cout << "Enter choice: ";
            std::cin >> choice;

            switch (choice) {
                case 1:
                    std::cout << "Viewing user profile...\n";
                  
                    break;
                case 2:
                    std::cout << "Logging out...\n";
                    break;
                default:
                    std::cout << "Invalid choice, please try again.\n";
            }
        } while (choice != 2);
    }

    void manageUsers() {
        int choice;
        do {
            std::cout << "\nUser Management\n";
            std::cout << "1. View Users\n";
            std::cout << "2. Add User\n";
            std::cout << "3. Return to Main Menu\n";
            std::cout << "Enter choice: ";
            std::cin >> choice;

            switch (choice) {
                case 1:
                    viewUsers();
                    break;
                case 2:
                    addUser();
                    break;
                case 3:
                    std::cout << "Returning to Main Menu...\n";
                    break;
                default:
                    std::cout << "Invalid choice, please try again.\n";
            }
        } while (choice != 0);
    }

public:
    AuthSystem() {
        loadUsers();
    }

    void addUser() {
        std::string username, password, role;
        std::cout << "Enter username: ";
        std::cin >> username;
        std::cout << "Enter password: ";
        std::cin >> password;
        std::cout << "Enter role (admin/user): ";
        std::cin >> role;

        users.push_back(User(username, password, role));
        saveUsers();

        if (role == "admin") {
            std::cout << "Admin added successfully!\n";
        } else {
            std::cout << "User added successfully!\n";
        }
    }

    void login() {
        std::string username, password;
        std::cout << "Enter username: ";
        std::cin >> username;
        std::cout << "Enter password: ";
        std::cin >> password;

        User authenticatedUser;
        if (authenticate(username, password, authenticatedUser)) {
            std::cout << "Login successful! Role: " << authenticatedUser.getRole() << std::endl;
            if (authenticatedUser.getRole() == "admin") {
                std::cout << "Admin login successful!\n";
                adminMenu();
            } else {
                userMenu();
            }
        } else {
            std::cout << "Invalid username or password.\n";
        }
    }

    void registerUser() {
        std::string username, password, role;
        std::cout << "Enter username: ";
        std::cin >> username;
        std::cout << "Enter password: ";
        std::cin >> password;
        std::cout << "Enter role (admin/user): ";
        std::cin >> role;

        users.push_back(User(username, password, role));
        saveUsers();
        std::cout << "User registered successfully!\n";
    }

    void viewUsers() {
        std::cout << "\nRegistered Users:\n";
        for (const auto& user : users) {
            std::cout << "Username: " << user.getUsername() << ", Role: " << user.getRole() << std::endl;
        }
    }

    void menu() {
        int choice;
        do {
            std::cout << "\nMain Menu\n";
            std::cout << "1. Login\n";
            std::cout << "2. Register\n";
            std::cout << "3. Exit\n";
            std::cout << "Enter choice: ";
            std::cin >> choice;

            switch (choice) {
                case 1:
                    login();
                    break;
                case 2:
                    registerUser();
                    break;
                case 0:
                    std::cout << "Exiting program...\n";
                    break;
                default:
                    std::cout << "Invalid choice, please try again.\n";
            }
        } while (choice != 0);
    }
};
