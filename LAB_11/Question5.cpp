#include <iostream>
#include <string>
#include <exception>
using namespace std;

class InsufficientFundsException : public exception {
    string errorMessage;
public:
    InsufficientFundsException(double shortfall) {
        errorMessage = "InsufficientFundsException - You're short by $" + to_string((int)shortfall) + ".00";
    }

    const char* what() const noexcept override {
        return errorMessage.c_str();
    }
};

template <typename T>
class BankAccount {
    T currentBalance;
public:
    BankAccount(T startingBalance) : currentBalance(startingBalance) {}

    void withdraw(T withdrawalAmount) {
        if (withdrawalAmount > currentBalance) {
            double shortage = static_cast<double>(withdrawalAmount - currentBalance);
            throw InsufficientFundsException(shortage);
        }
        currentBalance -= withdrawalAmount;
    }

    void displayBalance() {
        cout << "Your current balance is: $" << (int)currentBalance << ".00" << endl;
    }
};

int main() {
    BankAccount<double> myAccount(500.0);
    myAccount.displayBalance();

    try {
        myAccount.withdraw(600.0);
    } catch (const exception& e) {
        cout << "Attempted withdrawal of $600: " << e.what() << endl;
    }

    return 0;
}
