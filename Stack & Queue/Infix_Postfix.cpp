// Name: Shivprasad A. Mahind
// PRN: 123B1B266
// Assignment: 8
// Write a program to convert infix expression to postfix and evaluation of postfix expression. //

#include <iostream>
#include <string>

#define MAX 100

using namespace std;

// Stack class for managing characters (operators and operands)
class CharStack {
    char arr[MAX];
    int top;

public:
    CharStack() : top(-1) {}

    bool isEmpty() {
        return top == -1;
    }

    bool isFull() {
        return top == MAX - 1;
    }

    void push(char x) {
        if (!isFull()) {
            arr[++top] = x;
        }
    }

    char pop() {
        if (!isEmpty()) {
            return arr[top--];
        }
        return '\0'; // Return null character for underflow
    }

    char peek() {
        if (!isEmpty()) {
            return arr[top];
        }
        return '\0';
    }
};

// Stack class for managing integers (for evaluation)
class IntStack {
    int arr[MAX];
    int top;

public:
    IntStack() : top(-1) {}

    bool isEmpty() {
        return top == -1;
    }

    bool isFull() {
        return top == MAX - 1;
    }

    void push(int x) {
        if (!isFull()) {
            arr[++top] = x;
        }
    }

    int pop() {
        if (!isEmpty()) {
            return arr[top--];
        }
        return -1; // Return -1 for underflow
    }
};

// Class to handle conversion and evaluation
class Postfix {
public:
    // Function to check precedence of operators
    int precedence(char op) {
        if (op == '+' || op == '-')
            return 1;
        if (op == '*' || op == '/')
            return 2;
        return 0;
    }

    // Function to check if the character is an operator
    bool isOperator(char ch) {
        return ch == '+' || ch == '-' || ch == '*' || ch == '/';
    }

    // Convert infix expression to postfix
    string infixToPostfix(string infix) {
        CharStack s;
        string postfix;

        for (int i = 0; i < infix.length(); i++) {
            char ch = infix[i];

            // If the character is an operand, add it to output
            if (isalnum(ch)) {
                postfix += ch;
            }
            // If the character is '(', push to stack
            else if (ch == '(') {
                s.push(ch);
            }
            // If the character is ')', pop and add to output until '(' is found
            else if (ch == ')') {
                while (!s.isEmpty() && s.peek() != '(') {
                    postfix += s.pop();
                }
                s.pop(); // Remove '(' from stack
            }
            // If an operator is encountered
            else if (isOperator(ch)) {
                while (!s.isEmpty() && precedence(s.peek()) >= precedence(ch)) {
                    postfix += s.pop();
                }
                s.push(ch);
            }
        }

        // Pop all the operators from the stack
        while (!s.isEmpty()) {
            postfix += s.pop();
        }

        return postfix;
    }

    // Evaluate the postfix expression
    int evaluatePostfix(string postfix) {
        IntStack s;

        for (int i = 0; i < postfix.length(); i++) {
            char ch = postfix[i];

            // If the character is an operand, push it to stack
            if (isdigit(ch)) {
                s.push(ch - '0'); // Convert char to int
            }
            // If the character is an operator, pop two operands and apply the operation
            else {
                int val1 = s.pop();
                int val2 = s.pop();

                switch (ch) {
                    case '+':
                        s.push(val2 + val1);
                        break;
                    case '-':
                        s.push(val2 - val1);
                        break;
                    case '*':
                        s.push(val2 * val1);
                        break;
                    case '/':
                        s.push(val2 / val1);
                        break;
                }
            }
        }

        return s.pop(); // Final result
    }
};

int main() {
    Postfix postfix;
    string expression;
    int choice;

    cout << "\nMenu:\n";
    cout << "1. Infix to Postfix\n";
    cout << "2. Evaluate Postfix\n";
    cout << "3. Exit\n";

    do {
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                cout << "Enter infix expression: ";
                cin >> expression;
                cout << "Postfix expression: " << postfix.infixToPostfix(expression) << endl;
                break;

            case 2:
                cout << "Enter postfix expression: ";
                cin >> expression;
                cout << "Result of evaluation: " << postfix.evaluatePostfix(expression) << endl;
                break;

            case 3:
                cout << "Exiting..." << endl;
                break;

            default:
                cout << "Invalid choice!" << endl;
        }

    } while (choice != 3);

    return 0;
}
