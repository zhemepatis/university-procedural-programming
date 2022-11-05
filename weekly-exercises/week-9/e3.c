#include <stdio.h>
#include <stdlib.h>
#include <math.h>

typedef struct Point {
    double x, y;
} Point;

typedef struct Stack {
    Point *arr; int size;
} Stack;

// Stack functions
void initStack(Stack *stack);
void printStack(Stack *stack);
int getStackSize(Stack *stack);
void push(Stack *stack, Point value);
Point top(Stack *stack);
Point pop(Stack *stack);
void destroyStack(Stack *stack);

// Point functions
Point createPoint(double x, double y);
void printPoint(Point p);
double getDistance(Point a, Point b);

int main() {
    Stack smth;
    initStack(&smth);

    // printf("%p", smth.arr);
    push(&smth, createPoint(0.0, 0.0));
    push(&smth, createPoint(4.0, 5.0));
    push(&smth, createPoint(-2.0, 3.0));
    push(&smth, createPoint(3.0, -4.0));
    push(&smth, createPoint(-5.0, -6.0));
    printStack(&smth);

    int stackSize = getStackSize(&smth);
    Point stackTop = pop(&smth);

    destroyStack(&smth);

    return 0;
}

// Stack functions
void initStack(Stack *stack) {
    stack->arr = NULL; 
    stack->size = 0; 
}

void printStack(Stack *stack) {
    int stackSize = getStackSize(stack);
    Point *stackArr = stack->arr;
    
    Point nullPoint = createPoint(0.0, 0.0);
    for(int i = 0 ; i < stackSize; ++i) {
        printPoint(stackArr[i]);
        printf(" %f\n", getDistance(nullPoint, stackArr[i]));
    }
}

int getStackSize(Stack *stack) {
    return (stack->size);
}

void push(Stack *stack, Point value) {
    int stackSize = getStackSize(stack);

    stack->arr = realloc(stack->arr, (stackSize+1)*sizeof(Point));
    Point *stackArr = stack->arr;

    stackArr[stackSize] = value;
    (stack->size) = (stack->size) + 1;
}

Point top(Stack *stack) {
    int stackSize = stack->size;
    if(!stackSize) {
        return createPoint(0.0, 0.0);
    }
        
    Point *stackArr = stack->arr;
    
    return stackArr[stackSize-1];
}

Point pop(Stack *stack) {
    Point stackTop = top(stack);
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

// Point functions
Point createPoint(double x, double y) {
    Point point;

    point.x = x;
    point.y = y;

    return point;
}

void printPoint(Point p) {
    printf("(%f, %f)", p.x, p.y);
}

double getDistance(Point a, Point b) {
    return sqrt(pow((b.x-a.x), 2) + pow((b.y-a.y), 2));
}