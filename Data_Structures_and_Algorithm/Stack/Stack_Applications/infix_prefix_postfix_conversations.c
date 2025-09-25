/*
 * Expression Conversion in C
 * - Convert Infix → Postfix
 * - Convert Infix → Prefix
 *
 * Uses stack (array implementation)
 *
 * Example:
 *   Infix   : (A+B)*C
 *   Postfix : AB+C*
 *   Prefix  : *+ABC
 *
 * Author: (Your Name)
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>   // for isalpha, isdigit

#define MAX 100

// ---------------- Stack Implementation ----------------
struct Stack {
    char arr[MAX];
    int top;
};

// Initialize stack
void initStack(struct Stack *s) {
    s->top = -1;
}

// Check empty
int isEmpty(struct Stack *s) {
    return s->top == -1;
}

// Check full
int isFull(struct Stack *s) {
    return s->top == MAX - 1;
}

// Push character
void push(struct Stack *s, char c) {
    if (isFull(s)) {
        printf("Stack Overflow!\n");
        return;
    }
    s->arr[++(s->top)] = c;
}

// Pop character
char pop(struct Stack *s) {
    if (isEmpty(s)) {
        return '\0'; // empty stack
    }
    return s->arr[(s->top)--];
}

// Peek top character
char peek(struct Stack *s) {
    if (isEmpty(s)) return '\0';
    return s->arr[s->top];
}

// ---------------- Utility Functions ----------------
// Precedence of operators
int precedence(char c) {
    switch (c) {
        case '^': return 3;
        case '*':
        case '/': return 2;
        case '+':
        case '-': return 1;
        default : return -1;
    }
}

// Check if character is operator
int isOperator(char c) {
    return (c == '+' || c == '-' || c == '*' || c == '/' || c == '^');
}

// ---------------- Infix to Postfix ----------------
void infixToPostfix(char* infix, char* postfix) {
    struct Stack s;
    initStack(&s);
    int k = 0;  // index for postfix

    for (int i = 0; i < strlen(infix); i++) {
        char c = infix[i];

        // If operand (A, B, 1, 2...) → directly add to output
        if (isalnum(c)) {
            postfix[k++] = c;
        }
        // If opening bracket → push
        else if (c == '(') {
            push(&s, c);
        }
        // If closing bracket → pop until '('
        else if (c == ')') {
            while (!isEmpty(&s) && peek(&s) != '(') {
                postfix[k++] = pop(&s);
            }
            pop(&s); // remove '('
        }
        // If operator
        else if (isOperator(c)) {
            while (!isEmpty(&s) && precedence(peek(&s)) >= precedence(c)) {
                postfix[k++] = pop(&s);
            }
            push(&s, c);
        }
    }

    // Pop remaining operators
    while (!isEmpty(&s)) {
        postfix[k++] = pop(&s);
    }

    postfix[k] = '\0'; // end string
}

// ---------------- Infix to Prefix ----------------
// Method: Reverse infix, swap ( and ), convert to postfix, then reverse result
void reverseString(char* str) {
    int len = strlen(str);
    for (int i = 0; i < len/2; i++) {
        char temp = str[i];
        str[i] = str[len-i-1];
        str[len-i-1] = temp;
    }
}

void swapBrackets(char* str) {
    for (int i = 0; i < strlen(str); i++) {
        if (str[i] == '(') str[i] = ')';
        else if (str[i] == ')') str[i] = '(';
    }
}

void infixToPrefix(char* infix, char* prefix) {
    char revInfix[MAX], revPostfix[MAX];

    strcpy(revInfix, infix);
    reverseString(revInfix);
    swapBrackets(revInfix);

    infixToPostfix(revInfix, revPostfix);

    strcpy(prefix, revPostfix);
    reverseString(prefix);
}

// ---------------- Main ----------------
int main() {
    char infix[MAX], postfix[MAX], prefix[MAX];

    printf("Enter infix expression: ");
    scanf("%s", infix);

    infixToPostfix(infix, postfix);
    infixToPrefix(infix, prefix);

    printf("Infix   : %s\n", infix);
    printf("Postfix : %s\n", postfix);
    printf("Prefix  : %s\n", prefix);

    return 0;
}
