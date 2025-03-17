#include <iostream>

using namespace std;

class Account {
protected:
    string holder_name;
    int acc_number;
    double acc_balance;

public:
    Account(int number, string name, double balance) 
        : acc_number(number), holder_name(name), acc_balance(balance) {}

    virtual void deposit(double amount) {
        acc_balance += amount;
        cout << "Deposited: $" << amount << " | New Balance: $" << acc_balance << endl;
    }

    virtual void withdraw(double amount) {
        if (amount > acc_balance) {
            cout << "Insufficient funds!" << endl;
        } else {
            acc_balance -= amount;
            cout << "Withdrawn: $" << amount << " | Remaining Balance: $" << acc_balance << endl;
        }
    }

    virtual void calculate_interest() = 0;

    virtual void print_statement() const {
        cout << "Holder: " << holder_name << "\nNumber: " << acc_number << "\nBalance: $" << acc_balance << endl;
    }

    virtual ~Account() {}
};

class SavingsAccount : public Account {
private:
    double interest_rate;
    double min_balance;

public:
    SavingsAccount(int number, string name, double balance, double rate, double min_bal)
        : Account(number, name, balance), interest_rate(rate), min_balance(min_bal) {}

    void calculate_interest() override {
        double interest = acc_balance * (interest_rate / 100);
        acc_balance += interest;
        cout << "Interest added: $" << interest << " | New Balance: $" << acc_balance << endl;
    }

    void withdraw(double amount) override {
        if (acc_balance - amount < min_balance) {
            cout << "Cannot withdraw! Minimum balance required." << endl;
        } else {
            Account::withdraw(amount);
        }
    }
};

class CheckingAccount : public Account {
public:
    CheckingAccount(int number, string name, double balance)
        : Account(number, name, balance) {}

    void calculate_interest() override {
        cout << "Checking accounts do not earn interest." << endl;
    }
};

class FixedDepositAccount : public Account {
private:
    double fixed_rate;
    int maturity_years;

public:
    FixedDepositAccount(int number, string name, double balance, double rate, int years)
        : Account(number, name, balance), fixed_rate(rate), maturity_years(years) {}

    void calculate_interest() override {
        double interest = acc_balance * (fixed_rate / 100) * maturity_years;
        cout << "Total interest after " << maturity_years << " years: $" << interest << endl;
    }

    void withdraw(double) override {
        cout << "Withdrawal not allowed before maturity!" << endl;
    }
};

int main() {
    Account* acc1 = new SavingsAccount(101, "Alice", 5000, 5, 1000);
    Account* acc2 = new CheckingAccount(102, "Bob", 3000);
    Account* acc3 = new FixedDepositAccount(103, "Charlie", 10000, 6, 5);

    acc1->print_statement();
    acc1->calculate_interest();
    acc1->withdraw(500);
    cout << "------------------------\n";

    acc2->print_statement();
    acc2->calculate_interest();
    acc2->withdraw(500);
    cout << "------------------------\n";

    acc3->print_statement();
    acc3->calculate_interest();
    acc3->withdraw(500);
    cout << "------------------------\n";

    delete acc1;
    delete acc2;
    delete acc3;

    return 0;
}

