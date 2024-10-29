// Name : Tanushka Patil
// Prn No. : 123B1B036

#include <iostream>
using namespace std;

// Class to represent a party
class party
{
private:
    string name;             // Name of the party owner
    int participant_count;   // Number of participants in the party

public:
    party();                 // Constructor
    void party_entry_from(); // Function to input party details
    void display();          // Function to display party details
};

// Constructor to initialize party details
party::party(){
    name = "";              // Initialize name as empty
    participant_count = 0;  // Initialize participant count to zero
}

// Function to get party details from user
void party::party_entry_from()
{
    cout << "Enter Name of the owner : ";
    cin >> name; // Input party owner's name
    cout << "Enter Participant Count : ";
    cin >> participant_count; // Input number of participants
}

// Function to display party details
void party::display()
{
    cout << "Name : " << name << endl
         << "Participant Count : " << participant_count << endl
         << "-------------------------------------" << endl;
}

// Class to implement a queue for managing parties
class queue
{
private:
    int size;            // Size of the queue
    int front;           // Index of the front element
    int rear;            // Index of the rear element
    party *Q;           // Pointer to dynamically allocate array of parties
    bool isFull();       // Check if the queue is full
    bool isEmpty();      // Check if the queue is empty

public:
    queue(int x);        // Constructor to initialize the queue with a given size
    void enqueue();      // Function to add a party to the queue
    party dequeue();     // Function to remove a party from the queue
    void display();      // Function to display the queue
    party queueFront();  // Function to get the front party in the queue
    party queueRear();   // Function to get the rear party in the queue
    ~queue();            // Destructor to free allocated memory
};

// Constructor to initialize the queue
queue::queue(int x)
{
    size = x;             // Set size of the queue
    Q = new party[size];  // Dynamically allocate memory for parties
    front = 0;            // Initialize front index
    rear = 0;             // Initialize rear index
}

// Function to add a party to the queue (enqueue)
void queue::enqueue()
{
    if (isFull()) // Check if the queue is full
    {
        cout << "Queue Full!" << endl; // Display message if full
    }
    else
    {
        Q[rear].party_entry_from(); // Get party details from user
        rear = (rear + 1) % size;   // Update rear index circularly
    }
}

// Function to remove a party from the queue (dequeue)
party queue::dequeue()
{
    party none; // Create a default party object
    if (isEmpty()) // Check if the queue is empty
    {
        cout << "Queue is empty" << endl; // Display message if empty
        return none; // Return default party
    }
    else
    {
        party x = Q[front]; // Get the party at the front
        front = (front + 1) % size; // Update front index circularly
        return x; // Return the removed party
    }
}

// Function to display the queue
void queue::display()
{
    if (isEmpty()) // Check if the queue is empty
    {
        cout << "Queue is empty" << endl; // Display message if empty
    }
    else
    {
        cout << "Queue: ";
        int i = front; // Start from the front
        do
        {
            Q[i].display(); // Display each party
            i = (i + 1) % size; // Move to the next party circularly
        } while (i != rear); // Continue until we reach the rear
        cout << endl;
    }
}

// Function to get the party at the front of the queue
party queue::queueFront()
{
    party none; // Create a default party object
    if (isEmpty()) // Check if the queue is empty
    {
        cout << "Queue Empty!" << endl; // Display message if empty
        return none; // Return default party
    }
    else
    {
        return Q[front]; // Return the front party
    }
}

// Function to get the party at the rear of the queue
party queue::queueRear()
{
    party none; // Create a default party object
    if (isEmpty()) // Check if the queue is empty
    {
        cout << "Queue Empty!" << endl; // Display message if empty
        return none; // Return default party
    }
    else
    {
        return Q[(rear - 1 + size) % size]; // Return the rear party
    }
}

// Destructor to free allocated memory
queue::~queue()
{
    delete[] Q; // Free the dynamically allocated array of parties
}

// Check if the queue is full
bool queue::isFull()
{
    return (rear + 1) % size == front; // Check if the next rear would overlap front
}

// Check if the queue is empty
bool queue::isEmpty()
{
    return front == rear; // Check if front equals rear
}

// Main function to run the party queue system
int main(){
    queue restaurant(5); // Create a queue for the restaurant with a maximum size of 5
    while(1){ // Infinite loop to display menu and process user choices
        int choice;
        cout << "1. Add Party to waitlist" << endl;
        cout << "2. Serve Party" << endl;
        cout << "3. Display Waitlist" << endl;
        cout << "4. Close Counter" << endl;
        cout << "Enter your Choice : ";
        cin >> choice; // Get user's choice
        switch (choice)
        {
        case 1: // Add party to waitlist
            restaurant.enqueue(); // Call enqueue function
            break;
        case 2: // Serve the party
            cout << "Serving Customer...." << endl << endl;
            restaurant.dequeue().display(); // Call dequeue and display the served party
            break;
        case 3: // Display waitlist
            cout << endl << endl;
            restaurant.display(); // Call display function to show the

            break;
        case 4:
            cout<<"Counter Closed!"<<endl;
            return 0;
        default:
            break;
        }
    }
}
