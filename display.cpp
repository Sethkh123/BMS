#pragma once
#include <iostream>
#include <iomanip>
#include "Account.cpp"
using namespace std;

void displayAccount()  {
        std::cout << std::left << setw(20) <<"|Type"
                  << std::setw(20) << "ID"
                  << std::setw(15) << "Name"
                  << std::setw(20) << "phone"
                  << std::setw(20) << "Wallet|" <<endl;
        std::cout << "------------------------------------------------------------------------------" <<endl;
};
void displayCustomer() {
        std::cout << std::left << setw(20) <<"|Type"
                  << std::setw(20) << "ID"
                  << std::setw(15) << "Name"
                  << std::setw(15) << "FreeService" 
                  << std::setw(15) << "FullService" 
                  << std::setw(15) << "GetDiscount|"<< endl;
        std::cout << "----------------------------------------------------------------------------------------------" <<endl;
};
void displayMain(){
    std::cout <<"\n==============Welcome==============\n";
    std::cout <<"\n        1. Customer Management\n";
    std::cout <<"        2. Account Management\n";
    std::cout <<"        3. EXIT\n";
    std::cout <<"\n===================================\n";
};
void displayMenu(){
        std::cout << "======== Customer Management =======\n";
        std::cout << "\n       1. Add Customer\n";
        std::cout << "       2. Update Customer\n";
        std::cout << "       3. View Customer\n";
        std::cout << "       4. Delete Customer\n";
        std::cout << "       5. Back to Main Menu\n";
        std::cout << "\n===================================\n";
};
void displayMenuAccount(){
        std::cout << "========= Account Management ========\n";
        std::cout << "\n         1. Add Account\n";
        std::cout << "         2. Update Account\n";
        std::cout << "         3. View Account\n";
        std::cout << "         4. Delete Account\n";
        std::cout << "         5. Back to Main Menu\n";
        std::cout << "\n===================================\n";
};
void LoginDisplay(){
        std::cout <<"\n==============Welcome==============\n";
        std::cout <<"\n             1. LOGIN\n";
        std::cout <<"\n             2. REGISTER\n";
        std::cout <<"\n             3. EXIT\n";
        std::cout <<"\n===================================\n";
};


