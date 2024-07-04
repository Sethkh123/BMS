#pragma once
#include <iostream>
#include <vector>
#include <algorithm>
#include <iomanip>
#include <string>
#include <stdexcept>
using namespace std;

class Account {
protected:
    std::string name;
    int id;
    std::string phone;
    double balance;

public:
    Account() : balance(0.0) {}

    Account(int id, std::string phone, std::string name)
        : id(id), phone(phone), name(name), balance(0.0) {}

    
    int getId() const {
        return id;
    }

    std::string getPhone() const {
        return phone;
    }

    std::string getName() const {
        return name;
    }

    double getBalance() const {
        return balance;
    }

  
    void setId(int id) {
        this->id = id;
    }

    void setPhone(const std::string& phone) {
        this->phone = phone;
    }

    void setName(const std::string& name) {
        this->name = name;
    }

 
    void deposit(double amount) {
        if (amount <= 0) {
            throw std::invalid_argument("Deposit amount must be positive.");
        }
        balance += amount;
    }

    void withdraw(double amount) {
        if (amount <= 0) {
            throw std::invalid_argument("Withdraw amount must be positive.");
        }
        if (amount > balance) {
            throw std::invalid_argument("Insufficient balance.");
        }
        balance -= amount;
    }

   
    virtual std::string getType() const = 0;

    virtual void displayname() const {
        std::cout << std::left << std::setw(20) << getType()
                  << std::setw(20) << id
                  << std::setw(15) << name
                  << std::setw(15) << phone
                  << std::setw(15) << balance << std::endl;
    }

    virtual ~Account() = default;
};
