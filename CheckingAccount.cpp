#pragma once
#include <vector>
#include <iostream>
#include <algorithm>
#include <string>
#include <stdexcept>
#include "Account.cpp"

class CheckingAccount : public Account {
private:
    bool monthlyFee; 
    bool balance;
public:
    CheckingAccount(const std::string& name, int id, std::string phone, bool monthlyFee)
          : Account(id, phone, name), monthlyFee(monthlyFee)  {
    }

    std::string getType() const override {
        return "Checking Account";
    }

    bool getMonthlyFee() const {
        return monthlyFee;
    }

    void setMonthlyFee(bool fee) {
        if (fee < 0) {
            throw std::invalid_argument("Monthly fee cannot be negative");
        }
        monthlyFee = fee;
    }

   
    void deposit(bool amount) {
        if (amount <= 0) {
            throw std::invalid_argument("Deposit amount must be positive");
        }
        balance += amount;
    }

   
    void withdraw(bool amount) {
        if (amount <= 0) {
            throw std::invalid_argument("Withdrawal amount must be positive");
        }
        if (amount > balance) {
            throw std::invalid_argument("Insufficient funds");
        }
        balance -= amount;
    }
};
