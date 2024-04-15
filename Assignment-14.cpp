#include <iostream>
#include <vector>

class MenuItem {
protected:
    std::string itemName;
    double itemPrice;

public:
    MenuItem(std::string name, double price) : itemName(name), itemPrice(price) {}

    virtual double getPrice() const {
        return itemPrice;
    }
};

class FoodItem : public MenuItem {
public:
    FoodItem(std::string name, double price) : MenuItem(name, price) {}

    double getPrice() const override {
        return itemPrice * 1.1;
    }
};

class DrinkItem : public MenuItem {
public:
    DrinkItem(std::string name, double price) : MenuItem(name, price) {}

    double getPrice() const override {
        return itemPrice * 1.05;
    }
};

class Order {
private:
    std::vector<MenuItem*> orderedItems;

public:
    void addItem(MenuItem* item) {
        orderedItems.push_back(item);
    }

    double calculateTotal() const {
        double totalBill = 0.0;
        for (const auto item : orderedItems) {
            totalBill += item->getPrice();
        }
        return totalBill;
    }
};

int main() {
    FoodItem burger("Burger", 5.99);
    DrinkItem coke("Coke", 1.99);

    Order customerOrder;
    customerOrder.addItem(&burger);
    customerOrder.addItem(&coke);

    std::cout << "Total bill: $" << customerOrder.calculateTotal() << std::endl;

    return 0;
}

