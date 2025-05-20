#include <iostream>
using namespace std;

// ATM class definition
class ATM {
private:
    string userID;
    int pin;
    double balance;

public:
    // Constructor
    ATM(string uid, int p, double b) {
        userID = uid;
        pin = p;
        balance = b;
    }

    // Login method
    bool login(string inputID, int inputPin) {
        return (inputID == userID && inputPin == pin);
    }

    // Display menu options
    void showMenu() {
        cout << "\n===== ATM Main Menu =====" << endl;
        cout << "1. Check Balance" << endl;
        cout << "2. Deposit Money" << endl;
        cout << "3. Withdraw Money" << endl;
        cout << "4. Exit" << endl;
        cout << "=========================" << endl;
    }

    // Show current balance
    void checkBalance() {
        cout << "Your current balance is: ₹" << balance << endl;
    }

    // Deposit money
    void deposit(double amount) {
        if (amount > 0) {
            balance += amount;
            cout << "₹" << amount << " deposited successfully." << endl;
            checkBalance();
        } else {
            cout << "Invalid deposit amount." << endl;
        }
    }

    // Withdraw money
    void withdraw(double amount) {
        if (amount <= 0) {
            cout << "Invalid withdrawal amount." << endl;
        } else if (amount > balance) {
            cout << "Insufficient balance." << endl;
        } else {
            balance -= amount;
            cout << "₹" << amount << " withdrawn successfully." << endl;
            checkBalance();
        }
    }
};

// Main function
int main() {
    // Creating a sample user with ID, PIN, and initial balance
    ATM atm("user123", 4321, 10000.00);

    string enteredID;
    int enteredPin;

    cout << "===== Welcome to the ATM =====" << endl;

    // Login attempt
    cout << "Enter User ID: ";
    cin >> enteredID;
    cout << "Enter PIN: ";
    cin >> enteredPin;

    if (atm.login(enteredID, enteredPin)) {
        int choice;
        do {
            atm.showMenu();
            cout << "Enter your choice: ";
            cin >> choice;

            switch (choice) {
                case 1:
                    atm.checkBalance();
                    break;
                case 2: {
                    double depositAmount;
                    cout << "Enter amount to deposit: ₹";
                    cin >> depositAmount;
                    atm.deposit(depositAmount);
                    break;
                }
                case 3: {
                    double withdrawAmount;
                    cout << "Enter amount to withdraw: ₹";
                    cin >> withdrawAmount;
                    atm.withdraw(withdrawAmount);
                    break;
                }
                case 4:
                    cout << "Thank you for using the ATM. Goodbye!" << endl;
                    break;
                default:
                    cout << "Invalid choice. Please select again." << endl;
            }

        } while (choice != 4);
    } else {
        cout << "Authentication failed! Invalid User ID or PIN." << endl;
    }

    return 0;
}
