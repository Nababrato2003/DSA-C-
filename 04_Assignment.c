#include <stdio.h>
#include <stdlib.h>

#define MAX 5  // Maximum size of the circular queue

int queue[MAX];
int front = -1;
int rear = -1;


void CENQUE() {
    int element;

    if ((front == 0 && rear == MAX - 1) || (rear == (front - 1) % (MAX - 1))) {
        printf("Queue is full. Insertion not possible.\n");
        return;
    }

    printf("Enter the element to insert: ");
    scanf("%d", &element);

    if (front == -1) {  
        front = rear = 0;
    } else if (rear == MAX - 1 && front != 0) {  
        rear = 0;
    } else {
        rear++;
    }

    queue[rear] = element;
    printf("Inserted %d in the queue.\n", element);
}


void CDELQUE() {
    if (front == -1) {
        printf("Queue is empty. Deletion not possible.\n");
        return;
    }

    int element = queue[front];
    printf("Deleted element: %d\n", element);

    if (front == rear) {  
        front = rear = -1;
    } else if (front == MAX - 1) { 
        front = 0;
    } else {
        front++;
    }
}


void CDISPLAY() {
    if (front == -1) {
        printf("Queue is empty.\n");
        return;
    }

    printf("Elements in the circular queue: ");
    
    if (rear >= front) {
        for (int i = front; i <= rear; i++) {
            printf("%d ", queue[i]);
        }
    } else {
        for (int i = front; i < MAX; i++) {
            printf("%d ", queue[i]);
        }
        for (int i = 0; i <= rear; i++) {
            printf("%d ", queue[i]);
        }
    }
    printf("\n");
}


int main() {
    int choice;

    do {
        printf("\nCircular Queue Operations Menu:\n");
        printf("1. Insert an element in the Circular QUEUE\n");
        printf("2. Delete an element from the Circular QUEUE\n");
        printf("3. Display elements of the Circular QUEUE\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                CENQUE();
                break;
            case 2:
                CDELQUE();
                break;
            case 3:
                CDISPLAY();
                break;
            case 4:
                printf("Exiting the program.\n");
                break;
            default:
                printf("Invalid choice! Please try again.\n");
        }
    } while (choice != 4);

    return 0;
}
