#include <stdio.h>
#include <stdlib.h>

#define MAX 100

typedef struct Stack {
    int data[MAX];
    int top;
} Stack;

void init(Stack *s) {
    s->top = -1;
}

int isEmpty(Stack *s) {
    return s->top == -1;
}

int isFull(Stack *s) {
    return s->top == MAX - 1;
}

void push(Stack *s, int value) {
    if (isFull(s)) {
        printf("Stack Overflow\n");
        return;
    }
    s->data[++s->top] = value;
}

int pop(Stack *s) {
    if (isEmpty(s)) {
        printf("Stack Underflow\n");
        return -1;
    }
    return s->data[s->top--];
}

int peek(Stack *s) {
    if (isEmpty(s)) {
        printf("Stack is empty\n");
        return -1;
    }
    return s->data[s->top];
}

typedef struct Queue {
    Stack stack1, stack2;
} Queue;

void initQueue(Queue *q) {
    init(&q->stack1);
    init(&q->stack2);
}

void enqueue(Queue *q, int value) {
    push(&q->stack1, value);
    printf("%d enqueued\n", value);
}

int dequeue(Queue *q) {
    if (isEmpty(&q->stack2)) {
        while (!isEmpty(&q->stack1)) {
            push(&q->stack2, pop(&q->stack1));
        }
    }
    int value = pop(&q->stack2);
    if (value != -1) {
        printf("%d dequeued\n", value);
    }
    return value;
}

int main() {
    Queue q;
    initQueue(&q);

    int choice, value;

    while (1) {
        printf("\n1. Enqueue\n2. Dequeue\n3. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter value to enqueue: ");
                scanf("%d", &value);
                enqueue(&q, value);
                break;
            case 2:
                dequeue(&q);
                break;
            case 3:
                exit(0);
            default:
                printf("Invalid choice. Try again.\n");
        }
    }

    return 0;
}
