#include <stdio.h>
#include <string.h>

#define MAX 100 //just defining stack size

char stack[MAX];
int top = -1;

void push(char c) {
    stack[++top] = c;
}

char pop() {
    if (top == -1) return '\0';
    return stack[top--];
}

// Check matching pair,,
int isMatchingPair(char open, char close) {
    return (open == '(' && close == ')') || (open == '{' && close == '}') || (open == '[' && close == ']');
}

// loop to check balanced parentheses,
int isBalanced(char expr[]) {
    for (int i = 0; expr[i] != '\0'; i++) {

        char c = expr[i];

        if (c == '(' || c == '{' || c == '[') {
            push(c);

        } 
        else if (c == ')' || c == '}' || c == ']') {

            char popped = pop();

            if (!isMatchingPair(popped, c)) {

                return 0; // Not matching.
            }
        }
    }

    return top == -1; // Stack should be empty if balanced,
}

int main() {
    char expr[MAX];
    printf("Enter expression: ");
    scanf("%s", expr);

    if (isBalanced(expr))
        printf("Balanced\n");
    else
        printf("Not Balanced\n");

    return 0;
}
