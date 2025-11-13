#include <stdio.h>
#include <stdlib.h>
#define TRUE 1

struct node {
    int data;
    struct node *prev;
    struct node *next;
};

struct node *head = NULL;

struct node* getNode(int data) {
    struct node *ptr = (struct node *)malloc(sizeof(struct node));
    if (ptr == NULL) {
        printf("Memory allocation failed.\n");
        exit(1);
    }
    ptr->data = data;
    ptr->prev = NULL;
    ptr->next = NULL;
    return ptr;
}

void InsertAtFront() {
    int data;
    printf("Enter data: ");
    scanf("%d", &data);
    struct node *ptr = getNode(data);
    if (head == NULL) {
        head = ptr;
    } else {
        ptr->next = head;
        head->prev = ptr;
        head = ptr;
    }
    printf("Node inserted at front.\n");
}

void InsertAtEnd() {
    int data;
    printf("Enter data: ");
    scanf("%d", &data);
    struct node *ptr = getNode(data);
    if (head == NULL) {
        head = ptr;
    } else {
        struct node *temp = head;
        while (temp->next != NULL)
            temp = temp->next;
        temp->next = ptr;
        ptr->prev = temp;
    }
    printf("Node inserted at end.\n");
}

void RemoveFromFront() {
    if (head == NULL) {
        printf("List is empty.\n");
        return;
    }
    struct node *ptr = head;
    head = head->next;
    if (head != NULL)
        head->prev = NULL;
    free(ptr);
    printf("Node removed from front.\n");
}

void RemoveFromEnd() {
    if (head == NULL) {
        printf("List is empty.\n");
        return;
    }
    struct node *temp = head;
    if (temp->next == NULL) {
        head = NULL;
    } else {
        while (temp->next != NULL)
            temp = temp->next;
        temp->prev->next = NULL;
    }
    free(temp);
    printf("Node removed from end.\n");
}

void DisplayForward() {
    struct node *temp = head;
    if (temp == NULL) {
        printf("List is empty.\n");
        return;
    }
    printf("List (forward): ");
    while (temp != NULL) {
        printf("%d ", temp->data);
        if (temp->next == NULL) break;
        temp = temp->next;
    }
    printf("\n");
}

void DisplayBackward() {
    struct node *temp = head;
    if (temp == NULL) {
        printf("List is empty.\n");
        return;
    }
    while (temp->next != NULL)
        temp = temp->next;
    printf("List (backward): ");
    while (temp != NULL) {
        printf("%d ", temp->data);
        temp = temp->prev;
    }
    printf("\n");
}

int main() {
    int choice;
    while (TRUE) {
        printf("\nDoubly Linked List Menu:\n");
        printf("1. Insert at Front\n");
        printf("2. Insert at End\n");
        printf("3. Remove from Front\n");
        printf("4. Remove from End\n");
        printf("5. Display Forward\n");
        printf("6. Display Backward\n");
        printf("7. Exit\n");
        printf("Enter choice: ");
        scanf("%d", &choice);
        switch (choice) {
            case 1: InsertAtFront(); break;
            case 2: InsertAtEnd(); break;
            case 3: RemoveFromFront(); break;
            case 4: RemoveFromEnd(); break;
            case 5: DisplayForward(); break;
            case 6: DisplayBackward(); break;
            case 7: exit(0);
            default: printf("Invalid choice.\n");
        }
    }
    return 0;
}

