#include <stdio.h>
#include <stdbool.h>

// Function prototypes
bool isSorted(int arr[], int size);
void sortArray(int arr[], int size);
int binarySearch(int arr[], int size, int key, int *iterations);
int interpolationSearch(int arr[], int size, int key, int *iterations);

// Check if the array is sorted
bool isSorted(int arr[], int size) {
    for (int i = 1; i < size; i++) {
        if (arr[i] < arr[i - 1]) {
            return false;
        }
    }
    return true;
}

// Sort the array using Bubble Sort
void sortArray(int arr[], int size) {
    for (int i = 0; i < size - 1; i++) {
        for (int j = 0; j < size - i - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
}

// Binary Search Function
int binarySearch(int arr[], int size, int key, int *iterations) {
    int low = 0, high = size - 1;
    while (low <= high) {
        (*iterations)++;
        int mid = low + (high - low) / 2;
        if (arr[mid] == key) {
            return mid;
        } else if (arr[mid] < key) {
            low = mid + 1;
        } else {
            high = mid - 1;
        }
    }
    return -1;
}

// Interpolation Search Function
int interpolationSearch(int arr[], int size, int key, int *iterations) {
    int low = 0, high = size - 1;
    while (low <= high && key >= arr[low] && key <= arr[high]) {
        (*iterations)++;
        if (low == high) {
            if (arr[low] == key) return low;
            return -1;
        }
        int pos = low + ((key - arr[low]) * (high - low)) / (arr[high] - arr[low]);
        if (arr[pos] == key) {
            return pos;
        } else if (arr[pos] < key) {
            low = pos + 1;
        } else {
            high = pos - 1;
        }
    }
    return -1;
}

// Main function
int main() {
    int arr[100], n, choice, key, index, iterations;

    printf("Enter the number of elements in the array: ");
    scanf("%d", &n);
    printf("Enter %d integers: ", n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    // Check if the array is sorted
    if (!isSorted(arr, n)) {
        printf("Array is not sorted. Sorting the array...\n");
        sortArray(arr, n);
        printf("Array has been sorted: ");
        for (int i = 0; i < n; i++) {
            printf("%d ", arr[i]);
        }
        printf("\n");
    }

    do {
        printf("\nMenu:\n");
        printf("1. Binary Search\n");
        printf("2. Interpolation Search\n");
        printf("3. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter the element to search: ");
                scanf("%d", &key);
                iterations = 0;
                index = binarySearch(arr, n, key, &iterations);
                if (index != -1) {
                    printf("Element found at index %d using Binary Search.\n", index);
                } else {
                    printf("Element not found using Binary Search.\n");
                }
                printf("Number of iterations: %d\n", iterations);
                break;

            case 2:
                printf("Enter the element to search: ");
                scanf("%d", &key);
                iterations = 0;
                index = interpolationSearch(arr, n, key, &iterations);
                if (index != -1) {
                    printf("Element found at index %d using Interpolation Search.\n", index);
                } else {
                    printf("Element not found using Interpolation Search.\n");
                }
                printf("Number of iterations: %d\n", iterations);
                break;

            case 3:
                printf("Exiting...\n");
                break;

            default:
                printf("Invalid choice! Please try again.\n");
        }
    } while (choice != 3);

    return 0;
}
