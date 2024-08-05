#include <stdio.h>
#include <stdlib.h>

struct Node {
    int digit;
    struct Node* next;
};

typedef struct Node node;

node* createNode(int digit) {
    node* newNode = (node*)malloc(sizeof(node));
    newNode->digit = digit;
    newNode->next = NULL;
    return newNode;
}

void insertAtEnd(node** headRef, int digit) {
    node* newNode = createNode(digit);
    if (*headRef == NULL) {
        *headRef = newNode;
        return;
    }
    node* temp = *headRef;
    while (temp->next != NULL) {
        temp = temp->next;
    }
    temp->next = newNode;
}

void printList(node* head) {
    while (head != NULL) {
        printf("%d", head->digit);
        head = head->next;
    }
    printf("\n");
}

node* addLists(node* list1, node* list2) {
    node* result = NULL;
    node* temp = NULL;
    int carry = 0, sum = 0;
    while (list1 != NULL || list2 != NULL) {
        sum = carry + (list1 ? list1->digit : 0) + (list2 ? list2->digit : 0);
        carry = (sum >= 10) ? 1 : 0;
        sum = sum % 10;
        temp = createNode(sum);
        if (result == NULL) {
            result = temp;
        } else {
            node* tail = result;
            while (tail->next != NULL) {
                tail = tail->next;
            }
            tail->next = temp;
        }
        if (list1) list1 = list1->next;
        if (list2) list2 = list2->next;
    }
    if (carry > 0) {
        temp = createNode(carry);
        node* tail = result;
        while (tail->next != NULL) {
            tail = tail->next;
        }
        tail->next = temp;
    }
    return result;
}

node* subtractLists(node* list1, node* list2) {
    node* result = NULL;
    node* temp = NULL;
    int borrow = 0, diff = 0;
    while (list1 != NULL || list2 != NULL) {
        diff = borrow + (list1 ? list1->digit : 0) - (list2 ? list2->digit : 0);
        borrow = (diff < 0) ? -1 : 0;
        diff = (diff < 0) ? diff + 10 : diff;
        temp = createNode(diff);
        if (result == NULL) {
            result = temp;
        } else {
            node* tail = result;
            while (tail->next != NULL) {
                tail = tail->next;
            }
            tail->next = temp;
        }
        if (list1) list1 = list1->next;
        if (list2) list2 = list2->next;
    }
    return result;
}
int main() {
    node* list1 = NULL;
    node* list2 = NULL;
    char num1[11], num2[11];
    printf("Enter the first number (up to 10 digits): ");
    scanf("%s", num1);
    printf("Enter the second number (up to 10 digits): ");
    scanf("%s", num2);

    // Add each digit to linked list 1
    for (int i = 0; num1[i] != '\0'; i++) {
        int digit = num1[i] - '0';
        insertAtEnd(&list1, digit);
    }

    // Add each digit to linked list 2
    for (int i = 0; num2[i] != '\0'; i++) {
        int digit = num2[i] - '0';
        insertAtEnd(&list2, digit);
    }

    // Print the linked lists
    printf("\nList 1: ");
    printList(list1);
    printf("List 2: ");
    printList(list2);

    // Add the two linked lists
    node* sum = addLists(list1, list2);
    printf("Sum: ");
    printList(sum);

    // Subtract the two linked lists
    node* diff = subtractLists(list1, list2);
    printf("Difference: ");
    printList(diff);

    return 0;
}
