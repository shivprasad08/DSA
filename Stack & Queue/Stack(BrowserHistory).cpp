// Name: Shivprasad Abhijit Mahind
// PRN: 123B1B266
// Assignment-7
/* Implement a browser history management system using a stack data structure to track the user's browsing history.
   The system should support the following functionalities: a. Add visited page b. Navigate back c. View current page
   d. Check if history is empty or not Assume no upper bound on number of pages visited. */

#include <iostream>
#include <string>
using namespace std;

// Class representing each webpage as a node in the linked list
class Webpage
{
    string site;
    public:
        Webpage* next;
        // Constructor to initialize the webpage link
        Webpage(string site) {
            this->site = site;
            this->next = NULL;
        }

        // Getter to access the private site link
        string getSite() {
            return site;
        }
};

// Stack implemented using a singly linked list to manage browser history
class BrowserHistory
{
private:
    Webpage* top;    // Pointer to the top of the stack (most recently visited webpage)

public:
    // Constructor initializes the top pointer to NULL (empty stack)
    BrowserHistory() {
        top = NULL;
    }

    // Function to add a new visited webpage to the history
    void addVisitedWebpage(string site) {
        Webpage* newWebpage = new Webpage(site);
        newWebpage->next = top;
        top = newWebpage;
        cout << "Visited: " << site << endl;
    }

    // Function to navigate back (pop the top of the stack)
    void navigateBack() {
        if (top == NULL) {
            cout << "No more history to navigate back to!" << endl;
            return;
        }

        Webpage* temp = top;
        cout << "Navigating back from: " << top->getSite() << endl;
        top = top->next;
        delete temp;
    }

    // Function to view the current page (the top of the stack)
    void viewCurrentPage() {
        if (top == NULL) {
            cout << "No pages in history!" << endl;
        } else {
            cout << "Currently on: " << top->getSite() << endl;
        }
    }

    // Function to check if history is empty
    bool isHistoryEmpty() {
        return top == NULL;
    }
};

int main() {
    BrowserHistory history;
    int choice;
    string site;

     cout << "\nMenu\n";
        cout << "1. Add a visited webpage\n";
        cout << "2. Navigate back\n";
        cout << "3. View current page\n";
        cout << "4. Check if history is empty\n";
        cout << "5. Exit\n";

    do {
        cout << "Enter your choice: ";
        cin >> choice;

        switch(choice) {
            case 1:
                cout << "Enter the website link: ";
                cin.ignore();
                getline(cin, site);
                history.addVisitedWebpage(site);
                break;
            case 2:
                history.navigateBack();
                break;
            case 3:
                history.viewCurrentPage();
                break;
            case 4:
                if (history.isHistoryEmpty()) {
                    cout << "History is empty." << endl;
                } else {
                    cout << "History is not empty." << endl;
                }
                break;
            case 5:
                cout << "Exiting..." << endl;
                break;
            default:
                cout << "Invalid choice, please try again." << endl;
        }
    } while (choice != 5);

    return 0;
}
