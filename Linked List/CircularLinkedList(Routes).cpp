#include <iostream>
#include <string>
using namespace std;

class Route {
public:
    string source;
    string destination;
    float distance;
    Route* next;

    Route() {
        next = NULL;
    }

    void read() {
        cout << "Enter source: ";
        cin >> source;
        cout << "Enter destination: ";
        cin >> destination;
        cout << "Enter distance: ";
        cin >> distance;
    }

    void display() {
        cout << "Source: " << source << ", Destination: " << destination << ", Distance: " << distance << endl;
    }
};

class Navigation {
    Route* tail;
public:
    Navigation() {
        tail = NULL;
    }

    void insertAtEnd() {
        Route* cn = new Route();
        cn->read();
        if (tail == NULL) {
            tail = cn;
            cn->next = cn;
        } else {
            cn->next = tail->next;
            tail->next = cn;
            tail = cn;
        }
    }

    void insertAtHead() {
        Route* cn = new Route();
        cn->read();
        if (tail == NULL) {
            tail = cn;
            cn->next = cn;
        } else {
            cn->next = tail->next;
            tail->next = cn;
        }
    }

    void displayRoutes() {
        if (tail == NULL) {
            cout << "No routes to display." << endl;
            return;
        }
        Route* t = tail->next;
        do {
            t->display();
            t = t->next;
        } while (t != tail->next);
    }

    void deleteRoute(string src) {
        if (tail == nullptr) {
            cout << "No routes to delete." << endl;
            return;
        }

        Route* current = tail->next;
        Route* previous = tail;

        do {
            if (current->source == src) {
                if (current == tail) {
                    if (tail->next == tail) {
                        delete tail;
                        tail = nullptr;
                    } else {
                        previous->next = current->next;
                        tail = previous;
                        delete current;
                    }
                } else {
                    previous->next = current->next;
                    if (current == tail->next) {
                        tail->next = current->next;
                    }
                    delete current;
                }
                cout << "Route " << src << " deleted." << endl;
                return;
            }
            previous = current;
            current = current->next;
        } while (current != tail->next);

        cout << "Route " << src << " not found." << endl;
    }
};

int main() {
    Navigation Nav;
    int choice;

    while (true) {
        cout << "1. Add route at the end.\n2. Add route at the head.\n3. Display routes.\n4. Delete route.\n5. Exit." << endl;
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                Nav.insertAtEnd();
                break;
            case 2:
                Nav.insertAtHead();
                break;
            case 3:
                Nav.displayRoutes();
                break;
            case 4: {
                string src;
                cout << "Enter source of route to delete: ";
                cin >> src;
                Nav.deleteRoute(src);
                break;
            }
            case 5:
                return 0;
            default:
                cout << "Invalid choice, please try again." << endl;
        }
    }
}
