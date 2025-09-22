#include <stdio.h>
#include <stdlib.h>

// Node str
struct Node {
    int data;
    struct Node* next;
};

// Create new node
struct Node* createNode(int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

// Insert at end
void insertEnd(struct Node** head, int data) {
    struct Node* newNode = createNode(data);
    if (*head == NULL) {
        *head = newNode;
        return;
    }
    struct Node* temp = *head;
    while (temp->next != NULL)
        temp = temp->next;
    temp->next = newNode;
}

// Display linked list
void display(struct Node* head) {
    printf("Linked list: ");
    struct Node* temp = head;
    while (temp != NULL) {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

// Reverse linked list
void reverse(struct Node** head) {
    struct Node *prev = NULL, *curr = *head, *next = NULL;
    while (curr != NULL) {
        next = curr->next;
        curr->next = prev;
        prev = curr;
        curr = next;
    }
    *head = prev;
}

int main() {
    struct Node* head = NULL;
    int n, i, val;
    printf("Enter number of nodes: ");
    scanf("%d", &n);
    printf("Enter node values:\n");
    for (i = 0; i < n; i++) {
        scanf("%d", &val);
        insertEnd(&head, val);
    }
    display(head);

    reverse(&head);
    printf("Reversed linked list: ");
    display(head);
    return 0;
}
