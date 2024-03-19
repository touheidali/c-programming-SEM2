#include <stdio.h>
#include <string.h>

#define SIZE 100

int stack[SIZE], top = -1;

void push(char c) {
    if (top == SIZE - 1) {
        printf("Stack overflow!\n");
        return;
    }
    top++;
    stack[top] = c;
}

char pop() {
    if (top == -1) {
        printf("Stack underflow!\n");
        return '\0';
    }
    return stack[top--];
}

int is_matching_pair(char open, char close) {
    if (open == '(' && close == ')')
        return 1;
    if (open == '{' && close == '}')
        return 1;
    return 0;
}

int are_parentheses_balanced(const char *input) {
    int i;
    for (i = 0; i < strlen(input); i++) {
        if (input[i] == '(' || input[i] == '{') {
            push(input[i]);
        }

        if (input[i] == ')' || input[i] == '}') {
            if (top == -1)
                return 0;

            char open = pop();
            if (!is_matching_pair(open, input[i]))
                return 0;
        }
    }

    if (top != -1)
        return 0;

    return 1;
}

int main() {
    char expression[SIZE];
    printf("Enter an expression: ");
    fgets(expression, sizeof(expression), stdin);
    expression[strcspn(expression, "\n")] = '\0';

    if (are_parentheses_balanced(expression))
        printf("The expression has balanced parentheses.\n");
    else
        printf("The expression does not have balanced parentheses.\n");

    return 0;
}