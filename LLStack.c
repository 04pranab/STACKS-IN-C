#include <stdio.h>
#include <stdlib.h>

typedef struct node
{
    int data;
    struct node *next;
} stk;


// create a node.
stk *getnode()
{
    stk *a;
    a = (stk *)malloc(sizeof(stk));

    if (a == NULL)
    {
        printf("Memory Allocting Fail. \n");
        return NULL;
    }

    else
    {
        a->next = NULL;
        return a;
    }
}


// initialize a stack 
stk *initialize()
{
    stk *top = NULL;
    return top;
}

// checks whether the stack is empty
int isEmpty(stk *top)
{
    return top == NULL;
}

// pushes an element to the stack from the top.

stk *push(stk *top, int x)
{
    stk *temp = getnode();
    temp->data = x;
    temp->next = NULL;

    if (isEmpty(top))
    {
        return temp;
    }
    temp->next = top;
    top = temp;

    return top;
}

// pops an the top element of the stack if stack is not empty.
int pop(stk **top)
{
    if (isEmpty((*top)))
    {
        printf("Stack is Empty.\n");
        return 0;
    }

    stk *temp = (*top);
    int x = (*top)->data;
    (*top) = (*top)->next;

    free(temp);

    return x;
}

// prints the stack 
void Printstack(stk *top)
{
    if (isEmpty(top))
    {
        printf("stack is empty\n");
        return;
    }
    printf("%d <--- Top\n", top->data);

    top = top->next;
    while (top != NULL)
    {
        printf("%d\n", top->data);
        top = top->next;
    }
    printf("END OF STACK \n\n");
}

int main()
{
    stk *top = initialize(); // Initialize the stack

    // Push elements onto the stack
    top = push(top, 10);
    top = push(top, 20);
    top = push(top, 30);

    printf("Stack after pushing 10, 20, 30:\n");
    Printstack(top);

    // Pop an element from the stack
    printf("Popped element: %d\n", pop(&top));

    printf("Stack after popping one element:\n");
    Printstack(top);

    // Pop remaining elements
    printf("Popped element: %d\n", pop(&top));
    printf("Popped element: %d\n", pop(&top));

    // Try to pop from an empty stack
    printf("Attempting to pop from an empty stack:\n");
    pop(&top);

    return 0;
}
