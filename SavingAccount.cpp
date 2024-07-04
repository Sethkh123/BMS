#pragma once
#include <vector>
#include <iostream>
#include <algorithm>
#include <string>
#include <stdexcept>
#include "Account.cpp"

class SavingAccount : public Account {
private:
    double interestRate;

public:
    SavingAccount(const std::string& name, int id, std::string phone, double interestRate)
        : interestRate(interestRate) {
        this->name = name;
        this->id = id;
        this->phone = phone;
    }

    std::string getType() const override {
        return "Saving Account";
    }

    double getInterestRate() const {
        return interestRate;
    }

    void setInterestRate(double rate) {
        if (rate < 0) {
            throw std::invalid_argument("Interest rate cannot be negative");
        }
        interestRate = rate;
    }
};
