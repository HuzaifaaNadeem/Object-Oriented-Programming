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
        cout << "Cash deposit of Rs." << amount << " successful! Your new balance is: Rs." << balance << endl;
    }
    void depositByCheck(double amount, string checkNumber) {
        balance += amount;
        cout << "Check deposit of Rs." << amount << " (Check No: " << checkNumber << ") successful! Your new balance is: Rs." << balance << endl;
    }
    void depositOnline(double amount) {
        balance += amount;
        cout << "Online transfer of Rs." << amount << " successful! Your new balance is: Rs." << balance << endl;
    }

    virtual void withdraw(double amount) = 0;
    virtual void display() = 0;
};

class SavingsAccount : public BankAccount {
public:
    SavingsAccount(string accountNumber, double balance) : BankAccount(accountNumber, balance) {}

    void calculateInterest() override {
        setBalance(getBalance() * 1.05);
        cout << "Annual interest applied! New balance: Rs." << getBalance() << endl;
    }
    void withdraw(double amount) override {
        if (getBalance() - amount < 500) {
            cout << "Oops! You need to maintain at least Rs.500 in your savings account." << endl;
        } else {
            setBalance(getBalance() - amount);
            cout << "Withdrawal of Rs." << amount << " successful! Remaining balance: Rs." << getBalance() << endl;
        }
    }
    
    void display() override {
        cout << "Savings Account - Account Number: " << getAccountNumber() << " | Balance: Rs." << getBalance() << endl;
    }

    SavingsAccount operator+(const SavingsAccount &other) {
        return SavingsAccount("Merged", this->getBalance() + other.getBalance());
    }
    SavingsAccount operator-(double amount) {
        return SavingsAccount(this->getAccountNumber(), this->getBalance() - amount);
    }
    SavingsAccount operator*(double interest) {
        return SavingsAccount(this->getAccountNumber(), this->getBalance() * (1 + interest));
    }
    SavingsAccount operator/(int installments) {
        return SavingsAccount(this->getAccountNumber(), this->getBalance() / installments);
    }
};

class CurrentAccount : public BankAccount {
public:
    CurrentAccount(string accountNumber, double balance) : BankAccount(accountNumber, balance) {}

    void calculateInterest() override {}
    void withdraw(double amount) override {
        if (getBalance() - amount < -1000) {
            cout << "Sorry! Overdraft limit of Rs.1000 exceeded. Transaction declined." << endl;
        } else {
            setBalance(getBalance() - amount);
            cout << "Withdrawal of Rs." << amount << " successful! Remaining balance: Rs." << getBalance() << endl;
        }
    }
    
    void display() override {
        cout << "Current Account - Account Number: " << getAccountNumber() << " | Balance: Rs." << getBalance() << endl;
    }
};

int main() {
    SavingsAccount savingsAccount("S123", 1000);
    CurrentAccount currentAccount("C456", 500);

    savingsAccount.deposit(200);
    savingsAccount.depositByCheck(300, "BAHBL0948338");
    savingsAccount.depositOnline(500);
    
    savingsAccount.withdraw(400);
    savingsAccount.withdraw(800);

    currentAccount.deposit(1000);
    currentAccount.withdraw(1200);
    currentAccount.withdraw(500);

    SavingsAccount savingsAccount2("S789", 2000);
    SavingsAccount mergedAccount = savingsAccount + savingsAccount2;
    mergedAccount.display();

    SavingsAccount deductedAccount = savingsAccount - 200;
    deductedAccount.display();

    SavingsAccount interestApplied = savingsAccount * 0.05;
    interestApplied.display();

    SavingsAccount installmentPayment = savingsAccount / 5;
    installmentPayment.display();

    return 0;
}
