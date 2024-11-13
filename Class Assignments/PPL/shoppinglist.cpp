#include <iostream>
#include <string>
using namespace std;

class ShoppingCart {
private:
    string storeItems[3] = {"Bread", "Milk", "Eggs"};  // Items in shop
    float storePrices[3] = {20, 15, 10};               // Corresponding prices
    string cartItems[3];                               // Initializing Items in cart
    int cartQuantities[3] = {0, 0, 0};                 // Initializing Quantities for each item in cart

public:
    // Addint item to cart function
    void addItem(string name, int quantity) {
        for (int i = 0; i < 3; i++) {
            if (storeItems[i] == name) {
                cartItems[i] = name;
                cartQuantities[i] += quantity;
                cout << quantity << " x " << name << " added to the cart." << endl;
                return;
            }
        }
        cout << "Item not found in the store!" << endl;
    }

    // Remove item from cart function
    void removeItem(string name) {
        for (int i = 0; i < 3; i++) {
            if (cartItems[i] == name) {
                cartItems[i] = "";
                cartQuantities[i] = 0;
                cout << name << " removed from the cart." << endl;
                return;
            }
        }
        cout << "Item not found in the cart!" << endl;
    }

    // Display cart function
    void displayCart() {
        float totalOrderPrice = 0;
        bool emptyCart = true;

        cout << "\nYour Cart:\n";
        for (int i = 0; i < 3; i++) {
            if (cartQuantities[i] > 0) {
                emptyCart = false;
                float totalPrice = storePrices[i] * cartQuantities[i];
                totalOrderPrice += totalPrice;
                cout << "Item: " << storeItems[i] << "\tPrice: " << storePrices[i] 
                     << "\tQuantity: x" << cartQuantities[i] << "\tTotal price = " << totalPrice << endl;
            }
        }

        if (emptyCart) {
            cout << "Your cart is empty." << endl;
        } else {
            cout << "Total order price: Rs. " << totalOrderPrice << endl;
        }
    }
};

int main() {
    ShoppingCart cart;
    int choice, quantity;
    string itemName;

    do {
        cout << "\n1. Add Item\n2. Remove Item\n3. View Cart\n4. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                cout << "Enter item name to add (Bread, Milk, Eggs): ";
                cin >> itemName;
                cout << "Enter quantity: ";
                cin >> quantity;
                cart.addItem(itemName, quantity);
                break;

            case 2:
                cout << "Enter item name to remove: ";
                cin >> itemName;
                cart.removeItem(itemName);
                break;

            case 3:
                cart.displayCart();
                break;

            case 4:
                cout << "Exiting..." << endl;
                break;

            default:
                cout << "Invalid choice! Please try again." << endl;
                break;
        }
    } while (choice != 4);

    return 0;
}
