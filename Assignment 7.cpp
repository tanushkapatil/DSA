#include"stack.h"

// Main function to run the browser history management system
int main() {
    BrowserHistory browser;
    int choice;
    string page;

    do {
        // Display menu options
        cout << "\n----- Browser History Menu -----\n";
        cout << "1. Visit a new page\n";
        cout << "2. Navigate back\n";
        cout << "3. View current page\n";
        cout << "4. Check if history is empty\n";
        cout << "5. Clear browsing history\n";  // New option to clear history
        cout << "6. Exit\n";
        cout << "Enter your choice (1 to 6): ";
        cin >> choice;

        switch (choice) {
            case 1:  // Add a visited page
                cout << "Enter the page URL or title: ";
                cin >> page;
                browser.visitPage(page);
                break;

            case 2:  // Navigate back
                browser.goBack();
                break;

            case 3:  // View current page
                browser.viewCurrentPage();
                break;

            case 4:  // Check if history is empty
                browser.checkHistoryEmpty();
                break;

            case 5:  // Clear browsing history
                browser.clearHistory();
                break;

            case 6:  // Exit the program
                cout << "Exiting the browser history management system..." << endl;
                break;

            default:
                cout << "Invalid choice. Please enter a valid option (1 to 6)." << endl;
        }
    } while (choice != 6);  // Loop until the user chooses to exit

    return 0;
}
