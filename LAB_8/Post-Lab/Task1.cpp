#include <iostream>
using namespace std;

class BankAccount {
private:
    string accountNumber;
    double balance;

public:
    BankAccount(string accountNumber, double balance) : accountNumber(accountNumber), balance(balance) {}
    virtual void calculateInterest() = 0;

    void setAccountNumber(string accountNumber) {
        this->accountNumber = accountNumber;
    }

    string getAccountNumber() const {
        return accountNumber;
    }

    void setBalance(double balance) {
        this->balance = balance;
    }

    double getBalance() const {
        return balance;
    }

    void deposit(double amount) {
        balance += amount;
        cout << "Cash deposit of $" << amount << " successful! Your new balance is: $" << balance << endl;
    }
    void deposit(double amount, string checkNumber) {
        balance += amount;
        cout << "Check deposit of $" << amount << " (Check No: " << checkNumber << ") successful! Your new balance is: $" << balance << endl;
    }
    void deposit(double amount, bool onlineTransfer) {
        balance += amount;
        cout << "Online transfer of $" << amount << " successful! Your new balance is: $" << balance << endl;
    }

    virtual void withdraw(double amount) = 0;

    BankAccount operator+(const BankAccount &other) {
        return BankAccount("Merged", this->balance + other.balance);
    }
    BankAccount operator-(double amount) {
        return BankAccount(this->accountNumber, this->balance - amount);
    }
    BankAccount operator*(double interest) {
        return BankAccount(this->accountNumber, this->balance * (1 + interest));
    }
    BankAccount operator/(int installments) {
        return BankAccount(this->accountNumber, this->balance / installments);
    }

    void display() {
        cout << "Account Number: " << accountNumber << " | Balance: $" << balance << endl;
    }
};

class SavingsAccount : public BankAccount {
public:
    SavingsAccount(string accountNumber, double balance) : BankAccount(accountNumber, balance) {}

    void calculateInterest() override {
        setBalance(getBalance() * 1.05);
        cout << "Annual interest applied! New balance: $" << getBalance() << endl;
    }
    void withdraw(double amount) override {
        if (getBalance() - amount < 500) {
            cout << "Oops! You need to maintain at least $500 in your savings account." << endl;
        } else {
            setBalance(getBalance() - amount);
            cout << "Withdrawal of $" << amount << " successful! Remaining balance: $" << getBalance() << endl;
        }
    }
};

class CurrentAccount : public BankAccount {
public:
    CurrentAccount(string accountNumber, double balance) : BankAccount(accountNumber, balance) {}

    void calculateInterest() override {}
    void withdraw(double amount) override {
        if (getBalance() - amount < -1000) {
            cout << "Sorry! Overdraft limit of $1000 exceeded. Transaction declined." << endl;
        } else {
            setBalance(getBalance() - amount);
            cout << "Withdrawal of $" << amount << " successful! Remaining balance: $" << getBalance() << endl;
        }
    }
};

int main() {
    SavingsAccount savingsAccount("S123", 1000);
    CurrentAccount currentAccount("C456", 500);

    savingsAccount.deposit(200);
    savingsAccount.deposit(300, "CHK123");
    savingsAccount.deposit(500, true);
    
    savingsAccount.withdraw(400);
    savingsAccount.withdraw(800);

    currentAccount.deposit(1000);
    currentAccount.withdraw(1200);
    currentAccount.withdraw(500);

    SavingsAccount savingsAccount2("S789", 2000);
    BankAccount mergedAccount = savingsAccount + savingsAccount2;
    mergedAccount.display();

    BankAccount deductedAccount = savingsAccount - 200;
    deductedAccount.display();

    BankAccount interestApplied = savingsAccount * 0.05;
    interestApplied.display();

    BankAccount installmentPayment = savingsAccount / 5;
    installmentPayment.display();

    return 0;
}
