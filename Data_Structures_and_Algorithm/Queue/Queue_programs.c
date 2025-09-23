// Queue implementation in C (using arrays)
// Author: Het Hiteshkumar Thakkar
// Roll No: 24BIT218D

#include <stdio.h>
#include <stdlib.h>

// Defining size of array as a constant
#define SIZE 8  

// Structure definition of queue
struct queue {      
    int arr[SIZE];  // Array to hold elements
    int front, rear; // Front and rear pointers
};

// Function to initialize queue
// Sets both front and rear to 0 (indicating empty queue)
void initqueue(struct queue *q) {
    q->front = q->rear = 0;
}

// Function to check whether queue is full
// Queue is full when rear pointer reaches SIZE
int isfull(struct queue *q) {
    return q->rear >= SIZE;
}

// Function to check whether queue is empty
// Queue is empty when front pointer is 0
int isempty(struct queue *q) {
    return q->front <= 0;
}

// Function to insert value in queue (Enqueue)
int qinsert(struct queue *q, int value) {
    // If queue is full → Overflow
    if (isfull(q)) {
        printf("Queue Overflows!\n");
    }
    else {
        // Increment rear and store value
        q->rear += 1;  
        q->arr[q->rear] = value;  

        // If inserting the first element, move front to 1
        if (q->front == 0) {
            q->front += 1;
        }

        printf("%d inserted successfully\n", value);
    }
}

// Function to delete an element from queue (Dequeue)
int qdelete(struct queue *q) {   
    // If queue is empty → Underflow
    if (isempty(q)) {
        printf("Queue is empty\n");
        return -1;
    } 
    else {
        int y;  
        y = q->arr[q->front];  // Store element at front

        // If last element is deleted → Reset queue
        if (q->front == q->rear) {
            q->front = q->rear = 0;
        } 
        else {
            // Otherwise, move front pointer ahead
            q->front += 1;
        }

        return y;
    }
}

// Function to display queue elements
// Traverses from front → rear
void qdisplay(struct queue *q) {
    if (isempty(q)) {
        printf("Queue is empty\n");
    } 
    else {
        printf("Queue elements (front → rear): ");
        for (int i = q->front; i <= q->rear; i++) {
            printf("%d ", q->arr[i]);
        }
        printf("\n");
    }
}

// Driver function (menu-driven program)
int main() {
    struct queue q;
    initqueue(&q);  // Initialize queue

    printf("Name: Het Hiteshkumar Thakkar\nRoll No: 24BIT218D\n");

    int choice, value, deleted;
    while (1) {
        printf("\nQueue Operations:\n");
        printf("1. Insert (Enqueue)\n");
        printf("2. Delete (Dequeue)\n");
        printf("3. Display Queue\n");
        printf("4. Exit\n");
        printf("Enter choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("\nEnter value to insert: ");
                scanf("%d", &value);
                qinsert(&q, value);
                break;
            
            case 2:
                deleted = qdelete(&q);
                if (deleted != -1) {
                    printf("\n%d deleted successfully\n", deleted);
                }
                break;

            case 3:
                qdisplay(&q);
                break;

            case 4:
                exit(0);

            default:
                printf("\nEnter valid choice between 1-4\n");
                break;
        }
    }
    return 0;
}
