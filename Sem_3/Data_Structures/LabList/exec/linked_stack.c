#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

struct NODE {
    int n;
    struct NODE* link;
}*top=NULL;
typedef struct NODE NODE;

bool push(int e) {
    NODE* ptr=malloc(sizeof(NODE));
    if(!ptr)
        return false;
    ptr->n=e;
    ptr->link=top;
    top=ptr;
    return true;
}

bool pop() {
    if(!top)
        return false;
    NODE* ptr=top;
    top=top->link;
    free(ptr);
    return true;
}

int peek() {
    return top->n;
}

bool isEmpty() {
    return !top;
}

int main(int argc, char **argv) {
    int c;
    do {
        printf("\n1. Push\n2. Pop\n3. Peek\n4. Is the stack empty?\n0. Exit\nEnter "
               "selection : ");
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
            printf("\nPopped %d from the stack.\n",peek());
            pop();
        }
        break;
        case 3: {
            if(isEmpty())
                printf("\nStack Overflow!");
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
        }
    } while (c);
    return 0;
}
