#include <stdio.h>
#include <stdlib.h>
#define TRUE 1

struct node {
    int data;
    struct node *next;
};

struct node *last = NULL;

struct node* getNode(int data) {
    struct node *ptr = (struct node *)malloc(sizeof(struct node));
    if (ptr == NULL) {
        printf("Memory allocation failed.\n");
        exit(1);
    }
    ptr->data = data;
    ptr->next = NULL;
    return ptr;
}

void InsertAtFront() {
    int data;
    printf("Enter data: ");
    scanf("%d", &data);
    struct node *ptr = getNode(data);
    if (last == NULL) {
        last = ptr;
        ptr->next = ptr;
    } else {
        ptr->next = last->next;
        last->next = ptr;
    }
    printf("Node inserted at front.\n");
}

void InsertAtEnd() {
    int data;
    printf("Enter data: ");
    scanf("%d", &data);
    struct node *ptr = getNode(data);
    if (last == NULL) {
        last = ptr;
        ptr->next = ptr;
    } else {
        ptr->next = last->next;
        last->next = ptr;
        last = ptr;
    }
    printf("Node inserted at end.\n");
}

void RemoveFromFront() {
    if (last == NULL) {
        printf("List is empty.\n");
        return;
    }
    struct node *ptr = last->next;
    if (last == ptr) {
        last = NULL;
    } else {
        last->next = ptr->next;
    }
    free(ptr);
    printf("Node removed from front.\n");
}

void RemoveFromEnd() {
    if (last == NULL) {
        printf("List is empty.\n");
        return;
    }
    struct node *ptr = last->next, *prev = last;
    if (ptr == last) {
        last = NULL;
    } else {
        while (ptr->next != last->next) {
            prev = ptr;
            ptr = ptr->next;
        }
        prev->next = last->next;
        last = prev;
    }
    free(ptr);
    printf("Last node removed.\n");
}

void Display() {
    if (last == NULL) {
        printf("List is empty.\n");
        return;
    }
    struct node *ptr = last->next;
    printf("List: ");
    do {
        printf("%d ", ptr->data);
        ptr = ptr->next;
    } while (ptr != last->next);
    printf("\n");
}

int main() {
    int choice;
    while (TRUE) {
        printf("\nCircular Singly Linked List Menu:\n");
        printf("1. Insert at Front\n");
        printf("2. Insert at End\n");
        printf("3. Remove from Front\n");
        printf("4. Remove from End\n");
        printf("5. Display\n");
        printf("6. Exit\n");
        printf("Enter choice: ");
        scanf("%d", &choice);
        switch (choice) {
            case 1: InsertAtFront(); break;
            case 2: InsertAtEnd(); break;
            case 3: RemoveFromFront(); break;
            case 4: RemoveFromEnd(); break;
            case 5: Display(); break;
            case 6: exit(0);
            default: printf("Invalid choice.\n");
        }
    }
    return 0;
}

