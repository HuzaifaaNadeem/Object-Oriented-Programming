#include <iostream>
#include <string>
using namespace std;

class Currency {
protected:
    double amount;
    string currency_code;
    string currency_symbol;
    double exchange_rate;
public:
    Currency(double amt, string code, string symbol, double rate)
        : amount(amt), currency_code(code), currency_symbol(symbol), exchange_rate(rate) {}

    virtual double convert_to_base() const {
        return amount * exchange_rate;
    }

    virtual void display_currency() const {
        cout << currency_symbol << amount << " (" << currency_code << ")" << endl;
    }

    virtual double convert_to(const Currency &target_currency) const {
        double base_value = convert_to_base();
        return base_value / target_currency.exchange_rate;
    }

    virtual ~Currency() {}
};

class Dollar : public Currency {
public:
    Dollar(double amt) : Currency(amt, "USD", "$", 1.0) {} 

    void display_currency() const override {
        cout << currency_symbol << amount << " (US Dollar)" << endl;
    }
};

class Euro : public Currency {
public:
    Euro(double amt) : Currency(amt, "EUR", "€", 1.1) {} 

    void display_currency() const override {
        cout << currency_symbol << amount << " (Euro)" << endl;
    }
};

class Rupee : public Currency {
public:
    Rupee(double amt) : Currency(amt, "INR", "₹", 0.012) {} 

    void display_currency() const override {
        cout << currency_symbol << amount << " (Indian Rupee)" << endl;
    }
};

int main() {
    Dollar usd(100);
    Euro eur(50);
    Rupee inr(5000);

    cout << "Original Currencies:\n";
    usd.display_currency();
    eur.display_currency();
    inr.display_currency();

    cout << "\nConversions:\n";
    cout << "100 USD to EUR: " << usd.convert_to(eur) << " EUR" << endl;
    cout << "50 EUR to INR: " << eur.convert_to(inr) << " INR" << endl;
    cout << "5000 INR to USD: " << inr.convert_to(usd) << " USD" << endl;

    return 0;
}
