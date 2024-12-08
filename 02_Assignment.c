/*Write a Menu Driven C Program to implement Stack operations using array:
a) Insert an element in the STACK: void PUSH( int ) 
b) Delete an element from the STACK: int POP()
c) Display all elements of the STACK: void DISPLAY().
Write the code in such a way that it can produce output according to user choice.
Ex: push(31), push(71), push(91), display(), pop(), display()….*/
#include <stdio.h>
#include <stdlib.h>

#define MAX 100  // Maximum size of the stack 

int stack[MAX];
int top = -1;  // Initialize top of the stack

// Function to check if the stack is full
int isFull() {
    return top == MAX - 1;
}

// Function to check if the stack is empty
int isEmpty() {
    return top == -1;
}

// Function to push an element onto the stack
void PUSH(int value) {
    if (isFull()) {
        printf("Stack Overflow!\n");
    } else {
        stack[++top] = value;
        printf("Inserted %d\n", value);
    }
}

// Function to pop an element from the stack
int POP() {
    if (isEmpty()) {
        printf("Stack Underflow!\n");
        return -1;  // Return a sentinel value to indicate an error
    } else {
        return stack[top--];
    }
}

// Function to display all elements of the stack
void DISPLAY() {
    if (isEmpty()) {
        printf("Stack is Empty!\n");
    } else {
        printf("Stack elements are:\n");
        for (int i = top; i >= 0; i--) {
            printf("%d\n", stack[i]);
        }
    }
}

int main() {
    int choice, value;
    while (2) {
        // Display menu
        printf("\nMenu:\n");
        printf("1. Push\n");
        printf("2. Pop\n");
        printf("3. Display\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter value to push: ");
                scanf("%d", &value);
                PUSH(value);
                break;
            case 2:
                value = POP();
                if (value != -1) {  // Check if POP operation was successful
                    printf("Popped %d\n", value);
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
