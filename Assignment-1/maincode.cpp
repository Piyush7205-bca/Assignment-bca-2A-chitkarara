#include <iostream>

using namespace std;

class BankAccount {
private:
    int userId;
    string password;
    double balance;

public:
    BankAccount(int id, string pass) : userId(id), password(pass), balance(0.0) {}

    bool login(int id, string pass) {
        return (userId == id && password == pass);
    }

    void deposit(double amount) {
        balance += amount;
    }

    bool withdraw(double amount) {
        if (amount <= balance) {
            balance -= amount;
            return true;
        }
        return false;
    }

    double getBalance() const {
        return balance;
    }
};

void printIntroMenu() {
    cout << "Hi! Welcome to Mr. Zamar’s ATM Machine!" << endl;
    cout << "Please select an option from the menu below:" << endl;
    cout << "l -> Login" << endl;
    cout << "c -> Create New Account" << endl;
    cout << "q -> Quit" << endl;
    cout << "> ";
}

void createAccount(BankAccount& account) {
    int userId;
    string password;

    cout << "Please enter your user id: ";
    cin >> userId;
    cout << "Please enter your password: ";
    cin >> password;

    account = BankAccount(userId, password);
    cout << "Thank You! Your account has been created!" << endl;
}

int main() {
    BankAccount account(0, ""); // Initialize with dummy values

    char choice;
    do {
        printIntroMenu();
        cin >> choice;

        if (choice == 'l') {
            int id;
            string pass;
            cout << "Please enter your user id: ";
            cin >> id;
            cout << "Please enter your password: ";
            cin >> pass;

            if (account.login(id, pass)) {
                cout << "Access Granted!" << endl;
                do {
                    cout << "d -> Deposit Money" << endl;
                    cout << "w -> Withdraw Money" << endl;
                    cout << "r -> Request Balance" << endl;
                    cout << "q -> Quit" << endl;
                    cout << "> ";
                    cin >> choice;

                    switch (choice) {
                        case 'd':
                            double depositAmount;
                            cout << "Amount of deposit: $";
                            cin >> depositAmount;
                            account.deposit(depositAmount);
                            break;
                        case 'w':
                            double withdrawAmount;
                            cout << "Amount of withdrawal: $";
                            cin >> withdrawAmount;
                            if (!account.withdraw(withdrawAmount)) {
                                cout << "Insufficient funds!" << endl;
                            }
                            break;
                        case 'r':
                            cout << "Your balance is $" << account.getBalance() << endl;
                            break;
                        case 'q':
                            cout << "Thanks for stopping by!" << endl;
                            break;
                        default:
                            cout << "Invalid choice. Please try again." << endl;
                    }
                } while (choice != 'q');
            } else {
                cout << "******** LOGIN FAILED! ********" << endl;
            }
        } else if (choice == 'c') {
            createAccount(account);
        } else if (choice != 'q') {
            cout << "Invalid choice. Please try again." << endl;
        }
    } while (choice != 'q');

    cout << "Assignment 1: C++ Course" << endl;
    return 0;
}
