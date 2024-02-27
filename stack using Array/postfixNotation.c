// WAP to convert infix notation of an expression to Postfix Notation (Reverse Polish Notation) using stack (array)

#include <stdio.h>
#include <stdlib.h>
#define MAX_STACK_SIZE 100

// Structure for the stack
struct Stack
{
    int top;
    char items[MAX_STACK_SIZE];
};



// Function to push an element onto the stack
void push(struct Stack *stack, char item)
{
    if (stack->top == MAX_STACK_SIZE - 1)
    {
        printf("Stack Overflow\n");
        _Exit(1);
    }
    stack->items[++stack->top] = item;
}

// Function to pop an element from the stack
char pop(struct Stack *stack)
{
    if (stack->top == -1)
    {
        printf("Stack Underflow\n");
        _Exit(1); // Exit without cleanup for simplicity
    }
    return stack->items[stack->top--];
}

// Function to check if a character is a digit
int isDigitorChar(char c)
{
    return (c >= '0' && c <= '9') || (c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z');
}


// function to check if the character is a operator

int isOperator(char c)
{
    return (c == '+' || c == '-' || c == '*' || c == '/' || c == '$');
}

// Function to convert infix expression to postfix expression
void infixToPostfix(char infix[], char postfix[])
{
    struct Stack stack;
    stack.top = -1;

    int i = 0, j = 0;

    while (infix[i] != '\0')
    {
        if (isDigitorChar (infix[i]))
        {
            // If the character is a digit or char , append it to the postfix expression
            while (isDigitorChar (infix[i]))
            {
                postfix[j++] = infix[i++];
            }
            postfix[j++] = ' '; // space to separate digits
        }
        else if (infix[i] == '(')
        {
            // If the character is an opening parenthesis, push it onto the stack
            push(&stack, infix[i++]);
        }
        else if (infix[i] == ')')
        {
            // If the character is a closing parenthesis, pop operators from the stack
            // and append them to the postfix expression until an opening parenthesis is encountered
            while (stack.top != -1 && stack.items[stack.top] != '(')
            {
                postfix[j++] = pop(&stack);
            }
            // Pop the opening parenthesis from the stack
            pop(&stack);
            i++;
        }
        else if (infix[i] == '+' || infix[i] == '-' || infix[i] == '*' || infix[i] == '/')
        {
            // If the character is an operator, pop operators from the stack and append them
            // to the postfix expression as long as they have equal or higher precedence
            while (stack.top != -1 && isOperator(stack.items[stack.top]) &&
                   infix[i] <= stack.items[stack.top])
            {
                postfix[j++] = pop(&stack);
            }
            // Push the current operator onto the stack
            push(&stack, infix[i++]);
        }
        else
        {
            // Skip any other characters (e.g., spaces)
            i++;
        }
    }

    // Pop any remaining operators from the stack and append them to the postfix expression
    while (stack.top != -1)
    {
        postfix[j++] = pop(&stack);
    }

    // Null-terminate the postfix expression
    postfix[j] = '\0';
}

int main()
{
    char infixExpression[100];
    char postfixExpression[100];

    printf("Enter an infix expression: ");
    fgets(infixExpression, sizeof(infixExpression), stdin);

    infixToPostfix(infixExpression, postfixExpression);

    printf("Postfix expression: %s\n", postfixExpression);

    return 0;
}
