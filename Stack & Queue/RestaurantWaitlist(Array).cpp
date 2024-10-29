// Name: Shivprasad A. Mahind
// PRN: 123B1B266
// ASSIGNMENT-9A
/* a] Implement a restaurant waitlist system using the queue data structure. Restaurant waitlist provide following facility:
     a. Add Party to Waitlist b. Seat Party c. Display Waitlist */

#include <iostream>
#include <string>

using namespace std;

const int MAX_PARTIES = 100; // Maximum number of parties in the waitlist

class Party {
public:
    string name;
    int size;

    Party() : name(""), size(0) {} // Default constructor
    Party(string n, int s) : name(n), size(s) {} // Parameterized constructor
};

class Waitlist {
private:
    Party waitlist[MAX_PARTIES]; // Array to store parties
    int front; // Index of the front party
    int rear;  // Index of the rear party
    int count; // Number of parties in the waitlist

public:
    Waitlist() : front(0), rear(-1), count(0) {}

    // Function to add a party to the waitlist
    void addParty(const string& name, int size) {
        if (count >= MAX_PARTIES) {
            cout << "Waitlist is full. Cannot add more parties.\n";
            return;
        }
        rear = (rear + 1) % MAX_PARTIES; // Circular increment
        waitlist[rear] = Party(name, size);
        count++;
        cout << "Party: " << name << " added to waitlist.\n";
    }

    // Function to seat a party from the waitlist
    void seatParty() {
        if (count == 0) {
            cout << "No parties in the waitlist to seat.\n" << endl;
            return;
        }
        Party seatedParty = waitlist[front];
        cout << "Seating party '" << seatedParty.name << "' of size " << seatedParty.size << ".\n";
        front = (front + 1) % MAX_PARTIES; // Circular increment
        count--;
    }

    // Function to display the waitlist
    void displayWaitlist() {
        if (count == 0) {
            cout << "Waitlist is currently empty.\n" << endl;
            return;
        }

        cout << "Current waitlist: \n";
        for (int i = 0; i < count; i++) {
            int index = (front + i) % MAX_PARTIES; // Access in a circular manner
            cout << "Party: '" << waitlist[index].name << "', Size: " << waitlist[index].size << '\n';
        }
    }
};

int main() {
    Waitlist waitlist;
    string name;
    int choice;
    int size;

    cout << "\nRestaurant Waitlist System\n";
    cout << "1. Add party to the waitlist.\n";
    cout << "2. Seat party.\n";
    cout << "3. Display waitlist\n";
    cout << "4. Exit\n";

    do {
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                cout << "Enter Party name: ";
                cin.ignore();
                getline(cin, name);
                cout << "Enter size of the party: ";
                cin >> size;
                waitlist.addParty(name, size);
                break;
            case 2:
                waitlist.seatParty();
                break;
            case 3:
                waitlist.displayWaitlist();
                break;
            case 4:
                cout << "Exiting \n";
                break;
            default:
                cout << "Invalid choice. Try again." << endl;
        }
    } while (choice != 4);

    return 0;
}
