#include <iostream>
#include <string>

using namespace std;

class Currency {
protected:
    double amount;
    string currency_code;
    double exchange_rate;

public:
    Currency(double amt, string code, double rate)
        : amount(amt), currency_code(code), exchange_rate(rate) {}

    virtual double convert_to_base() const {
        return amount * exchange_rate;
    }

    virtual void display_currency() const {
        cout << currency_code << " " << amount << endl;
    }

    virtual ~Currency() {}
};

class PKR : public Currency {
public:
    PKR(double amt) : Currency(amt, "PKR", 0.0036) {}

    void display_currency() const override {
        cout << "PKR " << amount << endl;
    }
};

class Dollar : public Currency {
public:
    Dollar(double amt) : Currency(amt, "USD", 1.0) {}

    void display_currency() const override {
        cout << "USD " << amount << endl;
    }
};

class Euro : public Currency {
public:
    Euro(double amt) : Currency(amt, "EUR", 1.1) {}

    void display_currency() const override {
        cout << "EUR " << amount << endl;
    }
};

int main() {
    PKR pkr(1000);
    Dollar usd(10);
    Euro eur(20);

    cout << "Original Amounts:" << endl;
    pkr.display_currency();
    usd.display_currency();
    eur.display_currency();

    cout << "\nConverted to Base (USD):" << endl;
    cout << "PKR to USD: " << pkr.convert_to_base() << endl;
    cout << "USD to USD: " << usd.convert_to_base() << endl;
    cout << "EUR to USD: " << eur.convert_to_base() << endl;

    return 0;
}
