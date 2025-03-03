#include <iostream>
using namespace std;

class LoanHelper {
private:
    static const float interestRate;
    float loanAmount;
    int months;
    float rate;

public:
    LoanHelper(float amount, int monthsToRepay, float userRate) : loanAmount(amount), months(monthsToRepay) {
        rate = userRate;
    }

    void calculateMonthlyPayment() {
        float principalPayment = loanAmount / months;
        float monthlyPayment = principalPayment + (principalPayment * rate);
        cout << "You have to pay " << monthlyPayment << " every month for " 
             << months << " months to repay your loan." << endl;
    }

    static float getInterestRate() {
        return interestRate;
    }
};

const float LoanHelper::interestRate = 0.003;

int main() {
    float loanAmount;
    int months;
    float userInterestRate;

    cout << "Enter loan amount: $";
    cin >> loanAmount;
    cout << "Enter number of months to repay the loan: ";
    cin >> months;

    cout << "Enter interest rate (between 0 and 0.005): ";
    cin >> userInterestRate;

    if (userInterestRate < 0 || userInterestRate > 0.005) {
        cout << "Error: Invalid interest rate! Please enter a value between 0 and 0.005." << endl;
        return 1;
    }

    LoanHelper loan(loanAmount, months, userInterestRate);
    loan.calculateMonthlyPayment();

    return 0;
}
