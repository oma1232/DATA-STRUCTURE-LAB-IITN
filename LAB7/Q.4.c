#include <stdio.h>
#include <string.h>

#define MAX 100 //stack size

char stack[MAX];
int top = -1;

// Stack functions
void push(char c) {
    stack[++top] = c;
}

char pop() {
    if (top == -1) return '\0';
    return stack[top--];
}

//func to check if a string is a palindrome
int isPalindrome(char str[]) {

    int len = strlen(str);

    // Push all characters onto stack.
    for (int i = 0; i < len; i++) {
        push(str[i]);
    }

    // Compare characters popped from stack with the original string,
    for (int i = 0; i < len; i++) {
        if (str[i] != pop()) {
            return 0; // if char not matched means it's Not a palindrome
        }
    }

    return 1; // else it is a Palindrome
}

int main() {
    char str[MAX]; //string size of stack.

    printf("Enter a string: ");
    scanf("%s", str);

    if (isPalindrome(str))
        printf("Palindrome\n");
    else
        printf("Not a Palindrome\n");

    return 0;
}
