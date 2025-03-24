#include <iostream>
using namespace std;

class Account {
private:
    string AccNum;
    string AccHolder;
    double Balance;

public:
    Account(string number, string holder, double balance)
        : AccNum(number), AccHolder(holder), Balance(balance) {}

    Account operator+(const Account &Account1) const {
        return Account(AccNum, AccHolder, Balance + Account1.Balance);
    }

    Account &operator-=(double amount) {
        if (amount <= Balance) {
            Balance -= amount;
        } else {
            cout << "Insufficient balance!\n";
        }
        return *this;
    }

    bool operator>(const Account &Account1) const {
        return Balance > Account1.Balance;
    }

    string get_AccHolder() const { return AccHolder; }
    double get_Balance() const { return Balance; }

    friend ostream &operator<<(ostream &out, const Account &acc) {
        out << "Account: " << acc.AccHolder << ", Balance: $" << acc.Balance;
        return out;
    }
};

int main() {
    Account acc_1("001", "Shafique Rehman", 5000);
    Account acc_2("002", "Talha", 3000);

    cout << acc_1 << endl;
    cout << acc_2 << endl;

    Account total_balance = acc_1 + acc_2;
    cout << "\nAfter Addition:\n" << total_balance << endl;

    acc_1 -= 2000;
    acc_2 = Account("002", acc_2.get_AccHolder(), acc_2.get_Balance() + 2000);

    cout << "\nAfter Transfer:\n";
    cout << acc_1 << endl;
    cout << acc_2 << endl;

    cout << "\nComparison:\n";
    if (acc_1 > acc_2) {
        cout << acc_1.get_AccHolder() << " has more balance.\n";
    } else {
        cout << acc_2.get_AccHolder() << " has more balance.\n";
    }

    return 0;
}

