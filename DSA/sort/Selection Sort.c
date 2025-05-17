#include <stdio.h>

// Function to find the index of the smallest element from start to n-1
int findSmallestIndex(int arr[], int start, int n) {
	int i;
    int minIndex = start;
    for ( i = start ; i < n; i++) {
        if (arr[i] < arr[minIndex]) {
            minIndex = i;
        }
    }
    return minIndex;
}

// Selection sort using findSmallestIndex()
void selectionSort(int arr[], int n) {
    int temp, minIndex;
    int i;
    for ( i = 0; i < n - 1; i++) {
        minIndex = findSmallestIndex(arr, i, n);
        // Swap the current element with the smallest found
        temp = arr[i];
        arr[i] = arr[minIndex];
        arr[minIndex] = temp;
    }
}

// Function to print the array
void printArray(int arr[], int n) {
	int i;
    for ( i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

// Main function
int main() {
    int data[] = {20, 5, 18, 3, 7};
    int size = sizeof(data) / sizeof(data[0]);

    printf("Original array:\n");
    printArray(data, size);

    selectionSort(data, size);

    printf("Sorted array:\n");
    printArray(data, size);

    return 0;
}

