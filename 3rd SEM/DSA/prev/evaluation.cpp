#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <stdlib.h>

#define MAX 100

typedef struct {
    int arr[MAX];
    int tos;
} stack;

// Function to push value onto the stack
void push(stack *s, int value) {
    s->arr[++(s->tos)] = value;
}

// Function to pop value from the stack
int pop(stack *s) {
    return s->arr[(s->tos)--];
}

// Function to evaluate a prefix expression
int evaluatePrefix(char* exp, int* values) {
    stack s;
    s.tos = -1;  // Initialize stack
    int i, operand1, operand2, result;

    // Iterate over the expression from right to left
    for (i = strlen(exp) - 1; i >= 0; i--) {
        if (exp[i] == ' ') continue;  // Skip spaces

        if (isalpha(exp[i])) {  // If the character is an operand (A, B, C, ...)
            push(&s, values[exp[i] - 'A']);  // Push the corresponding value
        } else if (exp[i] == '+' || exp[i] == '-' || exp[i] == '*' || exp[i] == '/') {
            // Pop two operands from the stack
            if (s.tos < 1) {  // Ensure there are at least two operands
                printf("Error: Invalid prefix expression\n");
                return -1;
            }
            operand1 = pop(&s);
            operand2 = pop(&s);

            // Perform the operation
            switch (exp[i]) {
                case '+':
                    result = operand1 + operand2;
                    break;
                case '-':
                    result = operand1 - operand2;
                    break;
                case '*':
                    result = operand1 * operand2;
                    break;
                case '/':
                    if (operand2 == 0) {  // Check for division by zero
                        printf("Error: Division by zero\n");
                        return -1;
                    }
                    result = operand1 / operand2;
                    break;
                default:
                    printf("Error: Invalid operator %c\n", exp[i]);
                    return -1;
            }
            push(&s, result);  // Push the result back onto the stack
        } else {
            printf("Error: Invalid character %c\n", exp[i]);
            return -1;
        }
    }

    // Final result should be the only value in the stack
    if (s.tos != 0) {
        printf("Error: Invalid prefix expression\n");
        return -1;
    }
    
    return pop(&s);
}

int main() {
    char exp[MAX];

    // Enter prefix expression
    printf("Enter a prefix expression: ");
    fgets(exp, MAX, stdin);  // Read the expression
    exp[strcspn(exp, "\n")] = 0;  // Remove newline character if present

    // Define values for operands (A-Z)
    int values[26] = {0};  // Initialize all values to 0
    values['A' - 'A'] = 1;  // A = 1
    values['B' - 'A'] = 2;  // B = 2
    values['C' - 'A'] = 3;  // C = 3

    // Evaluate the prefix expression
    int result = evaluatePrefix(exp, values);

    // Print the result if no errors occurred
    if (result != -1) {
        printf("Result: %d\n", result);
    }

    return 0;
}

