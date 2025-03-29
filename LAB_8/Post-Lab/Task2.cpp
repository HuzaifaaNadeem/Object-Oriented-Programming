#include <iostream>
using namespace std;

class Product {
protected:
    string product_id;
    double price;

public:
    Product(string id, double cost) : product_id(id), price(cost) {}
    virtual double calculate_price() = 0;
    void set_price(double new_price) { price = new_price; }
    double get_price() const { return price; }
    string get_product_id() const { return product_id; }
};

class Electronics : public Product {
public:
    Electronics(string id, double cost) : Product(id, cost) {}
    double calculate_price() override {
        return price * 1.15;
    }
};

class Clothing : public Product {
public:
    Clothing(string id, double cost) : Product(id, cost) {}
    double calculate_price() override {
        return price * 1.05;
    }
};

class ShoppingCart {
private:
    Product** items;
    int item_count;
    int capacity;

public:
    ShoppingCart(int max_items = 10) : item_count(0), capacity(max_items) {
        items = new Product*[capacity];
    }
    ~ShoppingCart() {
        delete[] items;
    }
    void add_item(Product* product) {
        if (item_count < capacity) {
            items[item_count++] = product;
        }
    }
    void apply_percentage_discount(double percentage) {
        for (int i = 0; i < item_count; i++) {
            items[i]->set_price(items[i]->get_price() * (1 - percentage / 100));
        }
    }
    void apply_fixed_discount(double amount) {
        for (int i = 0; i < item_count; i++) {
            items[i]->set_price(items[i]->get_price() - amount);
        }
    }
    void buy_one_get_one_free() {
        if (item_count < capacity && item_count > 0) {
            items[item_count] = items[item_count - 1];
            item_count++;
        }
    }
    ShoppingCart merge_with(const ShoppingCart &other) {
        ShoppingCart merged_cart(capacity + other.capacity);
        for (int i = 0; i < item_count; i++) {
            merged_cart.add_item(items[i]);
        }
        for (int i = 0; i < other.item_count; i++) {
            merged_cart.add_item(other.items[i]);
        }
        return merged_cart;
    }
    ShoppingCart remove_item(Product* product) {
        ShoppingCart updated_cart(capacity);
        for (int i = 0; i < item_count; i++) {
            if (items[i]->get_product_id() != product->get_product_id()) {
                updated_cart.add_item(items[i]);
            }
        }
        return updated_cart;
    }
    ShoppingCart apply_bulk_discount(double discount) {
        ShoppingCart discounted_cart = *this;
        discounted_cart.apply_percentage_discount(discount);
        return discounted_cart;
    }
    ShoppingCart split_bill(int users) {
        ShoppingCart split_cart = *this;
        for (int i = 0; i < split_cart.item_count; i++) {
            split_cart.items[i]->set_price(split_cart.items[i]->get_price() / users);
        }
        return split_cart;
    }
    void display_cart() {
        double total = 0;
        cout << "Shopping Cart:\n";
        for (int i = 0; i < item_count; i++) {
            cout << "Product: " << items[i]->get_product_id() << " | Price: $" << items[i]->calculate_price() << endl;
            total += items[i]->calculate_price();
        }
        cout << "Total Amount: $" << total << "\n";
    }
};

int main() {
    Electronics laptop("E123", 1000);
    Clothing tshirt("C456", 50);

    ShoppingCart cart1;
    cart1.add_item(&laptop);
    cart1.add_item(&tshirt);
    cart1.display_cart();
    
    cart1.apply_percentage_discount(10);
    cout << "After 10% discount:\n";
    cart1.display_cart();
    
    ShoppingCart cart2;
    Electronics phone("E789", 800);
    cart2.add_item(&phone);
    
    ShoppingCart merged_cart = cart1.merge_with(cart2);
    cout << "After merging carts:\n";
    merged_cart.display_cart();
    
    ShoppingCart discounted_cart = merged_cart.apply_bulk_discount(5);
    cout << "After bulk discount:\n";
    discounted_cart.display_cart();
    
    ShoppingCart split_cart = merged_cart.split_bill(2);
    cout << "After splitting the total among 2 users:\n";
    split_cart.display_cart();
    
    return 0;
}
