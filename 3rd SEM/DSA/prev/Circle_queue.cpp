#include <stdio.h>
#include<stdlib.h>
#define MAX 5  // Maximum size of queue

typedef struct {
    int queue[MAX];
    int front, rear;
} CircularQueue;

// Function to initialize queue
void initQueue(CircularQueue *q) {
    q->front = q->rear = -1;
}

// Function to check if the queue is empty
int isEmpty(CircularQueue *q) {
    return q->front ==-1;
}

// Function to check if the queue is full
int isFull(CircularQueue *q) {
    return (q->rear + 1) % MAX == q->front;
}

// Function to insert (enqueue) an element
void enqueue(CircularQueue *q, int value) {
    if (isFull(q)) {
        printf("Queue is FULL!\n");
        return;
    }
    
    if (isEmpty(q))  // If queue was empty, set front to 0
        q->front = 0;
    
    q->rear = (q->rear + 1) % MAX;
    q->queue[q->rear] = value;
    printf("Inserted %d\n", value);
}

// Function to remove (dequeue) an element
void dequeue(CircularQueue *q) {
    if (isEmpty(q)) {
        printf("Queue is EMPTY!\n");
        return;
    }
    
    printf("Removed %d\n", q->queue[q->front]);
    
    if (q->front == q->rear) {  // If only one element was left
        q->front = q->rear = -1;  // Reset queue
    } else {
        q->front = (q->front + 1) % MAX;
    }
}

// Function to get the front element
void peek(CircularQueue *q) {
    if (isEmpty(q)) {
        printf("Queue is EMPTY!\n");
        return;
    }
    printf("Front element: %d\n", q->queue[q->front]);
}

// Function to display queue elements
void display(CircularQueue *q) {
	int i;
    if (isEmpty(q)) {
        printf("Queue is EMPTY!\n");
        return;
    }

    printf("Queue elements: ");
   
   for(i=q->front;i!=q->rear;i=((i+1)%MAX)){
   	printf("%d",q->queue[i]);
   }
    printf("\n");
}

// Main function
int main() {
    CircularQueue q;
    initQueue(&q);

    int choice, value;
    
    while (1) {
    
        printf("\nCircular Queue Operations:\n");
        printf("1. Enqueue\n2. Dequeue\n3. Peek\n4. Display\n5. Exit\n");
        printf("Enter choice: ");
        scanf("%d", &choice);
        
        switch (choice) {
            case 1:
                printf("Enter value: ");
                scanf("%d", &value);
                enqueue(&q, value);
                break;
            case 2:
                dequeue(&q);
                break;
            case 3:
                peek(&q);
                break;
            case 4:
                display(&q);
                break;
            case 5:
                return 0;
            default:
                printf("Invalid choice! Try again.\n");
        }
    }
    
    return 0;
}

