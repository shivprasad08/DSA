// Name: Shivprasad Abhijit Mahind
// PRN: 123B1B266
// Design a roll call list, arrange list of students according to roll numbers in ascending order using Insertion Sort

#include <iostream>
#include <string>
using namespace std;

// Define a class Student to hold student details like roll number, name, SGPA
class Student
{
    int roll;
    string name;
    float sgpa;

public:
    // Function to read student details
    void read(Student A[], int n)
    {
       for(int i = 0; i < n; ++i)
       {
            cout << "Student Roll number: ";
            cin >> A[i].roll; // Input Roll number
            cout << "Student name: ";
            cin.ignore();
            getline(cin, A[i].name); // Input Student Name
            cout << "Student SGPA: ";
            cin >> A[i].sgpa; // Input Student SGPA
       }
    }

    // Function to display student details
    void display(Student A[], int n)
    {
        for(int i = 0; i < n; i++)
        {
            cout << "Student Roll number: " << A[i].roll << " ";
            cout << "Student Name: " << A[i].name << " ";
            cout << "Student SGPA: " << A[i].sgpa << endl;
        }
    }

    // Declare insertionSort as a friend function so it can access private members of Student
    friend void insertionSort(Student A[], int n);
};

// Function to sort students based on roll numbers using Insertion Sort
void insertionSort(Student A[], int n)
{
    for (int i = 1; i < n; i++)
    {
        Student key = A[i]; // Store the current student to be inserted
        int j = i - 1;

        // Move elements of A[0..i-1], that are greater than key.roll, to one position ahead
        while (j >= 0 && A[j].roll > key.roll)
        {
            A[j + 1] = A[j];
            j = j - 1;
        }
        A[j + 1] = key; // Insert the key (current student) at the correct position
    }
}

int main()
{
    int n;
    int i;

    // Get the number of students
    cout << "Number of Students: ";
    cin >> n;
    Student A[n]; // Create an array of Student objects

    // Read student details
    A[i].read(A, n);
    cout << endl;
    cout << "Student Database before sorting: " << endl;
    // Display student details before sorting
    A[i].display(A, n);
    cout << endl;

    // Sort the students by roll number using Insertion Sort
    insertionSort(A, n);

    cout << "Student Database after sorting: " << endl;
    // Display student details after sorting
    A[i].display(A, n);

    return 0;
}

