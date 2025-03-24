//Question 1:

#include <iostream>
using namespace std;

class Bank_Account {
private:
    double balance;
public:
    Bank_Account(double bal) : balance(bal) {}

    Bank_Account& operator+=(double amount) {
        balance += amount;
        return *this;
    }
};

//Question 2:

#include <iostream>
using namespace std;

class Bank_Account {
private:
    double balance;
public:
    Bank_Account(double bal) : balance(bal) {}

    friend Bank_Account operator+(const Bank_Account &acc, double amount) {
        return Bank_Account(acc.balance + amount);
    }
    
    void display() const {
        cout << "Balance: $" << balance << endl;
    }
};

int main() {
    Bank_Account acc(1000);
    Bank_Account new_acc = acc + 500; 
    new_acc.display(); 
}

//Question 3:

#include <iostream>
using namespace std;

class Bank_Account {
private:
    double balance;
public:
    Bank_Account(double bal) : balance(bal) {}

    friend void show_balance(const Bank_Account &acc);
};

void show_balance(const Bank_Account &acc) {
    cout << "Balance: $" << acc.balance << endl; 
}

int main() {
    Bank_Account acc(2000);
    show_balance(acc);
}
