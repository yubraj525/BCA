#include<stdio.h>
#include <ctype.h>
#include<string.h>

#define MAX 100

typedef struct {
    char arr[MAX][MAX];
    int tos;
} stack;

void push(stack *s, char *c) {
    strcpy(s->arr[++s->tos], c);
}

char* pop(stack *s) {
    return s->arr[s->tos--];
}

int main() {
    stack p;
    char exp[MAX], temp[MAX];

    p.tos = -1;
    int i = 0;

    printf("Enter a prefix expression: ");
    fflush(stdin);
    fgets(exp, MAX, stdin); // Use fgets instead of gets to avoid overflow

    // Process the prefix expression from right to left
    for(i = strlen(exp) - 2; i >= 0; i--) {  // We start from strlen-2 to avoid the newline
        if(isalnum(exp[i])) {  // If the character is an operand
            char operand[2] = {exp[i], '\0'};
            push(&p, operand);
        } else {  // If the character is an operator
            char first[MAX], second[MAX];
            strcpy(first, pop(&p));
            strcpy(second, pop(&p));
            // Form the new expression with parentheses
            snprintf(temp, MAX, ")%s%c%s(", second, exp[i], first);
            push(&p, temp);
        }
    }

    // The last remaining item in the stack is the infix expression
    printf("Infix Expression is: ");
    printf("%s",strrev(pop(&p)));

    return 0;
}

