// Name : Tanushka Patil
// Prn No. : 123B1B036

#include <iostream>
using namespace std;

// Node structure for the doubly linked list
struct Node {
    string data;   // Data (text) contained in each node
    Node* next;    // Pointer to the next node
};

class NavigationSystem {
    Node* tail;    // Pointer to the last node (start of the buffer)

public:
    // Constructor initializing tail pointer to NULL
    NavigationSystem() {
        tail = NULL;
    }

    // Function to insert text at the end of the buffer
    void insertAtEnd(string value) {
        Node* nn = new Node;
        nn->data = value;

        if (tail == NULL) {
            // If the list is empty, the new node points to itself (circular)
            tail = nn;
            nn->next = nn;
        } else {
            // Insert new node at the end and adjust the circular links
            nn->next = tail->next;  // Point new node to the first node (tail->next)
            tail->next = nn;        // Tail's next now points to the new node
            tail = nn;              // Update tail to be the new node
        }
    }

    void insertAtFirst(string value) {
        Node* nn = new Node;
        nn->data = value;

        if (tail == NULL) {
            // If the list is empty, the new node points to itself (circular)
            tail = nn;
            nn->next = nn;
        } else {
            // Insert new node at the front and adjust the circular links
            nn->next = tail->next;  // New node points to the first node
            tail->next = nn;        // Tail's next now points to the new node
        }
    }

    void deleteRoute(string value) {
        if (!tail) {  // If the list is empty
            cout << "The buffer is empty.\n";
            return;
        }

        Node* t = tail->next;  // Start from the first node (head)
        Node* p = tail;        // Previous node (tail initially)

        do {
            if (t->data == value) {
                // If there's only one node in the list
                if (t == tail && t->next == tail) {
                    delete t;
                    tail = nullptr;  // List is now empty
                    cout << "Deleted the only node in the list.\n";
                    return;
                }

                // If the node to delete is the head (tail->next)
                if (t == tail->next) {
                    tail->next = t->next;  // Update tail->next to the next node
                }

                // If the node to delete is the tail
                if (t == tail) {
                    tail = p;  // Update tail to the previous node
                }

                // Bypass the current node
                p->next = t->next;

                // Delete the node
                Node* ntbd = t;   // Node to be deleted
                t = t->next;      // Move to the next node before deletion
                delete ntbd;

                cout << "Text deleted from buffer.\n";
                return;
            } else {
                p = t;            // Move `p` to the current node
                t = t->next;      // Move `t` to the next node
            }
        } while (t != tail->next);  // Stop when we loop back to the head

        // If we complete the loop and don't find the value
        cout << "Text not found in buffer.\n";
    }

    // Function to display the circular linked list
    void displayRoute() {
        if (tail == NULL) {
            cout << "The buffer is empty!" << endl;
            return;
        }

        Node* temp = tail->next; // Start from the first node (tail->next)
        do {
            cout << temp->data << " -> ";  // Print the data stored in each node
            temp = temp->next;          // Move to the next node
        } while (temp != tail->next);   // Stop when we reach the first node again

        cout << "(back to head)" << endl; // Indicate circular nature
    }
};

int main() {
    NavigationSystem nav;
    int choice;
    string value;

    do {
        cout << "\nNavigation System Menu\n";
        cout << "1. Insert at End\n";
        cout << "2. Insert at First\n";
        cout << "3. Delete Route\n";
        cout << "4. Display Routes\n";
        cout << "0. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                cout << "Enter the text to insert at the end: ";
                cin >> value;
                nav.insertAtEnd(value);
                break;
            case 2:
                cout << "Enter the text to insert at the beginning: ";
                cin >> value;
                nav.insertAtFirst(value);
                break;
            case 3:
                cout << "Enter the text to delete: ";
                cin >> value;
                nav.deleteRoute(value);
                break;
            case 4:
                nav.displayRoute();
                break;
            case 0:
                cout << "Exiting...\n";
                break;
            default:
                cout << "Invalid choice! Please try again.\n";
                break;
        }
    } while (choice != 0);

    return 0;
}
