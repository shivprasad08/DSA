// Name: Shivprasad A. Mahind
// PRN: 123B1B266
// ASSIGNMENT-9A
/* a] Implement a restaurant waitlist system using the queue data structure. Restaurant waitlist provide following facility:
     a. Add Party to Waitlist b. Seat Party c. Display Waitlist */

#include <iostream>
#include <string>

using namespace std;

// Class to represent a party in the waitlist
class Party
{
public:
    string name;
    int size;
    Party *next;

    // Constructor to initialize party's name and size
    Party(string n, int s) : name(n), size(s), next(nullptr) {}
};

// Class to manage the waitlist using a queue (FIFO) structure
class Waitlist
{
private:
    Party *front;
    Party *rear;

public:
    // Constructor to initialize an empty waitlist
    Waitlist() : front(nullptr), rear(nullptr) {}

    // Function to add a new party to the waitlist
    void addParty(const string& name, int size)
    {
        Party *newParty = new Party(name, size);

        if(rear == nullptr)
        {
            front = rear = newParty;
        }
        else
        {
            rear->next = newParty;
            rear = newParty;
        }
        cout << "Party: " << name << " added to waitlist.\n";
    }

    // Function to seat the party at the front of the waitlist
    void seatParty()
    {
        if(front == nullptr)
        {
            cout << "No parties in the waitlist to seat.\n" << endl;
            return;
        }

        Party *seatedParty = front;
        cout << "Seating party '" << seatedParty->name << "' of size " << seatedParty->size << ".\n";
        front = front->next;

        if(front == nullptr)
        {
            rear = nullptr;
        }

        delete seatedParty;
    }

    // Function to display the current waitlist
    void displayWaitlist()
    {
        if(front == nullptr)
        {
            cout << "Waitlist is currently empty.\n" << endl;
            return;
        }

        cout << "Current waitlist: \n";
        Party *current = front;

        while(current != nullptr)
        {
            cout << "Party: '" << current->name << "', Size: " << current->size << '\n';
            current = current->next;
        }
    }

    // Destructor to clean up any remaining parties in the waitlist
    ~Waitlist()
    {
        while(front != nullptr) // Delete all the parties one by one
        {
            Party *temp = front;
            front = front->next;
            delete temp;
        }
    }
};

// Main function to drive the menu-based waitlist system
int main()
{
    Waitlist waitlist;
    string name;
    int choice;
    int size;


    cout << "\nRestaurant Waitlist System\n";
    cout << "1. Add party to the waitlist.\n";
    cout << "2. Seat party.\n";
    cout << "3. Display waitlist\n";
    cout << "4. Exit\n";

    do
    {
        cout << "Enter your choice: ";
        cin >> choice;

        switch(choice)
        {
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
    } while(choice != 4);

    return 0;
}

