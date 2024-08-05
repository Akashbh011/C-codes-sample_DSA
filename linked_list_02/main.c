#include <stdio.h>
#include <stdlib.h>

#include <stdio.h>
#include <stdlib.h>

// Node structure
struct Node {
    int coefficient;
    int exponent;
    struct Node* next;
};

// Function to add two polynomials
struct Node* addPolynomials(struct Node* poly1, struct Node* poly2) {
    struct Node* result = NULL;
    struct Node* current = NULL;

    while (poly1 && poly2) {
        struct Node* new_node = (struct Node*)malloc(sizeof(struct Node));
        new_node->next = NULL;
        if (result == NULL) {
            result = new_node;
            current = result;
        }
        else {
            current->next = new_node;
            current = current->next;
        }
        if (poly1->exponent > poly2->exponent) {
            new_node->coefficient = poly1->coefficient;
            new_node->exponent = poly1->exponent;
            poly1 = poly1->next;
        }
        else if (poly1->exponent < poly2->exponent) {
            new_node->coefficient = poly2->coefficient;
            new_node->exponent = poly2->exponent;
            poly2 = poly2->next;
        }
        else {
            new_node->coefficient = poly1->coefficient + poly2->coefficient;
            new_node->exponent = poly1->exponent;
            poly1 = poly1->next;
            poly2 = poly2->next;
        }
    }

    while (poly1) {
        struct Node* new_node = (struct Node*)malloc(sizeof(struct Node));
        new_node->coefficient = poly1->coefficient;
        new_node->exponent = poly1->exponent;
        new_node->next = NULL;
        current->next = new_node;
        current = current->next;
        poly1 = poly1->next;
    }

    while (poly2) {
        struct Node* new_node = (struct Node*)malloc(sizeof(struct Node));
        new_node->coefficient = poly2->coefficient;
        new_node->exponent = poly2->exponent;
        new_node->next = NULL;
        current->next = new_node;
        current = current->next;
        poly2 = poly2->next;
    }

    return result;
}

// Function to print a polynomial
void printPolynomial(struct Node* poly) {
    while (poly != NULL) {
        printf("%dx^%d ", poly->coefficient, poly->exponent);
        poly = poly->next;
    }
    printf("\n");
}

int main() {
    struct Node* poly1 = NULL;
    struct Node* poly2 = NULL;
    struct Node* result = NULL;

    // First polynomial
    struct Node* node1 = (struct Node*)malloc(sizeof(struct Node));
    node1->coefficient = 5;
    node1->exponent = 2;
    node1->next = NULL;
    poly1 = node1;

    struct Node* node2 = (struct Node*)malloc(sizeof(struct Node));
    node2->coefficient = 4;
    node2->exponent = 1;
    node2->next = NULL;
    node1->next = node2;

    struct Node* node3 = (struct Node*)malloc(sizeof(struct Node));
    node3->coefficient = 2;
    node3->exponent = 0;
    node3->next = NULL;
    node2->next = node3;

    // Second polynomial
    struct Node* node4 = (struct Node*)malloc(sizeof(struct Node));
    node4->coefficient = 3;
    node4->exponent = 1;
    node4->next = NULL;
    poly2 = node4;

    struct Node* node5 = (struct Node*)malloc(sizeof(struct Node));
    node5->coefficient = 2;
    node5->exponent = 0;
    node5->next = NULL;
    node4->next = node5;

    printf("First polynomial: ");
    printPolynomial(poly1);

    printf("Second polynomial: ");
    printPolynomial(poly2);

    result = addPolynomials(poly1, poly2);

    printf("Sum of the polynomials: ");
    printPolynomial(result);

    return 0;
}
