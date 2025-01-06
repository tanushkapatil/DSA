// Name : Tanushka Patil
// Prn No. : 123B1B036

#include <iostream>
using namespace std;

#define size 10 // Define the size of the hash table

// Class to store employee details
class Employee {
    int empID;    // Employee ID
    string name;  // Employee name
    long salary;  // Employee salary

public:
    // Default constructor to initialize employee details
    Employee() {
        empID = -1;
        name = " ";
        salary = 0;
    }

    // Function to read employee details from the user
    void read() {
        cout << "Enter employee ID: ";
        cin >> empID;
        cout << "Enter employee name: ";
        cin >> name;
        cout << "Enter employee salary: ";
        cin >> salary;
    }

    // Function to display employee details
    void display() {
        if (empID != -1) { // If employee ID is valid
            cout << empID << "\t" << name << "\t" << salary << endl;
        } else {
            cout << "-\t-\t-" << endl; // If employee slot is empty
        }
    }

    // Function to get the employee ID
    int getID() {
        return empID;
    }

    // Function to clear employee details (mark slot as empty)
    void clear() {
        empID = -1;
        name = "";
        salary = 0;
    }
};

// Class to implement the hash table for employee data
class Hashtable {
    Employee e[size]; // Array of Employee objects
    int flag[size];   // Array to indicate if a slot is occupied (1) or empty (0)

public:
    // Constructor to initialize the hash table
    Hashtable() {
        for (int i = 0; i < size; i++) {
            flag[i] = 0; // Initialize all slots as empty
        }
    }

    // Function prototypes
    void insertID();
    void deleteID();
    void displayTable();
    int hashFunction(int empID);
};

// Hash function to determine the position based on employee ID
int Hashtable::hashFunction(int empID) {
    return empID % size; // Returns the remainder when empID is divided by size
}

// Function to insert an employee into the hash table
void Hashtable::insertID() {
    Employee newEmp;
    newEmp.read(); // Read employee details
    int empID = newEmp.getID();
    int pos = hashFunction(empID); // Get the initial position using hash function

    // Linear probing to find an empty slot
    for (int i = 0; i < size; i++) {
        pos = (pos + i) % size; // Update position using linear probing
        if (flag[pos] == 0) {   // If slot is empty
            e[pos] = newEmp;    // Insert employee data
            flag[pos] = 1;      // Mark the slot as occupied
            cout << "Employee inserted at position: " << pos << endl;
            return;
        }
    }

    // If no empty slot is found
    cout << "Hash table is full! Unable to insert employee." << endl;
}

// Function to delete an employee from the hash table
void Hashtable::deleteID() {
    int id;
    cout << "Enter the employee ID to delete: ";
    cin >> id;
    int pos = hashFunction(id); // Get the initial position using hash function

    // Check if the employee ID is valid
    if (id <= 0) {
        cout << "Invalid employee ID. It must be positive.\n";
        return;
    }

    // Linear probing to find the employee with the given ID
    for (int i = 0; i < size; i++) {
        pos = (pos + i) % size; // Update position using linear probing
        if (flag[pos] == 1 && e[pos].getID() == id) { // If employee is found
            e[pos].clear();    // Clear employee details
            flag[pos] = 0;     // Mark the slot as empty
            cout << "Employee with ID " << id << " deleted from position: " << pos << endl;
            return;
        }
    }

    // If the employee ID is not found
    cout << "Employee ID not found!" << endl;
}

// Function to display all employees in the hash table
void Hashtable::displayTable() {
    cout << "Position\tID\tName\t\tSalary" << endl;
    for (int i = 0; i < size; i++) {
        cout << i << "\t\t";
        if (flag[i] == 1) { // If slot is occupied
            e[i].display(); // Display employee details
        } else {
            cout << "-\t-\t\t-" << endl; // Display '-' for empty slots
        }
    }
}

// Main function to provide a menu for user interaction
int main() {
    Hashtable ht; // Create a hash table object
    int choice;

    // Menu loop
    while (1) {
        cout << "\nEmployee Database Menu:\n";
        cout << "1. Insert employee\n";
        cout << "2. Delete employee\n";
        cout << "3. Display all employees\n";
        cout << "4. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        // Switch case for menu options
        switch (choice) {
        case 1:
            ht.insertID(); // Insert a new employee
            break;
        case 2:
            ht.deleteID(); // Delete an employee
            break;
        case 3:
            ht.displayTable(); // Display the hash table
            break;
        case 4:
            cout << "Exiting the program." << endl;
            exit(0); // Exit the program
        default:
            cout << "Invalid choice! Please enter a valid option." << endl;
            break;
        }
    }

    return 0;
}
