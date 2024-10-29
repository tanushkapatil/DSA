// Name : Tanushka Patil
// Prn No. : 123B1B036

#include <iostream>
using namespace std;

// Class to represent a customer
class customer
{
private:
    string name;  // Customer's name
    long phone;   // Customer's phone number

public:
    customer();           // Constructor to initialize customer
    void getData();      // Method to input customer data
    void display();       // Method to display customer data
};

// Constructor to initialize customer attributes
customer::customer()
{
    name = "";  // Initialize name to an empty string
    phone = 0;  // Initialize phone to 0
}

// Method to get data from the user
void customer::getData()
{
    cout << endl;
    cout << "Enter the Name of the Customer: "; // Prompt for name
    cin >> name;                               // Read name input
    cout << "Enter Contact Number: ";          // Prompt for phone number
    cin >> phone;                              // Read phone input
    cout << endl;
}

// Method to display customer data
void customer::display()
{
    cout << endl;
    cout << "Customer Name: " << name;          // Display name
    cout << "Phone Number: " << phone;          // Display phone number
    cout << endl;
}

// Class to represent a queue for customers
class queue
{
private:
    int size;           // Maximum size of the queue
    int front;          // Index of the front of the queue
    int rear;           // Index of the rear of the queue
    customer *Q;       // Dynamic array to hold customers

public:
    queue(int x);      // Constructor to initialize queue
    void enqueue();    // Method to add a customer to the queue
    customer dequeue(); // Method to remove a customer from the queue
    void display();     // Method to display the queue
    bool isFull();      // Check if the queue is full
    bool isEmpty();     // Check if the queue is empty
    customer queueFront(); // Get the customer at the front
    customer queueRear();  // Get the customer at the rear
    ~queue();            // Destructor to free allocated memory
};

// Constructor to initialize the queue
queue::queue(int x)
{
    size = x;          // Set maximum size
    Q = new customer[size]; // Allocate memory for customer array
    front = 0;        // Initialize front index
    rear = 0;         // Initialize rear index
}

// Method to add a customer to the queue
void queue::enqueue()
{
    if (isFull())  // Check if the queue is full
    {
        cout << "Queue Full!" << endl; // Notify if full
    }
    else
    {
        Q[rear].getData(); // Get customer data
        rear = (rear + 1) % size; // Update rear index (circular increment)
    }
}

// Method to remove and return the customer at the front of the queue
customer queue::dequeue()
{
    customer none;  // Create a default customer object
    if (isEmpty())  // Check if the queue is empty
    {
        cout << "Queue is empty" << endl; // Notify if empty
        return none; // Return default customer object
    }
    else
    {
        customer x = Q[front]; // Store customer at the front
        front = (front + 1) % size; // Update front index (circular increment)
        return x; // Return the removed customer
    }
}

// Method to display all customers in the queue
void queue::display()
{
    if (isEmpty())  // Check if the queue is empty
    {
        cout << "Queue is empty" << endl; // Notify if empty
    }
    else
    {
        cout << "Queue: ";
        int i = front; // Start from the front index
        do
        {
            Q[i].display(); // Display each customer's data
            i = (i + 1) % size; // Move to the next index (circular increment)
        } while (i != rear); // Continue until we reach the rear
        cout << endl;
    }
}

// Method to get the customer at the front of the queue without removing it
customer queue::queueFront()
{
    customer none; // Create a default customer object
    if (isEmpty()) // Check if the queue is empty
    {
        cout << "Queue Empty!" << endl; // Notify if empty
        return none; // Return default customer object
    }
    else
    {
        return Q[front]; // Return customer at the front
    }
}

// Method to get the customer at the rear of the queue without removing it
customer queue::queueRear()
{
    customer none; // Create a default customer object
    if (isEmpty()) // Check if the queue is empty
    {
        cout << "Queue Empty!" << endl; // Notify if empty
        return none; // Return default customer object
    }
    else
    {
        return Q[(rear - 1 + size) % size]; // Return customer at the rear
    }
}

// Destructor to free the allocated memory for the queue
queue::~queue()
{
    delete[] Q; // Free the dynamically allocated array
}

// Method to check if the queue is full
bool queue::isFull()
{
    return (rear + 1) % size == front; // Full if next rear index is front
}

// Method to check if the queue is empty
bool queue::isEmpty()
{
    return front == rear; // Empty if front equals rear
}

// Main function to interact with the customer queue
int main()
{
    queue shop(5); // Create a queue for 5 customers
    while (1) // Infinite loop for user interaction
    {
        int choice; // Variable to store user's choice
        cout << "1. Add Customer to waitlist" << endl;
        cout << "2. Serve Customer" << endl;
        cout << "3. Display Waitlist" << endl;
        cout << "4. Close Counter" << endl;
        cout << "Enter your Choice: "; // Prompt for choice
        cin >> choice; // Read user's choice
        switch (choice)
        {
        case 1:
            shop.enqueue(); // Add customer to the waitlist
            break;
        case 2:
            cout << "Serving Customer...." << endl << endl;
            shop.dequeue().display(); // Serve and display the customer
            break;
        case 3:
            cout << endl << endl;
            shop.display(); // Display the current waitlist
            break;
        case 4:
            cout << "Counter Closed!" << endl; // Close the counter
            return 0; // Exit the program
        default:
            break; // Invalid choice, do nothing
        }
    }
}
