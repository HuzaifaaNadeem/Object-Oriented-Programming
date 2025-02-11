#include <iostream>
using namespace std;

class Account {
private:
    string accountNumber;
    string accountHolderName;
    double balance;

public:
    Account() : balance(0.0) {}

    Account(string accNum, string holderName, double initialBalance) 
        : accountNumber(accNum), accountHolderName(holderName), balance(initialBalance) {}

    void deposit(double amount) {
        if (amount > 0) {
            balance += amount;
            cout << "Deposited: $" << amount << " | New Balance: $" << balance << endl;
        } else {
            cout << "Invalid deposit amount." << endl;
        }
    }

    void withdraw(double amount) {
        if (amount > 0 && amount <= balance) {
            balance -= amount;
            cout << "Withdrawn: $" << amount << " | New Balance: $" << balance << endl;
        } else {
            cout << "Insufficient funds or invalid amount." << endl;
        }
    }

    void checkBalance() const {
        cout << "Account Holder: " << accountHolderName << " | Balance: $" << balance << endl;
    }
};

int main() {
    Account acc1("12345", "Aakif Abrar", 500.0);
    acc1.checkBalance();
    acc1.deposit(200.0);
    acc1.withdraw(100.0);
    acc1.withdraw(700.0);
    acc1.checkBalance();

    return 0;
}

