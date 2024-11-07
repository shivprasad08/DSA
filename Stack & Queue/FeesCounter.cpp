// Name: Shivprasad A. Mahind
// PRN: 123B1B266
// Queue using linked list to help optimize fees collection processing at fees counter in a college

#include <iostream>
#include <string>

using namespace std;

// Node class to represent each student in the queue
class Node {
public:
    int roll;
    string name;
    Node *next;

    Node(int r, string n) : roll(r), name(n), next(nullptr) {}
};

// Queue class to manage the queue operations using linked list
class Queue {
private:
    Node *front;
    Node *rear;

public:
    Queue() : front(nullptr), rear(nullptr) {}

    // Function to add a student to the queue
    void StudentArrival(int roll, string name) {
        Node *newNode = new Node(roll, name);

        if (rear == nullptr) {
            front = rear = newNode;
        } else {
            rear->next = newNode;
            rear = newNode;
        }

        cout << "Student " << name << " with roll number " << roll << " has arrived at the counter.\n";
    }

    // Function to process fee payment (dequeue operation)
    void payFees() {
        if (front == nullptr) {
            cout << "No students waiting in the line to pay the fees.\n";
            return;
        }

        Node *temp = front;
        cout << "Processing fees for student " << temp->name << " with roll number " << temp->roll << ".\n";

        front = front->next;

        if (front == nullptr) {
            rear = nullptr;
        }

        delete temp;
    }

    // Function to display all students currently waiting in the queue
    void displayWaitingStudents() {
        if (front == nullptr) {
            cout << "No students are waiting in the line.\n";
            return;
        }

        Node *current = front;
        cout << "Students currently waiting in the line:\n";
        while (current != nullptr) {
            cout << "Roll number: " << current->roll << " Name: " << current->name << "\n";
            current = current->next;
        }
    }

    // Destructor to free memory allocated for the queue
    ~Queue() {
        while (front != nullptr) {
            Node *temp = front;
            front = front->next;
            delete temp;
        }
    }
};

int main() {
    Queue fq;
    int choice;
    int roll;
    string name;

    cout << "\n--- Fees Counter System ---\n";
    cout << "1. Arrival of student at fees counter\n";
    cout << "2. Pay fees\n";
    cout << "3. Display all waiting students\n";
    cout << "4. Exit\n";

    do {
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                cout << "Enter Student roll number: ";
                cin >> roll;
                cout << "Enter Student name: ";
                cin.ignore();
                getline(cin, name);
                fq.StudentArrival(roll, name);
                break;

            case 2:
                fq.payFees();
                break;

            case 3:
                fq.displayWaitingStudents();
                break;

            case 4:
                cout << "Exiting\n";
                break;

            default:
                cout << "Invalid choice. Please try again.\n";
        }
    } while (choice != 4);

    return 0;
}
