#include <iostream>
#include <string>
using namespace std;

// Define a class called Employee
class Employee
{
    int id;
    string name;
    int salary;

public:
    // Member function to read employee details from user input
    void read()
    {
        cout << "Enter Employee Id: ";
        cin >> id;
        cout << "Enter Employee Name: ";
        cin.ignore();
        getline(cin, name);
        cout << "Enter Employee Salary: ";
        cin >> salary;
    }

    // Member function to display employee details
    void display()
    {
        cout << "Employee Id: " << id << " ";
        cout << "Employee Name: " << name << " ";
        cout << "Employee Salary: " << salary << endl;
    }

    // Declare friend functions (used for sorting)
    friend void swap(Employee &a, Employee &b);
    friend int partition(Employee A[], int low, int high);
    friend int QS(Employee A[], int low, int high);
};

// Swap two Employee objects
void swap(Employee &a, Employee &b)
{
    Employee temp = a;
    a = b;
    b = temp;
}

// Partition function for Quick Sort
int partition(Employee A[], int low, int high)
{
    double pivot = A[high].id;
    int i = low - 1;

    for (int j = low; j < high; j++)
    {
        if (A[j].id < pivot)
        {
            i++;
            swap(A[i], A[j]);
        }
    }

    swap(A[i + 1], A[high]);
    return i + 1;
}

// Quick Sort function
int QS(Employee A[], int low, int high)
{
    if (low < high)
    {
        int pi = partition(A, low, high);
        QS(A, low, pi - 1);
        QS(A, pi + 1, high);
    }
}

int main()
{
    int n;
    cout << "Enter the number of Employees: ";
    cin >> n;

    // Create an array of Employee objects
    Employee employee[n];
    for (int i = 0; i < n; i++)
    {
        cout << "Enter the Employee Details: " << endl;
        employee[i].read(); // Read details for each employee
    }

    // Sort the employees using Quick Sort
    QS(employee, 0, n - 1);

    // Display sorted employees
    cout << "\nEmployees sorted by Employee Id in ascending order:" << endl;
    for (int i = 0; i < n; i++)
    {
        employee[i].display();
    }

    return 0;
}
