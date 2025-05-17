#include <stdio.h>
#include <stdlib.h>

#define MAX 5  // Maximum size of the queue

// Queue structure
typedef struct {
    int arr[MAX];
    int front, rear;
} Queue;

// Function to initialize the queue
void initQueue(Queue *q) {
    q->front = -1;
    q->rear = -1;
}

// Function to check if the queue is empty
int isEmpty(Queue *q) {
    return (q->front == -1);
}

// Function to check if the queue is full
int isFull(Queue *q) {
    return (q->rear == MAX - 1);
}

// Function to insert an element into the queue (Enqueue)
void enqueue(Queue *q, int value) {
    if (isFull(q)) {
        printf("Queue is FULL! Cannot insert %d\n", value);
        return;
    }
    if (q->front == -1) q->front = 0;  // Set front if inserting the first element
    q->arr[++q->rear] = value;
    printf("%d inserted into queue.\n", value);
}

// Function to remove an element from the queue (Dequeue)
void dequeue(Queue *q) {
    if (isEmpty(q)) {
        printf("Queue is EMPTY! Cannot dequeue.\n");
        return;
    }
    printf("%d removed from queue.\n", q->arr[q->front]);
    if (q->front == q->rear) {  // Reset queue when last element is removed
        q->front = -1;
        q->rear = -1;
    } else {
        q->front++;
    }
}

// Function to display the queue elements
void display(Queue *q) {
    if (isEmpty(q)) {
        printf("Queue is EMPTY!\n");
        return;
    }
    printf("The  elements of queue: ");
    for (int i = q->front; i <= q->rear; i++) {
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
    printf("Front element: %d\n", q->arr[q->front]);
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
    
        printf("4. Exit\n");
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

