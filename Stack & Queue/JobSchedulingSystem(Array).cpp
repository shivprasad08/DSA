// Name: Shivprasad A. Mhaind
// PRN: 123B1B266
// Assignment-9B
/*  Implement a job scheduling system for a manufacturing plant using a double-ended queue.
    The system needs to efficiently manage the processing of jobs on various machines throughout the plant.
    Each job has a Job_priority. The system should support the following operations: a. Add Job b. Remove Job c. Display Job d. Search Job */

#include <iostream>
#include <string>

using namespace std;

#define MAX 5 // Define the maximum capacity of the DeQueue

// Job class representing a job with an ID and priority
class Job {
public:
    int jobId;
    int jobPriority;

    Job() : jobId(-1), jobPriority(-1) {}

    Job(int id, int priority) : jobId(id), jobPriority(priority) {}
};

// DeQueue class implementing a circular double-ended queue to store Job objects
class DeQueue {
    Job arr[MAX];
    int front, rear;

public:
    // Constructor to initialize front and rear as empty (-1)
    DeQueue() : front(-1), rear(-1) {}

    // Check if the DeQueue is empty
    bool isEmpty() {
        return (front == -1);
    }

    // Check if the DeQueue is full (circular behavior with modulo MAX)
    bool isFull() {
        return (front == (rear + 1) % MAX);
    }

    // Insert a job at the rear of the DeQueue
    void insertAtRear(Job job) {
        if (isFull()) {
            cout << "DeQueue is full. Cannot insert job: " << job.jobId << endl;
            return;
        }
        rear = (rear + 1) % MAX;
        arr[rear] = job;
        if (front == -1) {
            front = 0;
        }
    }

    // Insert a job at the front of the DeQueue
    void insertAtFront(Job job) {
        if (isFull()) {
            cout << "DeQueue is full. Cannot insert job: " << job.jobId << endl;
            return;
        }
        if (front == -1) {
            front = rear = 0;
        } else if (front == 0) {
            front = MAX - 1;
        } else {
            front--;
        }
        arr[front] = job;
    }

    // Delete a job from the front of the DeQueue
    Job deleteFromFront() {
        if (isEmpty()) {
            cout << "DeQueue is empty. Cannot delete from front." << endl;
            return Job();
        }
        Job returnValue = arr[front];
        if (rear == front) {
            front = rear = -1;
        } else {
            front = (front + 1) % MAX;
        }
        return returnValue;
    }

    // Delete a job from the rear of the DeQueue
    Job deleteFromRear() {
        if (isEmpty()) {
            cout << "DeQueue is empty. Cannot delete from rear." << endl;
            return Job();
        }
        Job returnValue = arr[rear];
        if (rear == front) {
            front = rear = -1;
        } else if (rear == 0) {
            rear = MAX - 1;
        } else {
            rear--;
        }
        return returnValue;
    }

    // Display all jobs in the DeQueue
    void display() {
        if (isEmpty()) {
            cout << "DeQueue is empty." << endl;
            return;
        }
        cout << "Jobs in DeQueue: ";
        int i = front;
        while (true) {
            cout << "[" << arr[i].jobId << ", Priority: " << arr[i].jobPriority << "] ";
            if (i == rear) break;
            i = (i + 1) % MAX;
        }
        cout << endl;
    }

    // Search for a job by its jobId in the DeQueue
    bool searchJob(int jobId) {
        if (isEmpty()) return false;
        int i = front;
        while (true) {
            if (arr[i].jobId == jobId) {
                return true;
            }
            if (i == rear) break;
            i = (i + 1) % MAX;
        }
        return false;
    }
};

int main() {
    DeQueue dq;
    int choice, jobId, jobPriority;

    cout << "\nJob Scheduling System Menu:\n";
    cout << "1. Add Job at Rear\n";
    cout << "2. Add Job at Front\n";
    cout << "3. Remove Job from Front\n";
    cout << "4. Remove Job from Rear\n";
    cout << "5. Display Jobs\n";
    cout << "6. Search Job\n";
    cout << "7. Exit\n";

    do {
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                cout << "Enter Job ID and Priority to add at Rear: ";
                cin >> jobId >> jobPriority;
                dq.insertAtRear(Job(jobId, jobPriority));
                break;

            case 2:
                cout << "Enter Job ID and Priority to add at Front: ";
                cin >> jobId >> jobPriority;
                dq.insertAtFront(Job(jobId, jobPriority));
                break;

            case 3:
                {
                    Job job = dq.deleteFromFront();
                    if (job.jobId != -1) {
                        cout << "Removed Job from Front: ID=" << job.jobId << ", Priority=" << job.jobPriority << endl;
                    }
                }
                break;

            case 4:
                {
                    Job job = dq.deleteFromRear();
                    if (job.jobId != -1) {
                        cout << "Removed Job from Rear: ID=" << job.jobId << ", Priority=" << job.jobPriority << endl;
                    }
                }
                break;

            case 5:
                dq.display();
                break;

            case 6:
                cout << "Enter Job ID to search: ";
                cin >> jobId;
                cout << "Job ID " << jobId << (dq.searchJob(jobId) ? " found." : " not found.") << endl;
                break;

            case 7:
                cout << "Exiting the program." << endl;
                break;

            default:
                cout << "Invalid choice. Please try again." << endl;
        }
    } while (choice != 7);

    return 0;
}
