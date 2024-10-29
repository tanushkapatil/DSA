// Name : Tanushka Patil
// Prn No. : 123B1B036

#include<iostream>
using namespace std;

// Node structure for the doubly linked list
struct Node {
    string data;   // Data (text) contained in each node
    Node* prev;    // Pointer to the previous node
    Node* next;    // Pointer to the next node
};

// Class for managing the text editor with a doubly linked list (acting as a text buffer)
class TextEditor {
    Node* head;    // Pointer to the first node (start of the buffer)

public:
    // Constructor initializing head and tail pointers to NULL
    TextEditor() {
        head = NULL;
    }

    // Function to insert text at the end of the buffer
    void insertAtEnd(string value) {
        Node* nn = new Node();    // Create a new node
        nn->data = value;         // Set the node's data to the input string
        nn->prev = NULL;
        nn->next = NULL;

        // If the list is empty, the new node becomes both head and tail
        if (head == NULL) {
            head = nn;
        } 
        else {
        // Otherwise, insert the new node at the end of the list
            Node* t = head ;
            while(t->next)
                t = t->next ;
            nn->next = NULL;
            nn->prev = t ;
            t->next = nn ;
        }
    }
    
    // Function to delete text by matching data in a node
    void deleteText(string value) {
        if(!head)  //If head != NULL
            return;
        Node* temp = head;

        while (temp != NULL) {
            if (temp->data == value) {
                // If it's not the head node
                if (temp->prev != NULL) {
                    temp->prev->next = temp->next;
                } 
                else {
                    // Deleting the head node
                    head = temp->next;
                }

                // If it's not the last node
                if (temp->next != NULL) {
                    temp->next->prev = temp->prev;
                }

                delete temp; // Delete the current node
                
            }
            temp = temp->next;  // Move to the next node
        }
        cout << "Text not found in buffer.\n";
    }

    void searchText(string value) {
        Node* temp = head;
        int position = 1; // Position counter

        while (temp != NULL) {
            if (temp->data == value) {
                cout << "Text '" << value << "' found at position " << position << "." << endl;
                return;
            }
            temp = temp->next;
            position++;
        }

        cout << "Text '" << value << "' not found in the buffer." << endl;
    }


    void displayTextReverse() {
        Node* t = head ;
        while(t->next)
            t = t-> next ;
            while(t) {
                cout << t->data << " " ;
                t = t->prev;
            }
    }
    // Function to display the text buffer from start to end
    void displayText() {
        Node* temp = head;
        while (temp != NULL) {
            cout << temp->data << " " << endl;  // Print the data stored in each node
            temp = temp->next;          // Move to the next node
        }
        cout << endl;
    }
};

int main() {
    TextEditor editor;   
    int choice;
    string text;

    do {
        cout << "\nText Editor Menu:\n";
        cout << "1. Insert Text\n";
        cout << "2. Delete Text\n";
        cout << "3. Search Text\n";
        cout << "4. Display Text\n";
        cout << "5. Display Text in Reverse\n";
        cout << "6. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch(choice) {
            case 1:
                cout << "Enter text to insert: ";
                cin.ignore();
                getline(cin, text);
                editor.insertAtEnd(text);
                break;
            
            case 2:
                cout << "Enter text to delete: ";
                cin.ignore();
                getline(cin, text);
                editor.deleteText(text);
                break;

            case 3:
                cout << "Enter text to search: ";
                cin.ignore();
                getline(cin, text);
                editor.searchText(text);
                break;

            case 4:
                cout << "Displaying text buffer:\n";
                editor.displayText();
                break;

            case 5:
                cout << "Displaying text buffer in reverse:\n";
                editor.displayTextReverse();
                break;

            case 6:
                cout << "Exiting the program.\n";
                break;

            default:
                cout << "Invalid choice. Please try again.\n";
        }
    } while (choice != 6);

    return 0;
}
