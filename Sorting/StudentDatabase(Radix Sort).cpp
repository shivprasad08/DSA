// Name: Shivprasad Abhijit Mahind
// PRN: 123B1B266
//Arrange list of students to find out first ten toppers from a class using Radix sort

#include <iostream>
#include <string>
#include <cmath>

using namespace std;

#define MAX_STUDENTS 100

class Student
{
    int rollNo;
    string name;
    float sgpa;

public:
    // To read student details
    void read()
    {
        cout << "Enter Roll No: ";
        cin >> rollNo;
        cout << "Enter Name: ";
        cin >> name;
        cout << "Enter SGPA: ";
        cin >> sgpa;
    }

    // To display student details
    void display() const
    {
        cout << "Roll No: " << rollNo << "\tName: " << name << "\tSGPA: " << sgpa << endl;
    }

    // Friend function declaration for sorting
    friend void radixSort(Student arr[], int n);
    friend float getMaxSGPA(Student arr[], int n);
    friend void countingSort(Student arr[], int n, int exp);
};

// To get the maximum SGPA in the array
float getMaxSGPA(Student arr[], int n)
{
    float maxSGPA = arr[0].sgpa;
    for (int i = 1; i < n; i++)
    {
        if (arr[i].sgpa > maxSGPA)
        {
            maxSGPA = arr[i].sgpa;
        }
    }
    return maxSGPA;
}

// Counting sort
void countingSort(Student arr[], int n, int exp)
{
    Student output[MAX_STUDENTS];
    int count[10] = {0};

    // Store count of occurrences in count[]
    for (int i = 0; i < n; i++)
    {
        int digit = (int)(arr[i].sgpa * 10) / exp % 10;
        count[digit]++;
    }

    // Change count[i] so that count[i] contains the actual position of this digit in output[]
    for (int i = 1; i < 10; i++)
    {
        count[i] += count[i - 1];
    }

    // Output array
    for (int i = n - 1; i >= 0; i--)
    {
        int digit = (int)(arr[i].sgpa * 10) / exp % 10;
        output[count[digit] - 1] = arr[i];
        count[digit]--;
    }

    // Copy the output array to arr[], so that arr[] now contains sorted numbers
    for (int i = 0; i < n; i++)
    {
        arr[i] = output[i];
    }
}

// Sort array using Radix Sort
void radixSort(Student arr[], int n)
{
    float maxSGPA = getMaxSGPA(arr, n);

    // Apply counting sort to sort elements based on place value.
    for (int exp = 1; maxSGPA / exp > 0; exp *= 10)
    {
        countingSort(arr, n, exp);
    }
}

// Function to print the top 10 students
void printTopStudents(Student arr[], int n)
{
    cout << "\nTop 10 Students:\n";
    for (int i = n - 1, count = 0; i >= 0 && count < 10; i--, count++)
    {
        arr[i].display();
    }
}

int main()
{
    int n;

    cout << "Enter the number of students (at least 15): ";
    cin >> n;

    if (n < 15)
    {
        cout << "Number of students should be at least 15." << endl;
        return 1;
    }

    Student students[MAX_STUDENTS];

    // Taking input from the user
    for (int i = 0; i < n; i++)
    {
        cout << "\nEnter details for student " << i + 1 << ":\n";
        students[i].read();
    }

    // Sort the students using Radix Sort
    radixSort(students, n);

    // Print the top 10 students
    printTopStudents(students, n);

    return 0;
}
