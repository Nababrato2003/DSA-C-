#include <stdio.h>
#include <conio.h>
#include <ctype.h>
#define MAX 100

float st[MAX];
int top = -1;

void push(float st[], float val);
float pop(float st[]);
float evaluatePostfixExp(char exp[]);

int main() {
    float val;
    char exp[100];
    printf("\nEnter any postfix expression: ");
    gets(exp);
    val = evaluatePostfixExp(exp);
    printf("\nValue of the postfix expression = %.2f", val);
    getch();
    return 0;
}

float evaluatePostfixExp(char exp[]) {
    int i = 0;
    float op1, op2, value;
    
    while (exp[i] != '\0') {
        if (isspace(exp[i])) {
            // Skip spaces
            i++;
            continue;
        }
        
        if (isdigit(exp[i])) {
            push(st, (float)(exp[i] - '0'));  // Convert char to float and push
        } else {
            op2 = pop(st);
            op1 = pop(st);
            
            switch (exp[i]) {
                case '+':
                    value = op1 + op2;
                    break;
                case '-':
                    value = op1 - op2;
                    break;  // Fixing subtraction
                case '/':
                    value = op1 / op2;
                    break;
                case '*':
                    value = op1 * op2;
                    break;
                case '%':
                    value = (int)op1 % (int)op2;
                    break;
            }
            push(st, value);
        }
        i++;
    }
    return pop(st);
}

void push(float st[], float val) {
    if (top == MAX - 1) {
        printf("\nSTACK OVERFLOW");
    } else {
        top++;
        st[top] = val;
    }
}

float pop(float st[]) {
    if (top == -1) {
        printf("\nSTACK UNDERFLOW");
        return -1;
    } else {
        float val = st[top];
        top--;
        return val;
    }
}
