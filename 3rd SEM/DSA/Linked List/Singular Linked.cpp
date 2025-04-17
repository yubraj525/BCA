#include <stdio.h>
#include <stdlib.h>
#define TRUE 1

struct node {
    int data;
    struct node *next;
};

struct node *header = NULL;

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
    ptr->next = header;
    header = ptr;
    printf("Node inserted at front.\n");
}

void InsertAtEnd() {
    int data;
    printf("Enter data: ");
    scanf("%d", &data);
    struct node *ptr = getNode(data);
    if (header == NULL) {
        header = ptr;
    } else {
        struct node *temp = header;
        while (temp->next != NULL) temp = temp->next;
        temp->next = ptr;
    }
    printf("Node inserted at end.\n");
}

void InsertBefore() {
    int key, data;
    printf("Enter key before which to insert: ");
    scanf("%d", &key);
    struct node *prev = NULL, *curr = header;
    while (curr != NULL && curr->data != key) {
        prev = curr;
        curr = curr->next;
    }
    if (curr == NULL) {
        printf("Key %d not found.\n", key);
        return;
    }
    printf("Enter data: ");
    scanf("%d", &data);
    struct node *ptr = getNode(data);
    ptr->next = curr;
    if (prev == NULL)
        header = ptr;
    else
        prev->next = ptr;
    printf("%d inserted before %d.\n", data, key);
}

void InsertAfter() {
    int key, data;
    printf("Enter key after which to insert: ");
    scanf("%d", &key);
    struct node *curr = header;
    while (curr != NULL && curr->data != key) curr = curr->next;
    if (curr == NULL) {
        printf("Key %d not found.\n", key);
        return;
    }
    printf("Enter data: ");
    scanf("%d", &data);
    struct node *ptr = getNode(data);
    ptr->next = curr->next;
    curr->next = ptr;
    printf("%d inserted after %d.\n", data, key);
}

void RemoveFromFront() {
    if (header == NULL) {
        printf("List is empty.\n");
        return;
    }
    struct node *ptr = header;
    header = header->next;
    free(ptr);
    printf("Node removed from front.\n");
}

void RemoveFromEnd() {
    if (header == NULL) {
        printf("List is empty.\n");
        return;
    }
    struct node *curr = header, *prev = NULL;
    while (curr->next != NULL) {
        prev = curr;
        curr = curr->next;
    }
    if (prev == NULL)
        header = NULL;
    else
        prev->next = NULL;
    free(curr);
    printf("Last node removed.\n");
}

void RemoveAny() {
    if (header == NULL) {
        printf("List is empty.\n");
        return;
    }
    int key;
    printf("Enter value to remove: ");
    scanf("%d", &key);
    struct node *curr = header, *prev = NULL;
    while (curr != NULL && curr->data != key) {
        prev = curr;
        curr = curr->next;
    }
    if (curr == NULL) {
        printf("Key %d not found.\n", key);
        return;
    }
    if (prev == NULL)
        header = header->next;
    else
        prev->next = curr->next;
    free(curr);
    printf("Node with value %d removed.\n", key);
}

void Display() {
    if (header == NULL) {
        printf("List is empty.\n");
        return;
    }
    printf("List: ");
    struct node *ptr = header;
    while (ptr != NULL) {
        printf("%d ", ptr->data);
        ptr = ptr->next;
    }
    printf("\n");
}

int main() {
    int choice;
    while (TRUE) {
        printf("\nLinked List Operations:\n");
        printf("1. Insert at Front\n");
        printf("2. Insert at End\n");
        printf("3. Insert Before\n");
        printf("4. Insert After\n");
        printf("5. Remove from Front\n");
        printf("6. Remove from End\n");
        printf("7. Remove Any\n");
        printf("8. Display List\n");
        printf("9. Exit\n");
        printf("Enter choice: ");
        scanf("%d", &choice);
        switch (choice) {
            case 1: InsertAtFront(); break;
            case 2: InsertAtEnd(); break;
            case 3: InsertBefore(); break;
            case 4: InsertAfter(); break;
            case 5: RemoveFromFront(); break;
            case 6: RemoveFromEnd(); break;
            case 7: RemoveAny(); break;
            case 8: Display(); break;
            case 9: exit(0);
            default: printf("Invalid choice.\n");
        }
    }
    return 0;
}

