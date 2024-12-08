/*Write a Menu Driven C Program to implement QUEUE operations using array:
a) Insert an element in the QUEUE: ENQUE(char)
b) Delete an element from the QUEUE: char DELQUE()
c) Display all the elements of the QUEUE: DISPLAY()
Write the code in such a way that it can produce output according to user choice:
Ex: enque(a), enque(b), enque(p), display(), delque(), display()…*/

#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>  // Include this header for isalpha() function

#define MAX 100  // Maximum size of the queue

char queue[MAX];
int front = -1;  // Index of the front element
int rear = -1;   // Index of the rear element

// Function to check if the queue is full
int isFull() {
    return (rear == MAX - 1);
}

// Function to check if the queue is empty
int isEmpty() {
    return (front == -1 || front > rear);
}

// Function to insert an element into the queue
int ENQUE(char value) {
    if (isFull()) {
        printf("Queue Overflow!\n");
    } else {
        if (!isalpha(value)) {  // Check if the input is not an alphabetic character
            printf("Only alphabetic characters are allowed!\n");
            return 0;
        }
        if (isEmpty()) {
            front = 0;  // Initialize front if the queue is empty
        }
        queue[++rear] = value;
        printf("Inserted %c\n", value);
   }
   return 0;
}

// Function to delete an element from the queue
char DELQUE() {
    if (isEmpty()) {
        printf("Queue Underflow!\n");
        return '\0';  // Return a null character to indicate an error
    } else {
        return queue[front++];
    }
}

// Function to display all elements of the queue
int DISPLAY() {
    int i;
    if (isEmpty()) {
        printf("Queue is Empty!\n");
    } else {
        printf("Queue elements are:\n");
        for (i = front; i <= rear; i++) {
            printf("%c\n", queue[i]);
        }
    }
    return 0;
}

int main() {
    int choice;
    char value;

    while (1) {  // Infinite loop to keep the menu running
        // Display menu
        printf("\nMenu:\n");
        printf("1. Enqueue\n");
        printf("2. Dequeue\n");
        printf("3. Display\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter value to enqueue: ");
                scanf(" %c", &value);  // Space before %c to skip whitespace
                ENQUE(value);
                break;
            case 2:
                value = DELQUE();
                if (value != '\0') {  // Check if DELQUE operation was successful
                    printf("Dequeued %c\n", value);
                }
                break;
            case 3:
                DISPLAY();
                break;
            case 4:
                exit(0);  // Exit the program
            default:
                printf("Invalid choice! Please enter a number between 1 and 4.\n");
        }
    }

    return 0;
}