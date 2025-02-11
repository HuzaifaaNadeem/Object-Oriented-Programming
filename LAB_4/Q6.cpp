#include <iostream>
using namespace std;

class BankAccount {
private:
    int accountNumber;
    string ownerName;
    double balance;

public:
    BankAccount(int accNumber, string owner, double initialBalance = 0.0)
        : accountNumber(accNumber), ownerName(owner), balance(initialBalance) {}

    void deposit(double amount) {
        if (amount > 0) balance += amount;
    }

    void withdraw(double amount) {
        if (amount <= balance) balance -= amount;
    }

    void display() const {
        cout << "Account Number: " << accountNumber << "\n";
        cout << "Owner Name: " << ownerName << "\n";
        cout << "Balance: $" << balance << "\n";
    }
};

int main() {
    BankAccount account1(12345, "Saim Noman", 1000.0);
    BankAccount account2(67890, "Syed Rafay Mehdi");

    account1.display();
    account2.display();

    account1.deposit(500.0);
    account2.deposit(200.0);

    account1.display();
    account2.display();

    account1.withdraw(300.0);
    account2.withdraw(50.0);

    account1.display();
    account2.display();

    return 0;
}

