#include <iostream>
#include <fstream>
#include <iomanip>
#include "CustomerApplication.cpp"
#include "AccountApplication.cpp"
#include "DataValidInput.cpp"
#include "display.cpp"
using namespace std;

class Application {
private:
    enum MainMenu {Customer = 1, Account, EXIT};
    enum LoginMenu {LOGIN = 1, REGIS};

public:
    void run() {
        int choice, choicelogin;
        while (true) {
            LoginDisplay();
            choicelogin = DataValidInput::getIntInput("Enter your choice: ");
            switch (choicelogin) {
                case LOGIN:
                  
                    break;
                default:
                    cout << "Invalid choice. Please try again.\n";
                    break;
            }

            displayMain();
            choice = DataValidInput::getIntInput("Enter your choice: ");
            switch (choice) {
                case Customer:
                    CustomerApplication customerApp;
                    customerApp.run();
                    break;
                case Account:
                    AccountApplication accountApp;
                    accountApp.run();
                    break;
                case EXIT:
                    cout << "Exiting Program." << endl;
                    return;
                default:
                    cout << "Invalid input. Please try again." << endl;
                    break;
            }
        }
    }
};
