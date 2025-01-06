// Name : Tanushka Patil
// Prn No. : 123B1B036

#include <iostream>
#include <string>
using namespace std;

#define MAX 100

// Custom Stack class
class Stack {
private:
    string arr[MAX];  // Array to store history pages
    int top;          // To keep track of the top of the stack

public:
    // Constructor
    Stack() {
        top = -1;  // Initially, the stack is empty
    }

    // Function to add a visited page (push operation)
    void push(string page) {
        if (top >= MAX - 1) {
            cout << "History is full. Cannot add more pages." << endl;
        } else {
            top++;         // Move the top pointer to the next position
            arr[top] = page;  // Store the new page at the top
        }
    }

    // Function to navigate back (pop operation)
    string pop() {
        if (top < 0) {
            return "";  // Stack is empty
        } else {
            string poppedPage = arr[top];  // Get the top page
            top--;  // Move the top pointer down
            return poppedPage;  // Return the popped page
        }
    }

    // Function to view the current page (peek operation)
    string peek() const {
        if (top < 0) {
            return "";  // Stack is empty
        } else {
            return arr[top];  // Return the top page
        }
    }

    // Function to check if the stack (history) is empty
    bool isEmpty() const {
        return (top == -1);  // If top is -1, stack is empty
    }

    // Function to clear the entire browsing history
    void clear() {
        top = -1;  // Reset the top pointer, effectively clearing the stack
    }
};

// Browser History Management
class BrowserHistory {
private:
    Stack history;         // Stack to store browsing history
    string current_page;    // Current page being viewed

public:
    // Add a visited page to history
    void visitPage(string page) {
        if (!current_page.empty()) {
            history.push(current_page);  // Push current page to the stack
        }
        current_page = page;  // Set the new page as the current page
        cout << "Visited page: " << current_page << endl;
    }

    // Navigate back to the previous page
    void goBack() {
        if (history.isEmpty()) {
            cout << "No previous page to navigate back to." << endl;
        } else {
            current_page = history.pop();  // Pop from the history stack
            cout << "Navigated back to: " << current_page << endl;
        }
    }

    // View the current page
    void viewCurrentPage() const {
        if (current_page.empty()) {
            cout << "No page is currently open." << endl;
        } else {
            cout << "Current page: " << current_page << endl;
        }
    }

    // Check if the history is empty
    void checkHistoryEmpty() const {
        if (history.isEmpty()) {
            cout << "The browsing history is empty." << endl;
        } else {
            cout << "There are pages in the browsing history." << endl;
        }
    }

    // Clear browsing history
    void clearHistory() {
        history.clear();         // Clear the stack
        current_page.clear();    // Clear the current page
        cout << "Browsing history has been cleared." << endl;
    }
};

