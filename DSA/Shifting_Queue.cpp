#include <stdio.h>
#include <stdlib.h>

#define MAX 5  // Maximum size of the queue

// Queue structure
typedef struct {
    int arr[MAX];
    int size;  // Number of elements in queue
} Queue;

// Function to initialize the queue
void initQueue(Queue *q) {
    q->size = 0;  // Initially, the queue is empty
}

// Function to check if the queue is empty
int isEmpty(Queue *q) {
    return (q->size == 0);
}

// Function to check if the queue is full
int isFull(Queue *q) {
    return (q->size == MAX);
}

// Function to insert an element into the queue (Enqueue)
void enqueue(Queue *q, int value) {
    if (isFull(q)) {
        printf("Queue is FULL! Cannot insert %d\n", value);
        return;
    }
    q->arr[q->size] = value;  // Insert at the next available index
    q->size++;
    printf("%d inserted into queue.\n", value);
}

// Function to remove an element from the queue (Dequeue with Shifting)
void dequeue(Queue *q) {
    if (isEmpty(q)) {
        printf("Queue is EMPTY! Cannot dequeue.\n");
        return;
    }
    printf("%d removed from queue.\n", q->arr[0]);

    // Shift all elements one position to the left
    for (int i = 0; i < q->size - 1; i++) {
        q->arr[i] = q->arr[i + 1];
    }
    q->size--;  // Reduce queue size
}

// Function to display the queue elements
void display(Queue *q) {
    if (isEmpty(q)) {
        printf("Queue is EMPTY!\n");
        return;
    }
    printf("Queue elements: ");
    for (int i = 0; i < q->size; i++) {
        printf("%d ", q->arr[i]);
    }
    printf("\n");
}

// Function to display the front element
void peek(Queue *q) {
    if (isEmpty(q)) {
        printf("Queue is EMPTY!\n");
        return;
    }
    printf("Front element: %d\n", q->arr[0]);
}

// Main function
int main() {
    Queue q;
    initQueue(&q);
    int choice, value;

    while (1) {
        // Menu options
        printf("\nQueue Operations Menu:\n");
        printf("1. Enqueue (Insert)\n");
        printf("2. Dequeue (Remove)\n");
        printf("3. Display Queue\n");
        printf("4. Peek (Front Element)\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        // Switch-case to handle user choice
        switch (choice) {
            case 1:
                printf("Enter value to insert: ");
                scanf("%d", &value);
                enqueue(&q, value);
                break;
            case 2:
                dequeue(&q);
                break;
            case 3:
                display(&q);
                break;
            case 4:
                peek(&q);
                break;
            case 5:
                printf("Exiting program...\n");
                exit(0);
            default:
                printf("Invalid choice! Please enter a number between 1-5.\n");
        }
    }
    return 0;
}

