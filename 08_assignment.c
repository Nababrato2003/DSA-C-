#include <stdio.h>
#include <stdlib.h>
struct Node {
    int coefficient;
    int exponent;
    struct Node* next;
};
struct Node* createNode(int coeff, int exp) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->coefficient = coeff;
    newNode->exponent = exp;
    newNode->next = NULL;
    return newNode;
}
void insertNode(struct Node** poly, int coeff, int exp) {
    struct Node* newNode = createNode(coeff, exp);
    if (*poly == NULL) {
        *poly = newNode;
    } else {
        struct Node* temp = *poly;
        while (temp->next != NULL) {
            temp = temp->next;
        }
        temp->next = newNode;
    }
}
void displayPoly(struct Node* poly) {
    while (poly != NULL) {
        printf("%dx^%d", poly->coefficient, poly->exponent);
        poly = poly->next;
        if (poly != NULL) {
            printf(" + ");
        }
    }
    printf("\n");
}
struct Node* addPolynomials(struct Node* poly1, struct Node* poly2) {
    struct Node* result = NULL;
    while (poly1 != NULL && poly2 != NULL) {
        if (poly1->exponent > poly2->exponent) {
            insertNode(&result, poly1->coefficient, poly1->exponent);
            poly1 = poly1->next;
        } else if (poly1->exponent < poly2->exponent) {
            insertNode(&result, poly2->coefficient, poly2->exponent);
            poly2 = poly2->next;
        } else {
            int sumCoeff = poly1->coefficient + poly2->coefficient;
            if (sumCoeff != 0) { 
                insertNode(&result, sumCoeff, poly1->exponent);
            }
            poly1 = poly1->next;
            poly2 = poly2->next;
        }
    }
    while (poly1 != NULL) {
        insertNode(&result, poly1->coefficient, poly1->exponent);
        poly1 = poly1->next;
    }
    while (poly2 != NULL) {
        insertNode(&result, poly2->coefficient, poly2->exponent);
        poly2 = poly2->next;
    }

    return result;
}
void inputPolynomial(struct Node** poly) {
    int n, coeff, exp;
    printf("Enter the number of terms in the polynomial: ");
    scanf("%d", &n);

    for (int i = 0; i < n; i++) {
        printf("Enter coefficient and exponent for term %d: ", i + 1);
        scanf("%d %d", &coeff, &exp);
        insertNode(poly, coeff, exp);
    }
}
int main() {
    struct Node* poly1 = NULL;
    struct Node* poly2 = NULL;
    struct Node* sum = NULL;
    printf("Input the first polynomial:\n");
    inputPolynomial(&poly1);
    printf("Input the second polynomial:\n");
    inputPolynomial(&poly2);
    printf("First Polynomial: ");
    displayPoly(poly1);
    printf("Second Polynomial: ");
    displayPoly(poly2);
    sum = addPolynomials(poly1, poly2);
    printf("Sum of the Polynomials: ");
    displayPoly(sum);
    return 0;
}