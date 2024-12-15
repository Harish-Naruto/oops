#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
using namespace std;

// Simple Item class
class Item {
    public:
        string name;
        int quantity;
        int cost;
        int code;

        // Input item details
        void input() {
            cout << "\nEnter Item Name: ";
            cin >> name;
            cout << "Enter Quantity: ";
            cin >> quantity;
            cout << "Enter Cost: ";
            cin >> cost;
            cout << "Enter Code: ";
            cin >> code;
        }

        // Display item details
        void display() {
            cout << "\nName: " << name
                 << "\nQuantity: " << quantity
                 << "\nCost: " << cost
                 << "\nCode: " << code << endl;
        }
};

class ItemStore {
    private:
        vector<Item> items;

    public:
        // Add new item
        void addItem() {
            Item item;
            item.input();
            items.push_back(item);
            cout << "\nItem added successfully!" << endl;
        }

        // Display all items
        void displayItems() {
            if(items.empty()) {
                cout << "\nNo items in store!" << endl;
                return;
            }
            
            cout << "\n----Item List----" << endl;
            for(auto& item : items) {
                item.display();
            }
        }

        // Search item by code
        void searchItem() {
            if(items.empty()) {
                cout << "\nNo items in store!" << endl;
                return;
            }

            int code;
            cout << "\nEnter Item Code to search: ";
            cin >> code;

            for(auto& item : items) {
                if(item.code == code) {
                    cout << "\nItem Found:" << endl;
                    item.display();
                    return;
                }
            }
            cout << "\nItem not found!" << endl;
        }

        // Sort items by cost
        void sortItems() {
            if(items.empty()) {
                cout << "\nNo items to sort!" << endl;
                return;
            }

            sort(items.begin(), items.end(), 
                [](Item& a, Item& b) { return a.cost < b.cost; });
            cout << "\nItems sorted by cost!" << endl;
        }

        // Delete item by code
        void deleteItem() {
            if(items.empty()) {
                cout << "\nNo items to delete!" << endl;
                return;
            }

            int code;
            cout << "\nEnter Item Code to delete: ";
            cin >> code;

            for(auto it = items.begin(); it != items.end(); ++it) {
                if(it->code == code) {
                    items.erase(it);
                    cout << "\nItem deleted successfully!" << endl;
                    return;
                }
            }
            cout << "\nItem not found!" << endl;
        }
};

int main() {
    ItemStore store;
    int choice;

    do {
        cout << "\n=== Item Management System ===" << endl;
        cout << "1. Add Item" << endl;
        cout << "2. Display All Items" << endl;
        cout << "3. Search Item" << endl;
        cout << "4. Sort Items by Cost" << endl;
        cout << "5. Delete Item" << endl;
        cout << "6. Exit" << endl;
        cout << "Enter your choice: ";
        cin >> choice;

        switch(choice) {
            case 1: store.addItem(); break;
            case 2: store.displayItems(); break;
            case 3: store.searchItem(); break;
            case 4: store.sortItems(); break;
            case 5: store.deleteItem(); break;
            case 6: cout << "\nExiting program...\n"; break;
            default: cout << "\nInvalid choice! Try again.\n";
        }
    } while(choice != 6);

    return 0;
}