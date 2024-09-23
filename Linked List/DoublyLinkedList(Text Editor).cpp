#include <iostream>
#include <string>
using namespace std;

// Node class representing each element in the doubly linked list
class Node {
public:
    string data; // Data stored in the node
    Node* next;       // Pointer to the next node
    Node* prev;       // Pointer to the previous node

    // Constructor to initialize the node with data
    Node(const string& data) : data(data), next(nullptr), prev(nullptr) {}
};

// TextEditor class to manage the text buffer using a doubly linked list
class TextEditor {
private:
    Node* head; // Pointer to the first node in the list
    Node* tail; // Pointer to the last node in the list

public:
    // Constructor to initialize an empty text editor
    TextEditor() : head(nullptr), tail(nullptr) {}

    // Insert text at the end of the list
    void insertText(const string& text) {
        Node* newNode = new Node(text);
        if (!head) { // If the list is empty
            head = tail = newNode;
        } else { // If the list is not empty
            tail->next = newNode;
            newNode->prev = tail;
            tail = newNode;
        }
    }

    // Delete text from the end of the list
    void deleteText() {
        if (!tail) return; // If the list is empty, do nothing
        Node* temp = tail;
        tail = tail->prev;
        if (tail) tail->next = nullptr; // If there are still nodes left
        else head = nullptr; // If the list is now empty
        delete temp;
    }

    // Display all text in the list
    void displayText() const {
        Node* current = head;
        while (current) {
            cout << current->data << endl;
            current = current->next;
        }
    }

    // Search for a specific text in the list
    bool searchText(const string& text) const {
        Node* current = head;
        while (current) {
            if (current->data == text) return true;
            current = current->next;
        }
        return false;
    }

    // Print all text in the list in reverse order
    void printReverse() const {
        Node* current = tail;
        while (current) {
            cout << current->data << endl;
            current = current->prev;
        }
    }

    // Destructor to clean up the list
    ~TextEditor() {
        while (head) {
            Node* temp = head;
            head = head->next;
            delete temp;
        }
    }
};

int main() {
    TextEditor editor;
    int choice;
    string text;

    cout << "\nText Editor Menu:\n";
    cout << "1. Insert text\n";
    cout << "2. Delete text\n";
    cout << "3. Display text\n";
    cout << "4. Search text\n";
    cout << "5. Print text in reverse\n";
    cout << "6. Exit\n";

    do {
        cout << "Enter your choice: ";
        cin >> choice;
        cin.ignore();  // Clear the newline left in the buffer

        switch (choice) {
            case 1:
                cout << "Enter text to insert: ";
                getline(cin, text);
                editor.insertText(text);
                break;
            case 2:
                editor.deleteText();
                cout << "Last text entry deleted.\n";
                break;
            case 3:
                cout << "Displaying text:\n";
                editor.displayText();
                break;
            case 4:
                cout << "Enter text to search: ";
                getline(cin, text);
                cout << (editor.searchText(text) ? "Text found." : "Text not found.") << endl;
                break;
            case 5:
                cout << "Printing text in reverse:\n";
                editor.printReverse();
                break;
            case 6:
                cout << "Exiting\n";
                break;
            default:
                cout << "Invalid choice. Please try again.\n";
        }
    } while (choice != 6);

    return 0;
}
