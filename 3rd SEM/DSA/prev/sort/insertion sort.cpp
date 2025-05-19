#include<stdio.h>
#include<stdlib.h>
void insertionSort(int arr[], int n) {
    int k, j, temp;
    for (k = 1; k < n; k++) {
        temp = arr[k];
        for (j = k - 1; j >= 0 && arr[j] > temp; j--) {
            arr[j + 1] = arr[j]; // Shift elements greater than temp to the right
        }
        arr[j + 1] = temp; 
        printArray(arr, n); 
    }
}

int main() {
    int arr[] = {23, 45, 12, 7, 9, 2, 11, 5, 14, 8};
    int n = sizeof(arr) / sizeof(int);

    system("CLS");
    printf("Before sorting............\n");
    printArray(arr, n);

    insertionSort(arr, n);

    printf("\nAfter sorting........\n");
    printArray(arr, n);

    return 0;
}

