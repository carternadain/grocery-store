#include <iostream>
#include <fstream>
#include <map>
#include <string>

using namespace std;

// Function types
void CreateBackupFile(const map<string, int>& itemFrequency);
void DisplayMenu();
void SearchItemFrequency(const map<string, int>& itemFrequency);
void PrintAllItems(const map<string, int>& itemFrequency);
void PrintHistogram(const map<string, int>& itemFrequency);

int main() {
    // Example item frequency map 
    map<string, int> itemFrequency;
    itemFrequency["Potatoes"] = 4;
    itemFrequency["Pumpkins"] = 5;
    itemFrequency["Onions"] = 3;

    // this creates the backup file
    CreateBackupFile(itemFrequency);

    int choice = 0;
    while (choice != 4) {
        // Displays the menu options
        DisplayMenu();
        cin >> choice;

        switch (choice) {
            case 1:
                SearchItemFrequency(itemFrequency);
                break;
            case 2:
                PrintAllItems(itemFrequency);
                break;
            case 3:
                PrintHistogram(itemFrequency);
                break;
            case 4:
                cout << "Exiting the program." << endl;
                break;
            default:
                cout << "Invalid option. Please try again." << endl;
        }
    }
    return 0;
}

// Function to create a backup data file "frequency.dat" 
void CreateBackupFile(const map<string, int>& itemFrequency) {
    ofstream backupFile("frequency.dat");
    if (backupFile.is_open()) {
        for (const auto& item : itemFrequency) {
            backupFile << item.first << " " << item.second << endl;
        }
        backupFile.close();
        cout << "Backup file 'frequency.dat' created successfully." << endl;
    } else {
        cout << "Error: Could not create backup file." << endl;
    }
}

// Function to display menu options
void DisplayMenu() {
    cout << "\nCorner Grocer Menu" << endl;
    cout << "1. Search for an item frequency" << endl;
    cout << "2. Print all items and frequencies" << endl;
    cout << "3. Print histogram of items" << endl;
    cout << "4. Exit" << endl;
    cout << "Enter your choice: ";
}

// Function to search for the frequency of a specific item
void SearchItemFrequency(const map<string, int>& itemFrequency) {
    string itemName;
    cout << "Enter the name of the item to search: ";
    cin >> itemName;

    auto it = itemFrequency.find(itemName);
    if (it != itemFrequency.end()) {
        cout << itemName << " appears " << it->second << " times." << endl;
    } else {
        cout << itemName << " not found in the list." << endl;
    }
}

// Function to print all items and their frequencies
void PrintAllItems(const map<string, int>& itemFrequency) {
    cout << "\nItem List with Frequencies:" << endl;
    for (const auto& item : itemFrequency) {
        cout << item.first << ": " << item.second << endl;
    }
}

// Function to print a histogram of items based on their frequencies
void PrintHistogram(const map<string, int>& itemFrequency) {
    cout << "\nHistogram of Items:" << endl;
    for (const auto& item : itemFrequency) {
        cout << item.first << ": ";
        for (int i = 0; i < item.second; ++i) {
            cout << "*";
        }
        cout << endl;
    }
}
