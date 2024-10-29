// Name : Tanushka Patil
// Prn No. : 123B1B036

#include<iostream>
using namespace std;

// Class representing a Student with roll number, name, and SGPA (Semester Grade Point Average)
class Student {
    private:
        int roll_no;       // Roll number of the student
        string name;       // Name of the student
        double sgpa;       // SGPA of the student

    public:
        // Default constructor initializing member variables
        Student() {
            roll_no = 0;
            name = " ";
            sgpa = 0.0;
        }

        // Parameterized constructor initializing member variables with provided values
        Student(int rn, string n, double s) {
            roll_no = rn;
            name = n;
            sgpa = s;
        }

        // Setter methods to set the values of member variables
        void setRollNo(int rn) {
            roll_no = rn;
        }

        void setName(string n) {
            name = n;
        }

        void setSGPA(double s) {
            sgpa = s;
        }

        // Getter methods to retrieve the values of member variables
        int getRollNo() {
            return roll_no;
        }

        string getName() {
            return name;
        }

        double getSGPA() {
            return sgpa;
        }
};

// Class representing a collection of students in SYCOMP (Second Year Computer Engineering)
class SYCOMP {
    private:
        int num;             // Number of students
        Student *Stud_Data;  // Pointer to array of Student objects

    public:
        // Function to get data (roll number, name, SGPA) of students from the user
        int fnGetData() {
            cout << "Enter the number of students: ";
            cin >> num;
            int rn;
            double sgpa;
            string name;
            Stud_Data = new Student[num];  // Dynamically allocate memory for the students

            // Loop to get the details of each student
            for (int i = 0; i < num; i++) {
                cout << "Enter the details of student (Roll No, Name, SGPA): ";
                cin >> rn;
                Stud_Data[i].setRollNo(rn);
                cin >> name;
                Stud_Data[i].setName(name);
                cin >> sgpa;
                Stud_Data[i].setSGPA(sgpa);
            }
            return num;
        }

        // Function to print the details of all students
        void fnPrintData() {
            cout << "Sorted List: " << endl;
            for (int i = 0; i < num; i++) {
                cout << "Student: ";
                cout << Stud_Data[i].getRollNo() << " ";
                cout << Stud_Data[i].getName() << " ";
                cout << Stud_Data[i].getSGPA() << " \n ";
            }
        }

        // Function to perform Insertion Sort based on roll number
        void insertionSort() {
            int i = 0;
            for (i = 1; i < num; i++) {
                Student temp = Stud_Data[i];  // Store the current student
                int j = i - 1;
                // Shift elements to the right to make space for the current student
                for (; j >= 0; j--) {
                    if (Stud_Data[j].getRollNo() > temp.getRollNo()) {
                        Stud_Data[j + 1] = Stud_Data[j];
                    } else
                        break;
                }
                Stud_Data[j + 1] = temp;  // Place the current student in the correct position
            }
        }

        // Function to perform Shell Sort based on name
        void shellSort() {
            int i = 0;
            int gap = num / 2;
            while (gap >= 1) {
                for (i = 1; i < num; i++) {
                    Student temp = Stud_Data[i];  // Store the current student
                    int j = i - gap;
                    // Perform gapped insertion sort
                    for (; j >= 0; j -= gap) {
                        if (Stud_Data[j].getName() > temp.getName()) {
                            Stud_Data[j + gap] = Stud_Data[j];
                        } else
                            break;
                    }
                    Stud_Data[j + gap] = temp;  // Place the current student in the correct position
                }
                gap /= 2;  // Reduce the gap for the next pass
            }
        }

        // Helper function for Radix Sort to perform counting sort on the basis of significant digit
        void countSort(int exp) {
            int countArr[10] = {0};        // Array to store the count of digits
            Student OutputArray[num];      // Array to store the sorted output

            // Count the occurrences of digits
            for (int i = 0; i < num; i++)
                countArr[(Stud_Data[i].getRollNo() / exp) % 10]++;

            // Update countArr to have the actual position of digits
            for (int i = 1; i < 10; i++)
                countArr[i] += countArr[i - 1];

            // Build the output array
            for (int i = num - 1; i >= 0; i--) {
                OutputArray[countArr[(Stud_Data[i].getRollNo() / exp) % 10] - 1] = Stud_Data[i];
                countArr[(Stud_Data[i].getRollNo() / exp) % 10]--;
            }

            // Copy the output array to Stud_Data
            for (int i = 0; i < num; i++)
                Stud_Data[i] = OutputArray[i];
        }

        // Function to perform Radix Sort based on roll number
        void radixSort() {
            int Max = Stud_Data[0].getRollNo();
            // Find the maximum roll number to determine the number of digits
            for (int i = 0; i < num; i++)
                if (Stud_Data[i].getRollNo() > Max)
                    Max = Stud_Data[i].getRollNo();

            // Perform counting sort for each digit (exp is 10^i where i is the digit position)
            for (int ex = 1; Max / ex > 1; ex *= 10)
                countSort(ex);
        }
};

int main() {
    SYCOMP obj1;  // Create an object of SYCOMP class
    int size = obj1.fnGetData();  // Get student data

    int choice;
    do {
        // Display the menu for sorting options
        cout << "\nChoose the sorting method:\n";
        cout << "\n";
        cout << "1. Insertion Sort (by Roll Number)\n";
        cout << "2. Shell Sort (by Name)\n";
        cout << "3. Radix Sort (by Roll Number)\n";
        cout << "4. Exit\n";
        cout << "\n";
        cout << "Enter your choice: ";
        cin >> choice;
        cout << "\n";
        
        // Perform the selected sorting method
        switch(choice) {
            case 1:
                cout << "Data Sorted as per Roll Number (Insertion Sort):\n";
                cout << "\n";
                obj1.insertionSort();  // Sort by roll number using Insertion Sort
                obj1.fnPrintData();    // Print the sorted data
                break;
            case 2:
                cout << "Data Sorted as per Names (Shell Sort):\n";
                cout << "\n";
                obj1.shellSort();      // Sort by name using Shell Sort
                obj1.fnPrintData();    // Print the sorted data
                break;
            case 3:
                cout << "Data Sorted as per Roll Numbers (Radix Sort):\n";
                cout << "\n";
                obj1.radixSort();      // Sort by roll number using Radix Sort
                obj1.fnPrintData();    // Print the sorted data
                break;
            case 4:
                cout << "Exiting program.\n";  // Exit the program
                break;
            default:
                cout << "Invalid choice! Please select a valid option.\n";  // Handle invalid choice
        }
    } while (choice != 4);  // Continue until the user chooses to exit

    return 0;
}

