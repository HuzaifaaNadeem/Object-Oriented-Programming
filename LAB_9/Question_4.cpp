#include <iostream>
#include <string>
using namespace std;

class PaymentMethod {
public:
    virtual bool process_payment(double amount) = 0; 
    virtual ~PaymentMethod() {}
};


class CreditCard : public PaymentMethod {
private:
    string* card_number;

public:
    CreditCard(const string& number) {
        card_number = new string(number);
    }

    ~CreditCard() {
        delete card_number;
    }

    bool process_payment(double amount) override {
        if (amount <= 0) {
            cout << "Invalid payment amount. Transaction failed.\n";
            return false;
        }

        cout << "Credit Card Payment of $" << amount
             << " using card: " << *card_number << " successful.\n";
        return true;
    }
};


class DigitalWallet : public PaymentMethod {
private:
    double* wallet_balance;

public:
    DigitalWallet(double initial_balance) {
        wallet_balance = new double(initial_balance);
    }

    ~DigitalWallet() {
        delete wallet_balance;
    }

    bool process_payment(double amount) override {
        if (amount <= 0) {
            cout << "Invalid payment amount. Transaction failed.\n";
            return false;
        }

        if (amount > *wallet_balance) {
            cout << "Insufficient balance. Transaction failed.\n";
            return false;
        }

        *wallet_balance -= amount;
        cout << "Wallet Payment of $" << amount << " successful.\n";
        cout << "Remaining Wallet Balance: $" << *wallet_balance << endl;
        return true;
    }

    double get_balance() const {
        return *wallet_balance;
    }
};


int main() {
    
    PaymentMethod* payment1 = new CreditCard("4321-9876-5432-1098");
    PaymentMethod* payment2 = new DigitalWallet(150.0);

    cout << "\n--- Credit Card Payment ---\n";
    payment1->process_payment(60.0);

    cout << "\n--- Digital Wallet Payment ---\n";
    payment2->process_payment(100.0);

    cout << "\n--- Digital Wallet Payment (Insufficient Funds) ---\n";
    payment2->process_payment(100.0); 

    
    delete payment1;
    delete payment2;

    return 0;
}
