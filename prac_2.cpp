#include <iostream>
using namespace std;

void swap(int arr[], int i, int j) {
    int temp = arr[i];
    arr[i] = arr[j];
    arr[j] = temp;
}

int partition(int arr[], int start, int end) {
    int pivot = arr[end];
    int i = start - 1;

    for (int j = start; j < end; j++) {
        if (arr[j] < pivot) {
            i++;
            swap(arr, i, j);
            cout << arr[] ;
        }
    }
    swap(arr, i + 1, end); // Place the pivot in the correct position
    return i + 1; // Return the index of the pivot
}

void qs(int arr[], int start, int end) {
    if (start < end) {
        int pivotIndex = partition(arr, start, end);
        qs(arr, start, pivotIndex - 1);
        qs(arr, pivotIndex + 1, end);
    }
}

int main() {
    int arr[] = {10, 7, 8, 9, 1, 5};
    int n = sizeof(arr) / sizeof(arr[0]);
    
    qs(arr, 0, n - 1);
    
    cout << "Sorted array: ";
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;

    return 0;
}