// Name: Shivprasad A. Mahind
// PRN: 123B1B266
// Assignment-11
/* Consider an employee database of N employees. Make use of a hash table implementation to
  quickly look up the employer's id number. */


#include <iostream>
#include <string>

using namespace std;

#define TABLE_SIZE 10  // Define hash table size

// Employee class to store employee details
class Employee {
public:
    int id;
    string name;
    bool occupied;  // Indicates if the slot is occupied

    Employee() : id(-1), name(""), occupied(false) {}
};

// HashTable class to implement hash table with linear probing
class HashTable {
private:
    Employee table[TABLE_SIZE];  // Array to hold employees

    // Simple hash function
    int hashFunction(int id) {
        return id % TABLE_SIZE;
    }

public:
    HashTable() {
        for (int i = 0; i < TABLE_SIZE; ++i) {
            table[i] = Employee();
        }
    }

    // Insert an employee into the hash table
    void insert(int id, std::string name) {
        int index = hashFunction(id);
        int originalIndex = index;
        bool inserted = false;

        // Linear probing to find the next available slot
        while (table[index].occupied) {
            // Check if the ID already exists to prevent duplicate entries
            if (table[index].id == id) {
                cout << "Employee ID " << id << " already exists.\n";
                return;
            }
            index = (index + 1) % TABLE_SIZE;
            if (index == originalIndex) {
                cout << "Hash table is full. Unable to insert employee.\n";
                return;
            }
        }

        table[index].id = id;
        table[index].name = name;
        table[index].occupied = true;
        cout << "Employee added successfully.\n";
    }

    // Search for an employee by ID
    void search(int id) {
        int index = hashFunction(id);
        int originalIndex = index;

        while (table[index].occupied) {
            if (table[index].id == id) {
                cout << "Employee found: ID=" << table[index].id
                          << ", Name=" << table[index].name << "\n";
                return;
            }
            index = (index + 1) % TABLE_SIZE;
            if (index == originalIndex) {
                break;
            }
        }
        cout << "Employee not found.\n";
    }

    // Remove an employee by ID
    void remove(int id) {
        int index = hashFunction(id);
        int originalIndex = index;

        while (table[index].occupied) {
            if (table[index].id == id) {
                table[index].id = -1;
                table[index].name = "";
                table[index].occupied = false;
                cout << "Employee removed successfully.\n";
                return;
            }
            index = (index + 1) % TABLE_SIZE;
            if (index == originalIndex) {
                break;
            }
        }
        cout << "Employee not found.\n";
    }

    // Display all employees
    void display() {
        for (int i = 0; i < TABLE_SIZE; ++i) {
            if (table[i].occupied) {
                cout << "Index " << i << ": [ID: " << table[i].id
                          << ", Name: " << table[i].name << "]\n";
            } else {
                cout << "Index " << i << ": Empty\n";
            }
        }
    }
};

int main() {
    HashTable hashTable;
    int choice, id;
    string name;

    cout << "\nEmployee Database Menu:\n";
    cout << "1. Add Employee\n";
    cout << "2. Search Employee by ID\n";
    cout << "3. Remove Employee by ID\n";
    cout << "4. Display All Employees\n";
    cout << "5. Exit\n";

    do {
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
        case 1:
            cout << "Enter Employee ID: ";
            cin >> id;
            cout << "Enter Employee Name: ";
            cin.ignore();
            getline(std::cin, name);
            hashTable.insert(id, name);
            break;
        case 2:
            cout << "Enter Employee ID to search: ";
            cin >> id;
            hashTable.search(id);
            break;
        case 3:
            cout << "Enter Employee ID to remove: ";
            cin >> id;
            hashTable.remove(id);
            break;
        case 4:
            cout << "All Employees:\n";
            hashTable.display();
            break;
        case 5:
            cout << "Exiting...\n";
            break;
        default:
            cout << "Invalid choice. Please try again.\n";
        }
    } while (choice != 5);

    return 0;
}
