#include <iostream>
#include <string>
using namespace std;

class Account {
private:
    int accNum;
    string holderName;
    double accBalance;

public:
    Account(int num, string name, double balance)
        : accNum(num), holderName(name), accBalance(balance) {}

    void deposit(double amount) {
        if (amount > 0) {
            accBalance += amount;
        } else {
            cout << "Deposit amount must be positive." << endl;
        }
    }

    void withdraw(double amount) {
        if (amount > 0) {
            if (accBalance >= amount) {
                accBalance -= amount;
            } else {
                cout << "Insufficient funds." << endl;
            }
        } else {
            cout << "Withdrawal amount must be positive." << endl;
        }
    }

    void display() const {
        cout << "Account Number: " << accNum << endl;
        cout << "Account Holder: " << holderName << endl;
        cout << "Balance: " << accBalance << " rupees" << endl;
        cout << "------------------------------" << endl;
    }
};

int main() {
    Account accounts[] = {
        Account(101, "Ahmed", 1000.0),
        Account(102, "Ali", 1500.0),
        Account(103, "Babar", 2000.0)
    };

    for (int i = 0; i < 3; i++) {
        accounts[i].display();

        accounts[i].deposit(500.0);
        cout << "After deposit of 500.0 rupees:" << endl;
        accounts[i].display();

        accounts[i].withdraw(200.0);
        cout << "After withdrawal of 200.0 rupees:" << endl;
        accounts[i].display();
    }

    return 0;
}
