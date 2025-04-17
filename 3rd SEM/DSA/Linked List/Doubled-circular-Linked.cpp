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
    ptr->prev = ptr->next = NULL;
    return ptr;
}

void InsertAtFront() {
    int data;
    printf("Enter data: ");
    scanf("%d", &data);
    struct node *ptr = getNode(data);

    if (head == NULL) {
        ptr->next = ptr->prev = ptr;
        head = ptr;
    } else {
        struct node *last = head->prev;
        ptr->next = head;
        ptr->prev = last;
        last->next = ptr;
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
        ptr->next = ptr->prev = ptr;
        head = ptr;
    } else {
        struct node *last = head->prev;
        last->next = ptr;
        ptr->prev = last;
        ptr->next = head;
        head->prev = ptr;
    }
    printf("Node inserted at end.\n");
}

void RemoveFromFront() {
    if (head == NULL) {
        printf("List is empty.\n");
        return;
    }

    struct node *temp = head;
    if (head->next == head) {
        head = NULL;
    } else {
        struct node *last = head->prev;
        head = head->next;
        head->prev = last;
        last->next = head;
    }
    free(temp);
    printf("Node removed from front.\n");
}

void RemoveFromEnd() {
    if (head == NULL) {
        printf("List is empty.\n");
        return;
    }

    struct node *last = head->prev;
    if (last == head) {
        head = NULL;
    } else {
        struct node *secondLast = last->prev;
        secondLast->next = head;
        head->prev = secondLast;
    }
    free(last);
    printf("Node removed from end.\n");
}

void DisplayForward() {
    if (head == NULL) {
        printf("List is empty.\n");
        return;
    }
    struct node *temp = head;
    printf("List (forward): ");
    do {
        printf("%d ", temp->data);
        temp = temp->next;
    } while (temp != head);
    printf("\n");
}

void DisplayBackward() {
    if (head == NULL) {
        printf("List is empty.\n");
        return;
    }
    struct node *last = head->prev;
    struct node *temp = last;
    printf("List (backward): ");
    do {
        printf("%d ", temp->data);
        temp = temp->prev;
    } while (temp != last);
    printf("\n");
}

int main() {
    int choice;
    while (TRUE) {
        printf("\nDoubly Circular Linked List Menu:\n");
        printf("1. Insert at Front\n");
        printf("2. Insert at End\n");
        printf("3. Remove from Front\n");
        printf("4. Remove from End\n");
        printf("5. Display Forward\n");
        printf("6. Display Backward\n");
        printf("7. Exit\n");
        printf("Enter your choice: ");
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

