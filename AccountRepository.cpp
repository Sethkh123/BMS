#pragma once
#include <iostream>
#include <vector>
#include <algorithm>
#include <stdexcept>
#include <string>
#include "CheckingAccount.cpp"
#include "SavingAccount.cpp"
#include "DataValidInput.cpp"
#include "Account.cpp"

class AccountRepository {
public:
    virtual ~AccountRepository() {}

    virtual void addAccount(int id, std::string name, int type, std::string phone) = 0;
    virtual void viewAccount() = 0;
    virtual void updateAccount(int id) = 0;
    virtual void deleteAccount(int id) = 0;
};
