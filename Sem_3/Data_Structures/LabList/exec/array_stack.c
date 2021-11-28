#include <stdbool.h>
#include <stdio.h>
#define STACK_SIZE 10

int Stack[STACK_SIZE];
int top = -1;

bool push(int e) {
    if (top == STACK_SIZE)
        return false;
    Stack[++top] = e;
    return true;
}

bool pop() {
    if (top == -1)
        return false;
    top--;
    return true;
}

int peek() {
    return Stack[top];
}

bool isEmpty() {
    return top==-1;
}
bool isFull() {
    return top==STACK_SIZE;
}

int main() {
    int c;
    do {
        printf("\n1. Push\n2. Pop\n3. Peek\n4. Is the stack empty?\n5. Is the stack full\n0. Exit\nEnter selection : ");
        scanf(" %d", &c);
        switch (c) {
        case 1: {
            int e;
            printf("\nEnter number : ");
            scanf(" %d",&e);
            if(push(e))
                printf("Pushed into the stack successfully.\n");
            else
                printf("Stack Overflow!\n");
        }
        break;
        case 2: {
            if(isEmpty()) {
                printf("\nStack Underflow!\n");
                break;
            }
            printf("\nPopped %d from the stack\n",peek());
            pop();
        }
        break;
        case 3: {
            if(isEmpty())
                printf("\nStack Underflow!\n");
            else
                printf("\nTop = %d\n",peek());
        }
        break;
        case 4: {
            if(isEmpty())
                printf("\nThe stack is empty.\n");
            else
                printf("\nThe stack is not empty.\n");
        }
        break;
        case 5: {
            if(isFull())
                printf("\nThe stack is full.\n");
            else
                printf("\nThe stack is not full.\n");
        }
        break;
        }
    } while (c);
    return 0;
}
