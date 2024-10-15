#include<stdio.h>
#include<stdlib.h>

typedef struct Stack
{
    int top;
    unsigned capacity;
    int *array;
} stk;

// initialize the a stack 

stk *createSTK(unsigned capacity)
{
    stk* stack = (stk *)malloc(sizeof(stk));
    stack->capacity = capacity;
    stack->top = -1;
    stack->array = (int *)malloc(stack->capacity * sizeof(int));
    return stack;
}


// Is full return true is stack is full

int isFull(stk *Stack)
{
    return Stack->top == Stack->capacity - 1;   
}


// Is enpty returns true is top == -1
int isEmpty(stk *Stack)
{
    return Stack->top == -1;
}

// pushes an element to stack if the stack is not full

void push(stk *Stack, int item)
{
    if (isFull(Stack))
    {
        printf("Stack is full\n");
        return;
    }

    Stack->array[++ Stack->top] = item;
    printf("%d pushed to stack. \n",item);
}

//  pop the element at the top and returns it

int pop(stk *Stack)
{
    if (isEmpty(Stack))
    {
        return -1;
    }
    return Stack->array[Stack->top--];
}

// prints the stack ..

void Printstack(stk *Stack)
{
    if (isEmpty(Stack))
    {
        printf("stack is empty\n");
        return;
    }
    printf("%d <--- Top\n",Stack->array[Stack->top]);

    for (int i = Stack->top-1; i>=0; i--)
    {
        printf("%d\n",Stack->array[i]);
    }

    printf("END OF STACK \n\n");

}


// main program 

int main() {
    unsigned capacity = 5;
    stk *stack = createSTK(capacity);

    push(stack, 10);
    push(stack, 20);
    push(stack, 30);
    push(stack, 40);
    push(stack, 50);
    push(stack, 60); // Should indicate stack is full

    printf("Current Stack:\n");
    Printstack(stack);


    printf("\nPopped %d from stack\n", pop(stack));
    printf("Popped %d from stack\n", pop(stack));


    printf("\nStack after popping two elements:\n");
    Printstack(stack);

 
    free(stack->array);
    free(stack);

    return 0;
}