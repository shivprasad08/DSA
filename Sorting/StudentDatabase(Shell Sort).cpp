#include <iostream>
#include <string>
using namespace std;

// Define a class Student to hold student details like roll number, name, and SGPA
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

    // Declare shellSort as a friend function so it can access private members of Student
    friend void shellSort(Student A[], int n);

};

// Function to sort students alphabetically by name using Shell Sort
void shellSort(Student A[], int n)
{
    // Start with a big gap, then reduce the gap
    for(int gap = n/2; gap > 0; gap /= 2)
    {
        // Perform a gapped insertion sort for this gap size
        for(int i = gap; i < n; i++)
        {
            Student temp = A[i]; // Store the current student to be inserted
            int j;

            // Shift earlier gap-sorted elements up until the correct location for A[i] is found
            for(j = i; j >= gap && A[j - gap].name > temp.name; j -= gap)
            {
                A[j] = A[j - gap];// Shift element to the right
            }
            A[j] = temp; // Insert the current student at the correct position
        }
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

    A[i].read(A, n);
    cout << endl;
    cout << "Student Database before sorting: " << endl;
    A[i].display(A, n); // Display student details before sorting
    cout << endl;

    shellSort(A, n); // Sort the students by name using Shell Sort

    cout << "Student Database after sorting: " << endl;
    A[i].display(A, n); // Display student details after sorting

    return 0;

}
