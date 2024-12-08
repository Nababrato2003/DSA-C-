#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#define MAX 100
char stack[MAX]; 
int top = -1;     
void push(char x) {
    if (top == MAX - 1) {
        printf("Stack overflow\n");
    } else {
        stack[++top] = x;
    }
}
char pop() {
    if (top == -1) {
        printf("Stack underflow\n");
        return -1;
    } else {
        return stack[top--];
    }
}
int precedence(char x) {
    if (x == '(') {
        return 0;
    }
    if (x == '+' || x == '-') {
        return 1;
    }
    if (x == '*' || x == '/') {
        return 2;
    }
    return 0;
}
void infixToPostfix(char *infix) {
    char *postfix = (char *)malloc((strlen(infix) + 1) * sizeof(char)); 
    int i = 0, j = 0;  

    while (infix[i] != '\0') {
        char current = infix[i];
        if (isalnum(current)) {
            postfix[j++] = current;
        } 
        else if (current == '(') {
            push(current);
        } 
        else if (current == ')') {
            while (stack[top] != '(') {
                postfix[j++] = pop();
            }
            pop();  
        }
        else {
            while (top != -1 && precedence(stack[top]) >= precedence(current)) {
                postfix[j++] = pop();
            }
            push(current);
        }
        i++;
    }
    while (top != -1)
    {
    	postfix[j++]=pop();
    }
    postfix[j] = '\0';  
    printf("Postfix Expression: %s\n", postfix);
    free(postfix);  
}
int main() {
    char infix[MAX];   
    printf("Enter infix expression: ");
    scanf("%s", infix);
    infixToPostfix(infix);
    return 0;
}