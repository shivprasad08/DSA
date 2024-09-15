// Name: Shivprasad Abhijit Mahind
// PRN : 123B1B266
// Arrange list of Employee alphabetically using Merge Sort
#include <iostream>
#include <string>

using namespace std;

class Employee
{
public:
    int id;
    string name;
    float salary;

    // Function to input employee details
    void input()
    {
        cout << "Enter Employee ID: ";
        cin >> id;
        cout << "Enter Employee Name: ";
        cin.ignore();  // Ignore any remaining newline characters
        getline(cin, name);  // Read the entire line (including spaces) for the name
        cout << "Enter Employee Salary: ";
        cin >> salary;
    }

    // Function to display employee details
    void display()
    {
        cout << "ID: " << id << ", Name: " << name << ", Salary: " << salary << endl;
    }
};

// Merge function for merge sort
void merge(Employee arr[], int left, int mid, int right)
{
    int n1 = mid - left + 1;
    int n2 = right - mid;

    Employee L[n1], R[n2];

    // Copy data to temporary arrays L[] and R[]
    for (int i = 0; i < n1; i++)
        L[i] = arr[left + i];
    for (int j = 0; j < n2; j++)
        R[j] = arr[mid + 1 + j];

    // Merge the two sorted arrays back into arr[]
    int i = 0, j = 0, k = left;
    while (i < n1 && j < n2) {
        if (L[i].name <= R[j].name)
        {
            arr[k] = L[i];
            i++;
        }
        else
        {
            arr[k] = R[j];
            j++;
        }
        k++;
    }

    // Copy any remaining elements of L[] and R[]
    while (i < n1)
    {
        arr[k] = L[i];
        i++;
        k++;
    }

    while (j < n2)
    {
        arr[k] = R[j];
        j++;
        k++;
    }
}

// Merge sort function
void mergeSort(Employee arr[], int left, int right)
{
    if (left < right)
    {
        int mid = left + (right - left) / 2;

        // Recursively sort the two halves
        mergeSort(arr, left, mid);
        mergeSort(arr, mid + 1, right);

        // Merge the sorted halves
        merge(arr, left, mid, right);
    }
}

int main()
{
    int n;
    cout << "Enter the number of employees: ";
    cin >> n;

    Employee employees[n];

    // Input employee details
    for (int i = 0; i < n; i++) {
        cout << "Enter details for employee " << i + 1 << ":" << endl;
        employees[i].input();
    }

    // Sort employees by name using merge sort
    mergeSort(employees, 0, n - 1);

    // Display the sorted employee database
    cout << "\nSorted Employee Database:\n";
    for (int i = 0; i < n; i++) {
        employees[i].display();
	}

    return 0;
}


