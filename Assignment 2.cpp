// Name : Tanushka Patil
// Prn No. : 123B1B036

#include <iostream>
#include <string>
using namespace std;

// Class representing an Employee with ID, name, and salary
class Employee {
private:
    int empID;     // Employee ID
    string ename;  // Employee name

public:
    // Default constructor initializing member variables
    Employee() {
        empID = 0;
        ename = "";
    }

    // Parameterized constructor initializing member variables with provided values
    Employee(int id, string name) {
        empID = id;
        ename = name;
    }

    // Setter methods to set the values of member variables
    void setEmpID(int id) {
        empID = id;
    }

    void setEmpName(string name) {
        ename = name;
    }

    // Getter methods to retrieve the values of member variables
    int getID() {
        return empID;
    }

    string getName() {
        return ename;
    }
};

// Function to partition the array based on the pivot element for Quick Sort
int partition(Employee arr[], int start, int end) {
    int pivot = arr[start].getID();  // Pivot is the ID of the first element
    int i = start, j = end;

    // Rearrange elements based on the pivot
    while (i < j) {
        while (i <= end && arr[i].getID() <= pivot)
            i++;
        while (arr[j].getID() > pivot)
            j--;
        if (i < j) {
            // Swap elements if out of order
            Employee temp = arr[i];
            arr[i] = arr[j];
            arr[j] = temp;
        }
    }

    // Swap the pivot element to its correct position
    Employee temp = arr[start];
    arr[start] = arr[j];
    arr[j] = temp;

    return j;  // Return the position of the pivot
}

// Quick Sort function to sort the array of Employee objects by EMP-ID
void QuickSort(Employee arr[], int start, int end) {
    if (start < end) {
        int pivotPosition = partition(arr, start, end);  // Partition the array
        QuickSort(arr, start, pivotPosition - 1);        // Recursively sort the left part
        QuickSort(arr, pivotPosition + 1, end);          // Recursively sort the right part
    }
}

// Function to print the array of Employee objects
void printArr(Employee arr[], int len) {
    for (int i = 0; i < len; i++) {
        cout << arr[i].getID() << " - " << arr[i].getName() << "\n";
    }
}

// Merge two subarrays of Employee objects by EMP-Name (alphabetically)
void mergeArray(Employee Arr[], int s, int m, int e) {
    int len1 = m - s + 1;  // Length of the first subarray
    int len2 = e - m;      // Length of the second subarray
    Employee* tempArr1 = new Employee[len1];
    Employee* tempArr2 = new Employee[len2];

    // Copy data to temporary arrays
    for (int i = 0; i < len1; i++)
        tempArr1[i] = Arr[s + i];
    for (int i = 0; i < len2; i++)
        tempArr2[i] = Arr[m + 1 + i];

    int leftIndex = 0, rightIndex = 0, mergedIndex = s;

    // Merge the temporary arrays back into the main array
    while (leftIndex < len1 && rightIndex < len2) {
        if (tempArr1[leftIndex].getName() < tempArr2[rightIndex].getName()) {
            Arr[mergedIndex] = tempArr1[leftIndex];
            leftIndex++;
        } else {
            Arr[mergedIndex] = tempArr2[rightIndex];
            rightIndex++;
        }
        mergedIndex++;
    }

    // Copy the remaining elements of tempArr1
    while (leftIndex < len1) {
        Arr[mergedIndex] = tempArr1[leftIndex];
        leftIndex++;
        mergedIndex++;
    }

    // Copy the remaining elements of tempArr2
    while (rightIndex < len2) {
        Arr[mergedIndex] = tempArr2[rightIndex];
        rightIndex++;
        mergedIndex++;
    }

    // Clean up the dynamically allocated memory
    delete[] tempArr1;
    delete[] tempArr2;
}

// Merge Sort function to sort the array of Employee objects by EMP-Name (alphabetically)
void mergeSort(Employee Arr[], int start, int endIndex) {
    if (start >= endIndex)
        return;

    int mid = (start + endIndex) / 2;
    mergeSort(Arr, start, mid);       // Recursively sort the first half
    mergeSort(Arr, mid + 1, endIndex); // Recursively sort the second half
    mergeArray(Arr, start, mid, endIndex); // Merge the sorted halves
}

// Main function
int main() {
    // Array of Employee objects with EMP-ID and EMP-Name
    Employee arr[] = {
        {13, "abc"}, {1, "xyz"}, {58, "uvw"}, {23, "def"}, {45, "mno"}, 
        {34, "ghi"}, {19, "jkl"}, {8, "rst"}, {29, "opq"}, {4, "efg"},
        {21, "stu"}, {56, "lmn"}, {30, "tuv"}, {9, "vwx"}, {42, "yzx"}, 
        {17, "lma"}, {28, "nop"}, {55, "pqr"}, {66, "sbc"}, {2, "aac"}
    };

    int len = sizeof(arr) / sizeof(Employee);
    int choice;

    do {
        cout << "\nMenu:\n";
        cout << "1. Sort by EMP-ID (Quick Sort)\n";
        cout << "2. Sort by EMP-Name (Merge Sort)\n";
        cout << "3. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                // Quick Sort by EMP-ID
                QuickSort(arr, 0, len - 1);
                cout << "Employee list sorted by EMP-ID (Quick Sort):\n";
                printArr(arr, len);
                break;

            case 2:
                // Merge Sort by EMP-Name
                mergeSort(arr, 0, len - 1);
                cout << "Employee list sorted alphabetically by Name (Merge Sort):\n";
                printArr(arr, len);
                break;

            case 3:
                cout << "Exiting program.\n";
                break;

            default:
                cout << "Invalid choice. Please try again.\n";
                break;
        }
    } while (choice != 3);

    return 0;
}
