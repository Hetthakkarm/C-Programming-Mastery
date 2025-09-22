//C program to implement stack and their operations like push,pop,peek,isfulland isempty using structure

#include <stdio.h>
#include <stdlib.h>

#define MAX 5   // Maximum size of the stack

// Structure definition for Stack
struct stack {
    int arr[MAX];   // Array to store stack elements
    int top;        // Index of the top element
};

// Function to initialize the stack
int initstack(struct stack *s) {
    return s->top = -1;  // Set top = -1 (stack is empty)
}

// Function to check if the stack is full
int isfull(struct stack *s) {
    return s->top == MAX - 1;
}

// Function to check if the stack is empty
int isempty(struct stack *s) {
    return s->top == -1;
}

// Function to push an element into the stack
void push(struct stack *s, int value) {
    if (isfull(s)) {
        printf("Stack Overflow! Cannot insert %d\n", value);
    } else {
        s->top += 1;             // Increase top index
        s->arr[s->top] = value;  // Insert value
        printf("%d pushed into stack\n", value);
    }
}

// Function to pop an element from the stack
int pop(struct stack *s) {
    if (isempty(s)) {
        printf("Stack Underflow! Cannot pop.\n");
        return -1;  // Indicate error
    } else {
        return s->arr[(s->top)--];  // Return top element and decrease top
    }
}

// Function to return the top element (without removing it)
int top(struct stack *s) {
    if (isempty(s)) {
        printf("Stack is empty! No top element.\n");
        return -1;
    }
    return s->arr[s->top];
}

// Function to display stack elements
void display(struct stack *s) {
    if (isempty(s)) {
        printf("Stack is empty\n");
    } else {
        printf("Stack (top to bottom): ");
        for (int i = s->top; i >= 0; i--) {
            printf("%d ", s->arr[i]);
        }
        printf("\n");
    }
}

// Main function (menu-driven program)
int main() {
    struct stack s;   // Declare stack
    initstack(&s);    // Initialize stack

    int choice, value;

    while (1) {
        printf("\n===== Stack Operations =====\n");
        printf("1. Push\n2. Pop\n3. Peek (Top)\n4. Display\n5. Exit\n");
        printf("Enter choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1: // Push
                printf("Enter value to push: ");
                scanf("%d", &value);
                push(&s, value);
                break;

            case 2: // Pop
                value = pop(&s);
                if (value != -1) {  // Check if pop was successful
                    printf("%d popped from stack\n", value);
                }
                break;

            case 3: // Peek (Top element)
                value = top(&s);
                if (value != -1) {
                    printf("Top element is %d\n", value);
                }
                break;

            case 4: // Display stack
                display(&s);
                break;

            case 5: // Exit program
                printf("Exiting...\n");
                exit(0);

            default:
                printf("Invalid choice! Please enter between 1-5.\n");
                break;
        }
    }

    return 0;
}
