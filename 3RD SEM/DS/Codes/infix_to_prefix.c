#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Function to check if a character is an operator
int isOperator(char c) {
    return (c == '^' || c == '*' || c == '/' || c == '+' || c == '-');
}

// Function to return the precedence of an operator based on the map
int getPrecedence(char c) {
    switch (c) {
        case '^':
            return 1;
        case '*':
        case '/':
            return 2;
        case '+':
        case '-':
            return 3;
        default:
            return 4;
    }
}
// Function to convert infix to prefix
void infixToPrefix(char infix[], char prefix[]) {
    int len = strlen(infix);
    char stack[len]; // Stack to hold operators
    int top = -1;    // Stack top pointer
    int outputIndex = 0;
    // Reverse the infix expression
    for (int i = len - 1; i >= 0; i--) {
        if (infix[i] == ')') {
            stack[++top] = infix[i];
        } else if (infix[i] == '(') {
            while (top >= 0 && stack[top] != ')') {
                prefix[outputIndex++] = stack[top--];
            }
            if (top >= 0) {
                top--; // Pop the '('
            }
        } else if (isOperator(infix[i])) {
            while (top >= 0 && getPrecedence(stack[top]) < getPrecedence(infix[i])) {
                prefix[outputIndex++] = stack[top--];
            }
            stack[++top] = infix[i];
        } else {
            // Operand
            prefix[outputIndex++] = infix[i];
        }
    }
    // Pop any remaining operators from the stack
    while (top >= 0) {
        prefix[outputIndex++] = stack[top--];
    }
    // Null-terminate the prefix expression
    prefix[outputIndex] = '\0';

    // Reverse the prefix expression to get the final result
    strrev(prefix);
}

int main() {
    char infix[100], prefix[100];
    printf("Enter an infix expression: ");
    scanf("%s", infix);

    infixToPrefix(infix, prefix);
    printf("Prefix expression: %s\n", prefix);
    return 0;
}
