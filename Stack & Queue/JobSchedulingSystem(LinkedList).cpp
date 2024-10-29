// Name: Shivprasad A. Mhaind
// PRN: 123B1B266
// Assignment-9B
/* Implement a job scheduling system for a manufacturing plant using a double-ended queue.
    The system needs to efficiently manage the processing of jobs on various machines throughout the plant.
    Each job has a Job_priority. The system should support the following operations: a. Add Job b. Remove Job c. Display Job d. Search Job */

#include <iostream>
#include <string>

class Job {
public:
    int jobID;
    int jobPriority;
    Job* next;
    Job* prev;

    Job(int id, int priority) : jobID(id), jobPriority(priority), next(nullptr), prev(nullptr) {}
};

class JobQueue {
private:
    Job* front;
    Job* back;

public:
    JobQueue() : front(nullptr), back(nullptr) {}

    // Add Job to the back of the queue
    void addJob(int id, int priority) {
        Job* newJob = new Job(id, priority);
        if (!front) { // Empty queue
            front = back = newJob;
        } else {
            back->next = newJob;
            newJob->prev = back;
            back = newJob;
        }
        std::cout << "Job added: ID = " << id << ", Priority = " << priority << std::endl;
    }

    // Remove Job from the front of the queue
    void removeJob() {
        if (!front) {
            std::cout << "Queue is empty, cannot remove job." << std::endl;
            return;
        }
        Job* temp = front;
        front = front->next;
        if (front) {
            front->prev = nullptr;
        } else {
            back = nullptr; // Queue is now empty
        }
        delete temp;
        std::cout << "Job removed from the front." << std::endl;
    }

    // Display all jobs in the queue
    void displayJobs() {
        if (!front) {
            std::cout << "Queue is empty." << std::endl;
            return;
        }
        Job* current = front;
        while (current) {
            std::cout << "Job ID: " << current->jobID << ", Priority: " << current->jobPriority << std::endl;
            current = current->next;
        }
    }

    // Search for a job by job ID
    void searchJob(int id) {
        Job* current = front;
        while (current) {
            if (current->jobID == id) {
                std::cout << "Job found - ID: " << current->jobID << ", Priority: " << current->jobPriority << std::endl;
                return;
            }
            current = current->next;
        }
        std::cout << "Job not found." << std::endl;
    }

    ~JobQueue() {
        while (front) {
            removeJob();
        }
    }
};

int main() {
    JobQueue jobQueue;
    int choice, id, priority;

    std::cout << "\nJob Scheduling System Menu:\n";
    std::cout << "1. Add Job\n";
    std::cout << "2. Remove Job\n";
    std::cout << "3. Display Jobs\n";
    std::cout << "4. Search Job\n";
    std::cout << "5. Exit\n";

    do {
        std::cout << "Enter your choice: ";
        std::cin >> choice;

        switch (choice) {
            case 1:
                std::cout << "Enter Job ID: ";
                std::cin >> id;
                std::cout << "Enter Job Priority: ";
                std::cin >> priority;
                jobQueue.addJob(id, priority);
                break;

            case 2:
                jobQueue.removeJob();
                break;

            case 3:
                jobQueue.displayJobs();
                break;

            case 4:
                std::cout << "Enter Job ID to search: ";
                std::cin >> id;
                jobQueue.searchJob(id);
                break;

            case 5:
                std::cout << "Exiting the program." << std::endl;
                break;

            default:
                std::cout << "Invalid choice. Please try again." << std::endl;
                break;
        }
    } while (choice != 5);

    return 0;
}
