#include <stdio.h>
#include <stdlib.h>

// Function prototypes
void bubbleSort(int arr[], int n);
void insertionSort(int arr[], int n);
void selectionSort(int arr[], int n);
void mergeSort(int arr[], int left, int right);
void quickSort(int arr[], int low, int high);
void merge(int arr[], int left, int mid, int right);
int partition(int arr[], int low, int high);
void displayArray(int arr[], int n);

// Bubble Sort function
void bubbleSort(int arr[], int n) {
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
}

// Insertion Sort function
void insertionSort(int arr[], int n) {
    for (int i = 1; i < n; i++) {
        int key = arr[i];
        int j = i - 1;
        while (j >= 0 && arr[j] > key) {
            arr[j + 1] = arr[j];
            j--;
        }
        arr[j + 1] = key;
    }
}

// Selection Sort function
void selectionSort(int arr[], int n) {
    for (int i = 0; i < n - 1; i++) {
        int minIndex = i;
        for (int j = i + 1; j < n; j++) {
            if (arr[j] < arr[minIndex]) {
                minIndex = j;
            }
        }
        int temp = arr[minIndex];
        arr[minIndex] = arr[i];
        arr[i] = temp;
    }
}

// Merge Sort function
void mergeSort(int arr[], int left, int right) {
    if (left < right) {
        int mid = left + (right - left) / 2;
        mergeSort(arr, left, mid);
        mergeSort(arr, mid + 1, right);
        merge(arr, left, mid, right);
    }
}

void merge(int arr[], int left, int mid, int right) {
    int n1 = mid - left + 1;
    int n2 = right - mid;

    int L[n1], R[n2];
    for (int i = 0; i < n1; i++) L[i] = arr[left + i];
    for (int i = 0; i < n2; i++) R[i] = arr[mid + 1 + i];

    int i = 0, j = 0, k = left;
    while (i < n1 && j < n2) {
        if (L[i] <= R[j]) {
            arr[k] = L[i];
            i++;
        } else {
            arr[k] = R[j];
            j++;
        }
        k++;
    }

    while (i < n1) arr[k++] = L[i++];
    while (j < n2) arr[k++] = R[j++];
}

// Quick Sort function
void quickSort(int arr[], int low, int high) {
    if (low < high) {
        int pi = partition(arr, low, high);
        quickSort(arr, low, pi - 1);
        quickSort(arr, pi + 1, high);
    }
}

int partition(int arr[], int low, int high) {
    int pivot = arr[high];
    int i = (low - 1);
    for (int j = low; j < high; j++) {
        if (arr[j] <= pivot) {
            i++;
            int temp = arr[i];
            arr[i] = arr[j];
            arr[j] = temp;
        }
    }
    int temp = arr[i + 1];
    arr[i + 1] = arr[high];
    arr[high] = temp;
    return (i + 1);
}

// Function to display array
void displayArray(int arr[], int n) {
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

// Main function
int main() {
    int choice, n, i;
    int arr[100];

    while (1) {
        printf("\nMenu:\n");
        printf("1. Bubble Sort\n");
        printf("2. Insertion Sort\n");
        printf("3. Selection Sort\n");
        printf("4. Merge Sort\n");
        printf("5. Quick Sort\n");
        printf("6. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        if (choice == 6) {
            printf("Exiting program.\n");
            break;
        }

        printf("Enter the number of elements in the array: ");
        scanf("%d", &n);
        printf("Enter the array elements:\n");
        for (i = 0; i < n; i++) {
            scanf("%d", &arr[i]);
        }

        switch (choice) {
            case 1:
                bubbleSort(arr, n);
                printf("Sorted array using Bubble Sort: ");
                displayArray(arr, n);
                break;
            case 2:
                insertionSort(arr, n);
                printf("Sorted array using Insertion Sort: ");
                displayArray(arr, n);
                break;
            case 3:
                selectionSort(arr, n);
                printf("Sorted array using Selection Sort: ");
                displayArray(arr, n);
                break;
            case 4:
                mergeSort(arr, 0, n - 1);
                printf("Sorted array using Merge Sort: ");
                displayArray(arr, n);
                break;
            case 5:
                quickSort(arr, 0, n - 1);
                printf("Sorted array using Quick Sort: ");
                displayArray(arr, n);
                break;
            default:
                printf("Invalid choice! Please try again.\n");
        }
    }

    return 0;
}
