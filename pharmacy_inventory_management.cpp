#include <iostream>
#include <string>
#include <map>
using namespace std;

struct Item{
    string name;
    double price;
    int quantity;
};

map<string, Item> inventory;

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
        cin >> choice;

        if (!(cin >> choice)) {
            cout << "Invalid input. Please enter a number." << endl;
            cin.clear();
            cin.ignore(10000, '\n');
            continue;
        }

        /* switch (choice) {
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
        } */

    }
}

int main() {
    mainMenu();
    return 0;
}