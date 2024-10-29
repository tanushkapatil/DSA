#include <iostream>
#include <string>
using namespace std;

struct Song {
    string title;
    string artist;
    float duration;
    Song* next; // pointer to the next song
};

class Playlist {
    Song* head; // pointer to the first song
public:
    Playlist() {
        head = NULL;  // Initialize head to NULL
    }

    void insert_at_end(string title, string artist, float duration) {
        Song* nn = new Song; // Create a new song node
        if (nn == NULL)  // Check if memory allocation failed
            return;
        nn->title = title;
        nn->artist = artist;
        nn->duration = duration;
        nn->next = NULL;  // The new song points to nothing

        if (head == NULL) {
            head = nn;  // If the list is empty, make the new song the head
        } else {
            Song* temp = head;
            while (temp->next)  // Traverse to the last song
                temp = temp->next;
            temp->next = nn;  // Link the last song to the new song
        }
    }

    void search_a_song(string artist) {
        Song* temp = head;
        bool found = false;
        while (temp) {
            if (temp->artist == artist) {  // Match found
                cout << temp->title << " " << temp->artist << " " << temp->duration << endl;
                found = true;
            }
            temp = temp->next;
        }
        if (!found) {
            cout << "No songs found by artist " << artist << endl;
        }
    }

    void print_records() {
        Song* temp = head;
        if (temp == NULL) {
            cout << "The playlist is empty." << endl;
            return;
        }
        while (temp) {
            cout << temp->title << " " << temp->artist << " " << temp->duration << endl;
            temp = temp->next;
        }
    }

    void remove_a_song(string artist) {
        Song* temp = head;
        Song* prev = NULL;

        if (head != NULL && head->artist == artist) {  // Check if the song to be deleted is the head
            head = head->next;  // Move the head to the next song
            delete temp;  // Delete the old head
            cout << "Song by artist " << artist << " removed from the playlist." << endl;
            return;
        }

        while (temp) {  // Traverse until the song is found
            if (temp->artist == artist) {
                prev->next = temp->next;
                Song* songToBeDeleted = temp;
                temp = temp->next;
                delete songToBeDeleted;
                cout << "Song by artist " << artist << " removed from the playlist." << endl;
            } else {
                prev = temp;
                temp = temp->next;
            }
        }
    }
};

int main() {
    Playlist myList;
    int choice;
    string title, artist;
    float duration;

    do {
        cout << "\nMenu:\n";
        cout << "1. Add Song\n";
        cout << "2. Search Song by Artist\n";
        cout << "3. Print Playlist\n";
        cout << "4. Remove Song by Artist\n";
        cout << "5. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                cout << "Enter song title: ";
                cin.ignore();  // Clear the newline character from the input buffer
                getline(cin, title);
                cout << "Enter artist name: ";
                getline(cin, artist);
                cout << "Enter duration: ";
                cin >> duration;
                myList.insert_at_end(title, artist, duration);
                break;

            case 2:
                cout << "Enter artist name to search: ";
                cin.ignore();  // Clear the newline character from the input buffer
                getline(cin, artist);
                myList.search_a_song(artist);
                break;

            case 3:
                cout << "Playlist:\n";
                myList.print_records();
                break;

            case 4:
                cout << "Enter artist name to remove: ";
                cin.ignore();  // Clear the newline character from the input buffer
                getline(cin, artist);
                myList.remove_a_song(artist);
                break;

            case 5:
                cout << "Exiting...\n";
                break;

            default:
                cout << "Invalid choice! Please try again.\n";
        }
    } while (choice != 5);

    return 0;
}
