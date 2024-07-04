#pragma once
#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <stdexcept>
#include <regex>
#include "Customer.cpp"
#include "Account.cpp"

class DataValidInput {
public:
    static void validateId(int id) {
        if (id <= 0) {
            throw std::invalid_argument("ID must be a positive integer.");
        }
    }

    static bool validateName(const std::string& name) {
        std::regex name_regex("^[A-Za-z]{3,}$");
        return std::regex_match(name, name_regex);
    }

    static bool validatePhone(const std::string& phone) {
       
        std::regex phone_regex("^0[0-9]{8}$");
        return std::regex_match(phone, phone_regex);
    }

    static std::string getStringInput(const std::string& prompt) {
        std::string input;
        while (true) {
            std::cout << prompt;
            std::getline(std::cin, input);
            if (validateName(input)) {
                break;
            }
            std::cout << "Invalid input! Please enter a valid name (more than 2 alphabetic characters)." << std::endl;
        }
        return input;
    }

    static std::string getPhoneInput(const std::string& prompt) {
        std::string input;
        while (true) {
            std::cout << prompt;
            std::getline(std::cin, input);
            if (validatePhone(input)) {
                break;
            }
            std::cout << "Invalid input! Please enter a valid 9-digit phone number starting with '0'." << std::endl;
        }
        return input;
    }

    static int getIntInput(const std::string& prompt) {
        int input;
        std::cout << prompt;
        while (!(std::cin >> input)) {
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            std::cout << "Invalid input. Please enter an integer: ";
        }
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        return input;
    }

    static bool getBoolInput(const std::string& prompt) {
        std::string input;
        while (true) {
            std::cout << prompt;
            std::getline(std::cin, input);
            if (input == "1" || input == "true" || input == "y" || input == "Y") {
                return true;
            } else if (input == "0" || input == "false" || input == "n" || input == "N") {
                return false;
            } else {
                std::cout << "Invalid input. Please enter '1' (true) or '0' (false): ";
            }
        }
    }
};