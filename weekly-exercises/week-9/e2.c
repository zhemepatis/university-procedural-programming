#include <stdio.h>
#include <stdlib.h>

typedef struct Stack {int *arr; int size;} Stack;

void initStack(Stack *stack);
void printStack(Stack *stack);
int getStackSize(Stack *stack);
void push(Stack *stack, int value);
int top(Stack *stack);
int pop(Stack *stack);
void destroyStack(Stack *stack);

int main() {
    Stack smth;
    initStack(&smth);

    push(&smth, 1);
    push(&smth, 2);
    push(&smth, 3);

    int stackSize = getStackSize(&smth);
    int stackTop = pop(&smth);
    printStack(&smth);

    destroyStack(&smth);

    return 0;
}

void initStack(Stack *stack) {
    stack->arr = NULL; 
    stack->size = 0; 
}

void printStack(Stack *stack) {
    int stackSize = getStackSize(stack);
    int *stackArr = stack->arr;
    
    for(int i = 0 ; i < stackSize; ++i){
        printf("%d\n", stackArr[i]);
    }
}

int getStackSize(Stack *stack) {
    return (stack->size);
}

void push(Stack *stack, int value) {
    int stackSize = getStackSize(stack);

    stack->arr = realloc(stack->arr, (stackSize+1)*sizeof(int));
    int *stackArr = stack->arr;

    stackArr[stackSize]= value;
    (stack->size) = (stack->size) + 1;
}

int top(Stack *stack) {
    int stackSize = stack->size;
    if(!stackSize)
        return 0;
    int *stackArr = stack->arr;
    
    return stackArr[stackSize-1];
}

int pop(Stack *stack) {
    int stackTop = top(stack);
    int stackSize = getStackSize(stack);

    if(stackSize) {
        stack->arr = realloc(stack->arr, (stackSize-1)*sizeof(int));
        (stack->size) = (stack->size) - 1;
    }

    return stackTop;
}

void destroyStack(Stack *stack) {
    free(stack->arr);
    initStack(stack);
}