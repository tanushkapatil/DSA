// Name : Tanushka Patil
// Prn No. : 123B1B036

#include <iostream> // Include the iostream library for input and output operations
using namespace std; // Use the standard namespace

// Define a structure for a polynomial node
struct PolyNode {
    int coeff; // Coefficient of the polynomial term
    int power; // Power/exponent of the polynomial term
    PolyNode* next; // Pointer to the next node in the linked list
};

// Define a class to represent a polynomial expression
class PolyExpression {
    PolyNode* head; // Pointer to the head of the linked list representing the polynomial

public:
    // Constructor to initialize the polynomial expression
    PolyExpression() {
        head = NULL; // Initialize head to NULL, indicating the polynomial is empty
    }

    // Function to get the head of the polynomial linked list
    PolyNode* getHead() {
        return head; // Return the head pointer
    }

    // Function to insert a new polynomial term
    void insertPoly(int coeff, int power) {
        PolyNode* nn = new PolyNode(); // Create a new node
        nn->coeff = coeff; // Set the coefficient of the node
        nn->power = power; // Set the power of the node
        nn->next = NULL; // Initialize next pointer to NULL

        // If the linked list is empty, make the new node the head
        if (head == NULL) {
            head = nn; // Set head to point to the new node
        } else {
            PolyNode* t = head; // Temporary pointer to traverse the linked list
            // Traverse to the end of the linked list
            while (t->next != NULL) {
                t = t->next; // Move to the next node
            }
            t->next = nn; // Attach the new node at the end
        }
    }

    // Function to display the polynomial in a human-readable format
    void displayText() {
        if (!head) return; // If the list is empty, do nothing
        PolyNode* temp = head; // Temporary pointer to traverse the linked list
        bool isFirst = true; // Flag to check if it's the first term

        // Traverse the linked list
        while (temp != NULL) {
            if (!isFirst) {
                cout << " + "; // Add plus sign for subsequent terms
            }
            isFirst = false; // Set the flag to false after the first term
            cout << temp->coeff << "x^" << temp->power; // Display the term
            temp = temp->next; // Move to the next node
        }
        cout << endl; // Print a newline at the end
    }
};

// Define a class for polynomial operations
class PolyOperations {
public:
    // Function to add two polynomial expressions
    void AddPoly(PolyExpression p1, PolyExpression p2, PolyExpression* result) {
        PolyNode* t1 = p1.getHead(); // Get the head of the first polynomial
        PolyNode* t2 = p2.getHead(); // Get the head of the second polynomial

        // Traverse both polynomials to add them
        while (t1 != NULL && t2 != NULL) {
            if (t1->power > t2->power) {
                result->insertPoly(t1->coeff, t1->power); // Insert term from p1
                t1 = t1->next; // Move to the next term in p1
            } else if (t1->power < t2->power) {
                result->insertPoly(t2->coeff, t2->power); // Insert term from p2
                t2 = t2->next; // Move to the next term in p2
            } else {
                // If powers are equal, add coefficients and insert
                result->insertPoly(t1->coeff + t2->coeff, t1->power);
                t1 = t1->next; // Move to the next term in p1
                t2 = t2->next; // Move to the next term in p2
            }
        }
        // Insert remaining terms from p1
        while (t1) {
            result->insertPoly(t1->coeff, t1->power);
            t1 = t1->next; // Move to the next term in p1
        }
        // Insert remaining terms from p2
        while (t2) {
            result->insertPoly(t2->coeff, t2->power);
            t2 = t2->next; // Move to the next term in p2
        }
    }
};

// Main function to execute the polynomial operations
int main() {
    PolyExpression p1, p2, result; // Create three polynomial expressions
    PolyOperations exp; // Create an instance of PolyOperations
    int choice, coeff, power; // Variables to hold user choices, coefficients, and powers

    do {
        // Display the menu for polynomial operations
        cout << "\nPolynomial Operations Menu\n";
        cout << "1. Insert Polynomial 1\n";
        cout << "2. Insert Polynomial 2\n";
        cout << "3. Display Polynomial 1\n";
        cout << "4. Display Polynomial 2\n";
        cout << "5. Add Polynomials\n";
        cout << "6. Display Resultant Polynomial\n";
        cout << "0. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice; // Get user choice

        switch (choice) {
            case 1: // Insert a term into polynomial 1
                cout << "Enter coefficient and power: ";
                cin >> coeff >> power; // Read coefficient and power
                p1.insertPoly(coeff, power); // Insert into polynomial 1
                break;

            case 2: // Insert a term into polynomial 2
                cout << "Enter coefficient and power: ";
                cin >> coeff >> power; // Read coefficient and power
                p2.insertPoly(coeff, power); // Insert into polynomial 2
                break;

            case 3: // Display polynomial 1
                cout << "Polynomial 1: ";
                p1.displayText(); // Call the display function for polynomial 1
                break;

            case 4: // Display polynomial 2
                cout << "Polynomial 2: ";
                p2.displayText(); // Call the display function for polynomial 2
                break;

            case 5: // Add polynomials
                exp.AddPoly(p1, p2, &result); // Add p1 and p2, store in result
                cout << "Polynomials added successfully.\n"; // Confirmation message
                break;

            case 6: // Display the resultant polynomial
                cout << "Resultant Polynomial: ";
                result.displayText(); // Call the display function for the result
                break;

            case 0: // Exit the program
                cout << "Exiting...\n"; // Exit message
                break;

            default: // Handle invalid choice

                cout << "Invalid choice! Please try again.\n";
                break;
        }
    } while (choice != 0);

    return 0;
}
