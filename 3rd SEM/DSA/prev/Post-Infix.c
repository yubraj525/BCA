#include <stdio.h>
#include <string.h>
#include <ctype.h>

#define MAX 100

// Define a stack to store strings
typedef struct {
    char arr[MAX][MAX];  // Stack of strings
    int tos;  // Top of stack index
} stack;

// Push a full string onto the stack
void push(stack *s, char *str) {
    if (s->tos < MAX - 1) {
        strcpy(s->arr[++s->tos], str);  // Copy string into stack
    }
}

// Pop a string from the stack
char* pop(stack *s) {
    if (s->tos >= 0) {
        return s->arr[s->tos--];  // Return the popped string
    }
    return "";  // Return empty string if stack is empty
}

int main() {
    stack s;
    char exp[MAX], temp[MAX];

    s.tos = -1;
    int i;
    printf("Enter a postfix expression: ");
    fgets(exp, MAX, stdin);  // Read postfix expression
    

    for ( i = 0; exp[i] != '\0'; i++) {
        if (isalnum(exp[i])) {  // If operand, push it as a string
            char operand[2] = {exp[i], '\0'}; // Convert char to string
            push(&s, operand);
        } else {  // If operator, pop two operands and form infix
            char second[MAX], first[MAX];

            strcpy(first, pop(&s)); // Pop second operand
            strcpy(second, pop(&s));  // Pop first operand

            // Create a new infix expression: "(first operator second)"
            snprintf(temp, MAX, "(%s%c%s)", second, exp[i], first);
            
            push(&s, temp);  // Push the new expression back
        }
    }
printf("Infix Expression: \n");
    printf("%s", pop(&s));  // Final result

    return 0;
}

