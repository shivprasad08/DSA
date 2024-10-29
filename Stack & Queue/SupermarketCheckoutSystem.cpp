// Name: Shivprasad A. Mahind
// PRN: 123B1B266
// Assignment-9B
/* Implement a checkout system for a supermarket to efficiently manage customer queues during peak hours.
   The system should support the following operations using a circular queue data structure:
   a. Customer arrival b. Customer checkout c. Close Checkout Counter d. View customer. */

#include <iostream>
#include <string>

using namespace std;

#define MAX 100 // Maximum size of the queue

class Customer {
public:
    int id;             // Customer ID
    string name;       // Customer Name

    Customer() : id(0), name("") {} // Default constructor
    Customer(int id, string name) : id(id), name(name) {} // Parameterized constructor
};

class CircularQueue {
private:
    Customer customers[MAX]; // Array to hold customers
    int front, rear;         // Front and rear indices

public:
    CircularQueue() : front(-1), rear(-1) {}

    bool isEmpty() {
        return front == -1; // Returns true if the queue is empty
    }

    bool isFull() {
        return (rear + 1) % MAX == front; // Returns true if the queue is full
    }

    void enqueue(Customer customer) {
        if (isFull()) {
            cout << "Checkout counter is full. Cannot add customer: " << customer.name << endl;
            return;
        }
        if (isEmpty()) {
            front = rear = 0; // Initialize front and rear
        } else {
            rear = (rear + 1) % MAX; // Move rear to the next position
        }
        customers[rear] = customer; // Add customer to the queue
        cout << "Customer added: " << customer.name << endl;
    }

    Customer dequeue() {
        if (isEmpty()) {
            cout << "Checkout counter is empty. No customer to checkout." << endl;
            return Customer(); // Return default customer on underflow
        }
        Customer customer = customers[front]; // Get the customer at the front
        if (front == rear) { // If only one customer was in the queue
            front = rear = -1; // Reset the queue
        } else {
            front = (front + 1) % MAX; // Move front to the next position
        }
        return customer; // Return the checked-out customer
    }

    void displayQueue() {
        if (isEmpty()) {
            cout << "No customers in the checkout queue." << endl;
            return;
        }
        cout << "Customers in queue: ";
        int i = front;
        while (true) {
            cout << customers[i].name << " (ID: " << customers[i].id << ") ";
            if (i == rear) break; // Stop when we reach the rear
            i = (i + 1) % MAX; // Circular increment
        }
        cout << endl;
    }

    void closeCounter() {
        front = rear = -1; // Reset the queue
        cout << "Checkout counter closed." << endl;
    }
};

int main() {
    CircularQueue queue;
    int choice;

    cout << "\nSupermarket Checkout System\n";
    cout << "1. Customer Arrival\n";
    cout << "2. Customer Checkout\n";
    cout << "3. Close Checkout Counter\n";
    cout << "4. View Customers\n";
    cout << "5. Exit\n";

    do {
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1: {
                int id;
                string name;
                cout << "Enter Customer ID: ";
                cin >> id;
                cout << "Enter Customer Name: ";
                cin >> name;
                queue.enqueue(Customer(id, name)); // Add new customer
                break;
            }
            case 2: {
                Customer customer = queue.dequeue(); // Checkout customer
                if (customer.id != 0) { // If customer is valid
                    cout << "Customer checked out: " << customer.name << " (ID: " << customer.id << ")" << endl;
                }
                break;
            }
            case 3:
                queue.closeCounter(); // Close checkout counter
                break;
            case 4:
                queue.displayQueue(); // View customers in queue
                break;
            case 5:
                cout << "Exiting the system." << endl;
                break;
            default:
                cout << "Invalid choice. Please try again." << endl;
        }
    } while (choice != 5);

    return 0;
}

