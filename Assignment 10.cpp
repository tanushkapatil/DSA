// Name : Tanushka Patil
// Prn No. : 123B1B036

#include <iostream>
#include <string>

using namespace std;

// Structure for a job
struct Job {
    string job_name;
    int job_priority;
    Job* next;
    Job* prev;
};

class JobSchedulingSystem {
    Job* front;  // Points to the front job
    Job* rear;   // Points to the rear job

public:
    JobSchedulingSystem() {
        front = nullptr;
        rear = nullptr;
    }

    // Function to check if the deque is empty
    bool isEmpty() {
        return front == nullptr;
    }

    // Function to add a job to the front of the deque
    void addJobFront(string job_name, int job_priority) {
        Job* newJob = new Job();
        newJob->job_name = job_name;
        newJob->job_priority = job_priority;
        newJob->next = front;
        newJob->prev = nullptr;

        if (isEmpty()) {
            front = rear = newJob; // First job in the deque
        } else {
            front->prev = newJob;
            front = newJob;
        }
        cout << "Job added at the front." << endl;
    }

    // Function to add a job to the rear of the deque
    void addJobRear(string job_name, int job_priority) {
        Job* newJob = new Job();
        newJob->job_name = job_name;
        newJob->job_priority = job_priority;
        newJob->next = nullptr;
        newJob->prev = rear;

        if (isEmpty()) {
            front = rear = newJob; // First job in the deque
        } else {
            rear->next = newJob;
            rear = newJob;
        }
        cout << "Job added at the rear." << endl;
    }

    // Function to remove a job from the front of the deque
    void removeJobFront() {
        if (isEmpty()) {
            cout << "Queue is empty. No job to remove!" << endl;
            return;
        }

        Job* temp = front;
        cout << "Removing job: " << front->job_name << " with priority " << front->job_priority << endl;
        
        if (front == rear) { // Only one job
            front = rear = nullptr;
        } else {
            front = front->next;
            front->prev = nullptr;
        }

        delete temp;
    }

    // Function to remove a job from the rear of the deque
    void removeJobRear() {
        if (isEmpty()) {
            cout << "Queue is empty. No job to remove!" << endl;
            return;
        }

        Job* temp = rear;
        cout << "Removing job: " << rear->job_name << " with priority " << rear->job_priority << endl;

        if (front == rear) { // Only one job
            front = rear = nullptr;
        } else {
            rear = rear->prev;
            rear->next = nullptr;
        }

        delete temp;
    }

    // Function to display all jobs in the deque
    void displayJobs() {
        if (isEmpty()) {
            cout << "Queue is empty!" << endl;
            return;
        }

        cout << "Jobs in the queue:" << endl;
        Job* temp = front;
        while (temp != nullptr) {
            cout << "Job: " << temp->job_name << " | Priority: " << temp->job_priority << endl;
            temp = temp->next;
        }
    }

    // Function to search for a job by name
    void searchJob(string job_name) {
        if (isEmpty()) {
            cout << "Queue is empty. No job to search!" << endl;
            return;
        }

        Job* temp = front;
        bool found = false;
        while (temp != nullptr) {
            if (temp->job_name == job_name) {
                cout << "Job found: " << job_name << " with priority " << temp->job_priority << endl;
                found = true;
                break;
            }
            temp = temp->next;
        }

        if (!found) {
            cout << "Job not found!" << endl;
        }
    }
};

int main() {
    JobSchedulingSystem system;
    int choice;
    string job_name;
    int job_priority;

    do {
        cout << "\nJob Scheduling System Menu:\n";
        cout << "1. Add Job at Front\n";
        cout << "2. Add Job at Rear\n";
        cout << "3. Remove Job from Front\n";
        cout << "4. Remove Job from Rear\n";
        cout << "5. Display Jobs\n";
        cout << "6. Search Job\n";
        cout << "7. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                cout << "Enter job name: ";
                cin >> job_name;
                cout << "Enter job priority: ";
                cin >> job_priority;
                system.addJobFront(job_name, job_priority);
                break;
            case 2:
                cout << "Enter job name: ";
                cin >> job_name;
                cout << "Enter job priority: ";
                cin >> job_priority;
                system.addJobRear(job_name, job_priority);
                break;
            case 3:
                system.removeJobFront();
                break;
            case 4:
                system.removeJobRear();
                break;
            case 5:
                system.displayJobs();
                break;
            case 6:
                cout << "Enter job name to search: ";
                cin >> job_name;
                system.searchJob(job_name);
                break;
            case 7:
                cout << "Exiting system." << endl;
                break;
            default:
                cout << "Invalid choice. Please try again." << endl;
        }
    } while (choice != 7);

    return 0;
}
