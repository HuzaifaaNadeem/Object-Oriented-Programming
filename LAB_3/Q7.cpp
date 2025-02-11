#include <iostream>
using namespace std;

class Shop {
private:
    string products[100];
    double costs[100];
    int count;

public:
    Shop() : count(0) {}

    void addProduct(string product, double cost) {
        if (count < 100) {
            products[count] = product;
            costs[count] = cost;
            count++;
        } else {
            cout << "Product list is full!" << endl;
        }
    }

    void listProducts() {
        cout << "\nProducts available:" << endl;
        for (int i = 0; i < count; i++) {
            cout << i + 1 << ". " << products[i] << endl;
        }
    }

    void updateCost(int index, double newCost) {
        if (index >= 1 && index <= count) {
            costs[index - 1] = newCost;
            cout << "Cost updated successfully!" << endl;
        } else {
            cout << "Invalid product index!" << endl;
        }
    }

    void viewProducts() {
        cout << "\nProducts and Costs:" << endl;
        for (int i = 0; i < count; i++) {
            cout << i + 1 << ". " << products[i] << " - $" << costs[i] << endl;
        }
    }

    void generateBill(int purchasedProducts[], int quantities[], int numProducts) {
        double total = 0;
        cout << "\n--- Bill ---" << endl;
        for (int i = 0; i < numProducts; i++) {
            int index = purchasedProducts[i] - 1;
            if (index >= 0 && index < count) {
                double cost = costs[index] * quantities[i];
                total += cost;
                cout << products[index] << " x" << quantities[i] << " - $" << cost << endl;
            } else {
                cout << "Invalid product index in bill!" << endl;
            }
        }
        cout << "Total: $" << total << endl;
    }
};

int main() {
    Shop store;
    int choice;
    
    while (true) {
        cout << "\n--- Shop Menu ---" << endl;
        cout << "1. Add Product" << endl;
        cout << "2. List Products" << endl;
        cout << "3. Update Cost" << endl;
        cout << "4. View Products" << endl;
        cout << "5. Generate Bill" << endl;
        cout << "6. Exit" << endl;
        cout << "Enter your choice: ";
        cin >> choice;
        
        if (choice == 1) {
            string product;
            double cost;
            cout << "Enter product name: ";
            cin.ignore();
            getline(cin, product);
            cout << "Enter cost: $";
            cin >> cost;
            store.addProduct(product, cost);
        } else if (choice == 2) {
            store.listProducts();
        } else if (choice == 3) {
            int index;
            double newCost;
            cout << "Enter product index to update cost: ";
            cin >> index;
            cout << "Enter new cost: $";
            cin >> newCost;
            store.updateCost(index, newCost);
        } else if (choice == 4) {
            store.viewProducts();
        } else if (choice == 5) {
            int numProducts, purchasedProducts[100], quantities[100];
            cout << "Enter number of different products bought: ";
            cin >> numProducts;
            for (int i = 0; i < numProducts; i++) {
                cout << "Enter product index: ";
                cin >> purchasedProducts[i];
                cout << "Enter quantity: ";
                cin >> quantities[i];
            }
            store.generateBill(purchasedProducts, quantities, numProducts);
        } else if (choice == 6) {
            break;
        } else {
            cout << "Invalid choice! Try again." << endl;
        }
    }
    return 0;
}
