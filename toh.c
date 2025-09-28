#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <limits.h>

// Stack structure
typedef struct Stack {
    int capacity;
    int top;
    int *array;
} Stack;

// Function to create a stack of given capacity
Stack* createStack(int capacity) {
    Stack* stack = (Stack *)malloc(sizeof(Stack));
    stack->capacity = capacity;
    stack->top = -1;
    stack->array = (int *)malloc(capacity * sizeof(int));
    return stack;
}

// Check if the stack is full
int isFull(Stack* stack) {
    return stack->top == stack->capacity - 1;
}

// Check if the stack is empty
int isEmpty(Stack* stack) {
    return stack->top == -1;
}

// Push an item onto the stack
void push(Stack* stack, int item) {
    if (!isFull(stack)) {
        stack->array[++stack->top] = item;
    }
}

// Pop an item from the stack
int pop(Stack* stack) {
    if (!isEmpty(stack)) {
        return stack->array[stack->top--];
    }
    return INT_MIN;
}

// Move disks between poles
void moveDisks(Stack* src, Stack* dest, char s, char d) {
    int pole1TopDisk = pop(src);
    int pole2TopDisk = pop(dest);

    if (pole1TopDisk == INT_MIN) {
        push(src, pole2TopDisk);
        printf("Move disk %d from pole %c to pole %c\n", pole2TopDisk, d, s);
    } else if (pole2TopDisk == INT_MIN) {
        push(dest, pole1TopDisk);
        printf("Move disk %d from pole %c to pole %c\n", pole1TopDisk, s, d);
    } else if (pole1TopDisk > pole2TopDisk) {
        push(src, pole1TopDisk);
        push(src, pole2TopDisk);
        printf("Move disk %d from pole %c to pole %c\n", pole2TopDisk, d, s);
    } else {
        push(dest, pole2TopDisk);
        push(dest, pole1TopDisk);
        printf("Move disk %d from pole %c to pole %c\n", pole1TopDisk, s, d);
    }
}

int main() {
    int num, i, moves;
    char s = 'A', d = 'C', a = 'B';

    printf("Enter number of disks: ");
    scanf("%d", &num);

    Stack *src = createStack(num);
    Stack *aux = createStack(num);
    Stack *dest = createStack(num);

    for (i = num; i >= 1; i--) push(src, i);

    moves = pow(2, num) - 1;

    for (i = 1; i <= moves; i++) {
        if (i % 3 == 1)
            moveDisks(src, dest, s, d);
        else if (i % 3 == 2)
            moveDisks(src, aux, s, a);
        else if (i % 3 == 0)
            moveDisks(aux, dest, a, d);
    }
    return 0;
}
