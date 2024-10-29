// Name: Shivprasad Abhijit Mahind
// PRN: 123B1B266
// Assignment-6
// Consider two polynomial expressions of any degree. Design solution to perform addition of these two polynomials with suitable data structure and display results.

#include <iostream>
using namespace std;

class Node {
public:
    int coefficient; // Coefficient of the term
    int power;    // Exponent of the term
    Node* next;      // Pointer to the next term

    Node(int coeff, int pow) : coefficient(coeff), power(pow), next(nullptr) {}
};

class Polynomial {
private:
    Node* head; // Head of the linked list

public:
    Polynomial() : head(nullptr) {}

    // Function to add a term to the polynomial
    void addTerm(int coeff, int pow) {
        Node* newNode = new Node(coeff, pow);
        if (!head || head->power < pow) {
            newNode->next = head;
            head = newNode;
        } else {
            Node* current = head;
            Node* prev = nullptr;
            while (current && current->power >= pow) {
                if (current->power == pow) {
                    current->coefficient += coeff;
                    delete newNode; // Avoid memory leak
                    return;
                }
                prev = current;
                current = current->next;
            }
            newNode->next = current;
            prev->next = newNode;
        }
    }

    // Function to display the polynomial
    void display() const {
        if (!head) {
            cout << "0" << endl; // Display 0 if polynomial is empty
            return;
        }

        Node* current = head;
        while (current) {
            cout << current->coefficient << "x^" << current->power;
            current = current->next;
            if (current) {
                cout << " + ";
            }
        }
        cout << endl;
    }

    // Function to add two polynomials
    Polynomial add(const Polynomial& other) {
        Polynomial result;
        Node* p1 = head;
        Node* p2 = other.head;

        while (p1 || p2) {
            if (p1 && (!p2 || p1->power > p2->power)) {
                result.addTerm(p1->coefficient, p1->power);
                p1 = p1->next;
            } else if (p2 && (!p1 || p2->power > p1->power)) {
                result.addTerm(p2->coefficient, p2->power);
                p2 = p2->next;
            } else {
                // Same exponent
                result.addTerm(p1->coefficient + p2->coefficient, p1->power);
                p1 = p1->next;
                p2 = p2->next;
            }
        }
        return result;
    }

    // Destructor to free memory
    ~Polynomial() {
        Node* current = head;
        while (current) {
            Node* next = current->next;
            delete current;
            current = next;
        }
    }
};

int main() {
    Polynomial p1, p2;
    int choice, coeff, pow;

    cout << "Menu:\n";
    cout << "1. Add term to Polynomial 1\n";
    cout << "2. Add term to Polynomial 2\n";
    cout << "3. Display Polynomial 1\n";
    cout << "4. Display Polynomial 2\n";
    cout << "5. Add Polynomials\n";
    cout << "6. Exit\n";

    while (true) {
        cout << "\nEnter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                cout << "Enter coefficient and power for Polynomial 1: ";
                cin >> coeff >> pow;
                p1.addTerm(coeff, pow);
                break;

            case 2:
                cout << "Enter coefficient and power for Polynomial 2: ";
                cin >> coeff >> pow;
                p2.addTerm(coeff, pow);
                break;

            case 3:
                cout << "Polynomial 1: ";
                p1.display();
                break;

            case 4:
                cout << "Polynomial 2: ";
                p2.display();
                break;

            case 5:
                {
                    Polynomial result = p1.add(p2);
                    cout << "Resulting Polynomial: ";
                    result.display();
                }
                break;

            case 6:
                cout << "Exiting\n";
                return 0;

            default:
                cout << "Invalid choice! Please try again.\n";
        }
    }

    return 0;
}
