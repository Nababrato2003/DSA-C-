#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

// Node structure definition
struct Node {
    int data;
    struct Node* next;
};

// Function prototypes
void insert_at_beg(struct Node** head, int data);
void insert_at_end(struct Node** head, int data);
void insert_at_pos(struct Node** head, int data, int pos);
void del_from_beg(struct Node** head);
void del_from_end(struct Node** head);
void del_at_pos(struct Node** head, int pos);
void traverse(struct Node* head);
int get_valid_input();  // Function to get valid integer input

// Main function
int main() {
    struct Node* head = NULL;
    int choice, data, pos;

    while(1) {
        printf("\nMenu:\n");
        printf("1. Insert at Beginning\n");
        printf("2. Insert at End\n");
        printf("3. Insert at Position\n");
        printf("4. Delete from Beginning\n");
        printf("5. Delete from End\n");
        printf("6. Delete at Position\n");
        printf("7. Traverse List\n");
        printf("8. Exit\n");
        printf("Enter your choice: ");
        choice = get_valid_input();

        switch(choice) {
            case 1:
                printf("Enter data to insert at beginning: ");
                data = get_valid_input();
                insert_at_beg(&head, data);
                break;
            case 2:
                printf("Enter data to insert at end: ");
                data = get_valid_input();
                insert_at_end(&head, data);
                break;
            case 3:
                printf("Enter data to insert: ");
                data = get_valid_input();
                printf("Enter position to insert: ");
                pos = get_valid_input();
                insert_at_pos(&head, data, pos);
                break;
            case 4:
                del_from_beg(&head);
                break;
            case 5:
                del_from_end(&head);
                break;
            case 6:
                printf("Enter position to delete: ");
                pos = get_valid_input();
                del_at_pos(&head, pos);
                break;
            case 7:
                traverse(head);
                break;
            case 8:
                exit(0);
            default:
                printf("Invalid choice! Please try again.\n");
        }
    }
    return 0;
}

// Function to get valid integer input
int get_valid_input() {
    char input[20];
    int valid = 0;
    int number;

    while (!valid) {
        scanf("%s", input);
        valid = 1;  // Assume the input is valid

        // Check if all characters in input are digits
        for (int i = 0; i < strlen(input); i++) {
            if (!isdigit(input[i])) {
                valid = 0;  // Invalid input
                break;
            }
        }

        if (valid) {
            number = atoi(input);  // Convert string to integer
        } else {
            printf("Invalid input! Please enter a valid number: ");
        }
    }

    return number;
}

// Function to insert node at the beginning
void insert_at_beg(struct Node** head, int data) {
    struct Node* new_node = (struct Node*)malloc(sizeof(struct Node));
    new_node->data = data;
    new_node->next = *head;
    *head = new_node;
}

// Function to insert node at the end
void insert_at_end(struct Node** head, int data) {
    struct Node* new_node = (struct Node*)malloc(sizeof(struct Node));
    struct Node* temp = *head;
    new_node->data = data;
    new_node->next = NULL;
    
    if (*head == NULL) {
        *head = new_node;
        return;
    }
    while (temp->next != NULL) {
        temp = temp->next;
    }
    temp->next = new_node;
}

// Function to insert node at a specific position
void insert_at_pos(struct Node** head, int data, int pos) {
    struct Node* new_node = (struct Node*)malloc(sizeof(struct Node));
    struct Node* temp = *head;
    new_node->data = data;

    if (pos == 1) {
        new_node->next = *head;
        *head = new_node;
        return;
    }

    for (int i = 1; temp != NULL && i < pos - 1; i++) {
        temp = temp->next;
    }

    if (temp == NULL) {
        printf("Position out of bounds!\n");
        return;
    }

    new_node->next = temp->next;
    temp->next = new_node;
}

// Function to delete node from the beginning
void del_from_beg(struct Node** head) {
    if (*head == NULL) {
        printf("List is empty!\n");
        return;
    }
    struct Node* temp = *head;
    *head = (*head)->next;
    free(temp);
}

// Function to delete node from the end
void del_from_end(struct Node** head) {
    if (*head == NULL) {
        printf("List is empty!\n");
        return;
    }

    struct Node* temp = *head;
    if (temp->next == NULL) {
        *head = NULL;
        free(temp);
        return;
    }

    struct Node* prev = NULL;
    while (temp->next != NULL) {
        prev = temp;
        temp = temp->next;
    }
    prev->next = NULL;
    free(temp);
}

// Function to delete node at a specific position
void del_at_pos(struct Node** head, int pos) {
    if (*head == NULL) {
        printf("List is empty!\n");
        return;
    }

    struct Node* temp = *head;

    if (pos == 1) {
        *head = temp->next;
        free(temp);
        return;
    }

    struct Node* prev = NULL;
    for (int i = 1; temp != NULL && i < pos; i++) {
        prev = temp;
        temp = temp->next;
    }

    if (temp == NULL) {
        printf("Position out of bounds!\n");
        return;
    }

    prev->next = temp->next;
    free(temp);
}

// Function to traverse and print the list
void traverse(struct Node* head) {
    if (head == NULL) {
        printf("List is empty!\n");
        return;
    }

    struct Node* temp = head;
    printf("List elements: ");
    while (temp != NULL) {
        printf("%d -> ", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
}
