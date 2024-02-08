#include<stdio.h>
#include<stdlib.h>
#include <limits.h>

struct Stack
{
    int top;
    unsigned size;
    int* array;
};

// 1 -> Initialize
// TODO: Complete the function to initialize a new stack with a given size
struct Stack* createStack(unsigned size)
{
    struct Stack* stack = (struct Stack*) malloc(sizeof(struct Stack));
    stack->size  = size;
    stack->top = -1;
    stack->array = (int*)malloc(stack->size * sizeof(int));
    return stack;
}

// 2 -> isFull
// TODO: Complete the function. It should check if the stack provided to it is full
int isFull(struct Stack* stack)
{
    return stack->top == stack->size -1;
}

// 3 -> isEmpty
// TODO: Complete the function. It should check if the stack provided to it is empty
int isEmpty(struct Stack* stack)
{
    return stack->top == -1;
};

// 4 -> push
void push(struct Stack *stack, int item)
{
    if (isFull(stack))
        return ;
    stack->array[++stack->top] = item;
    printf("%d Pushed to stack\n", item);
}

// 5 -> peek
int peek(struct Stack* stack)
{
    if (isEmpty(stack))
        return INT_MIN;
    return stack->array[stack->top];
}

// 6 -> pop
// TODO: Complete the function. It should pop an element from the stack and return it. For an empty stack, it should throw an error message
int pop(struct Stack* stack)
{
    if (isEmpty(stack))
        return INT_MIN;
    return stack->array[stack->top--];
}

int main()
{
    struct Stack* stack = createStack(100);
    
    push(stack, 28);
    push(stack, 9);
    push(stack, 13);

    printf("%d Popped from Stack\n", pop(stack));

    return 0;
}