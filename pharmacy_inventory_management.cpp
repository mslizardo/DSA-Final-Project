#include <iostream>
#include <string>
#include <map>
#include <limits>
using namespace std;

struct Item{
    int id;
    string name;
    double price;
    int quantity;
};

map<int, Item> inventory;

void clearScreen() {
    #ifdef _WIN32
        system("cls");
    #else
        system("clear");
    #endif
}

void addItem();
void searchItem();
void deleteItem();
void viewInventory();

//Prompts the user for details, formats outputs, and saves on verification
void addItem() {
    clearScreen();
    Item newItem{};
    char saveChoice = '\0';

    while (true) {
        cout << "=== ADD ITEM ===" << endl;
        cout << "ID: ";
        if (!(cin >> newItem.id)) {
            cout << "Invalid input. Please enter a valid integer ID." << endl;
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            continue;
        }

        if (inventory.find(newItem.id) != inventory.end()) {
            cout << "ID already exists. Please enter a unique ID." << endl;
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            continue;
        }

        break;
    }

    while (true) {
        cout << "NAME: ";
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        getline(cin, newItem.name);

        if (newItem.name.empty()) {
            cout << "Name cannot be empty. Please enter a valid name." << endl;
        } else {
            break;
        }
    }

    while (true) {
        cout << "PRICE: ";
        if (!(cin >> newItem.price)) {
            cout << "Invalid input. Please enter a valid price." << endl;
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
        } else if (newItem.price <= 0) {
            cout << "Price must be greater than 0." << endl;
        } else {
            break;
        }
    }

    while (true) {
        cout << "QUANTITY: ";
        if (!(cin >> newItem.quantity)) {
            cout << "Invalid input. Please enter a valid quantity." << endl;
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
        } else if (newItem.quantity < 0) {
            cout << "Quantity cannot be negative." << endl;
        } else {
            break;
        }
    }

    while (true) {
        cout << "SAVE THE RECORD (y/n)? ";
        if (!(cin >> saveChoice)) {
            cout << "Invalid input. Please enter 'y' or 'n'." << endl;
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            continue;
        }

        if (saveChoice == 'y' || saveChoice == 'Y') {
            inventory[newItem.id] = newItem;
            cout << "\nRecord saved successfully!" << endl;
            break;
        } else if (saveChoice == 'n' || saveChoice == 'N') {
            cout << "\nRecord discarded." << endl;
            break;
        } else {
            cout << "Please enter 'y' or 'n'." << endl;
        }
    }

    cout << "\nPress Enter to return to menu";
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
    cin.get();
}

// Prompts the user for an ID, searches the inventory, and displays the result
void searchItem() { 
    clearScreen();
    int searchId;
 
    cout << "=== SEARCH ITEM ===" << endl;
    cout << "Enter the ID to be searched: ";
    while (!(cin >> searchId)) {
        cout << "Invalid input. Please enter a valid ID." << endl;
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
    }
    
    if (inventory.find(searchId) != inventory.end()) {
        Item found = inventory[searchId];
        cout << "\nItem Found!" << endl;
        cout << "ID:       " << found.id << endl;
        cout << "Name:     " << found.name << endl;
        cout << "Price:    " << found.price << endl;
        cout << "Quantity: " << found.quantity << endl;
    } else {
        cout << "\nItem ID '" << searchId << "' not found." << endl;
    }
 
    cout << "\nPress Enter to return to menu...";
    cin.clear();
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
    cin.get();
}

// Prompts the user for an ID, searches the inventory, and deletes the item if found
void deleteItem() {
    clearScreen();
 
    int itemId;
 
    cout << "===== DELETE ITEM =====" << endl;
    
    while (true) {
        cout << "Enter ID: ";
        if (!(cin >> itemId)) {
            cout << "Invalid input. Please enter a valid ID." << endl;
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            continue;
        }
        break;
    }
    
    auto it = inventory.find(itemId);
 
    if (it != inventory.end()) {
        cout << "Are you sure you want to delete this item? (y/n): ";
        char confirm;
        while (!(cin >> confirm)) {
            cout << "Invalid input. Please enter 'y' or 'n'." << endl;
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            continue;
        }
        if (confirm != 'y' && confirm != 'Y') {
            cout << "\nDeletion cancelled." << endl;
            return;
        }
        inventory.erase(it);
        cout << "\nItem successfully deleted!" << endl;
    }
    else {
        cout << "\nItem not found!" << endl;
    }
 
    system("pause");
}

// Displays the entire inventory in a formatted table
void viewInventory() {
    clearScreen();
 
    cout << "========== INVENTORY ==========" << endl;
 
    if (inventory.empty()) {
        cout << "Inventory is empty." << endl;
    }
    else {
        cout << "ID\tItem Name\tPrice\tQuantity" << endl;
        cout << "----------------------------------------" << endl;
 
        for (auto item : inventory) {
            cout << item.second.id << "\t";
            cout << item.second.name << "\t\t";
            cout << item.second.price << "\t";
            cout << item.second.quantity << endl;
        }
    }
 
    system("pause");
}

void mainMenu() {
    int choice;
    while (true) {
        clearScreen();
        cout << "*********************" << endl;
        cout << "[1] ADD ITEM" << endl;
        cout << "[2] SEARCH ITEM" << endl;
        cout << "[3] DELETE ITEM" << endl;
        cout << "[4] VIEW INVENTORY" << endl;
        cout << "[5] BACK TO MAIN MENU" << endl;
        cout << "*********************" << endl;
        cout << "Enter your choice: ";  

        if (!(cin >> choice)) {
            cout << "Invalid input. Please enter a number." << endl;
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            continue;
        }

        switch (choice) {
            case 1:
                addItem(); break;
            case 2:
                searchItem(); break;
            case 3:
                deleteItem(); break;
            case 4:
                viewInventory(); break;
            case 5:
                clearScreen();
                return; break;
            default:
                cout << "Invalid choice. Please try again." << endl;
                cin.clear();
                cin.ignore(10000, '\n');
                break;
        }

    }
}

int main() {
    mainMenu();
    return 0;
}
