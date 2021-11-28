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
            printf("Enter number : ");
            scanf(" %d",&e);
            if(push(e))
                printf("Pushed into the stack successfully.\n");
            else
                printf("Stack Overflow!\n");
        }
        break;
        case 2: {
            if(isEmpty()) {
                printf("Stack Underflow!\n");
                break;
            }
            printf("Confirm to pop %d (y/n).\n",peek());
            char c;
            scanf(" %c",&c);
            if(c=='y'||c=='Y')
                pop();
        }
        break;
        case 3: {
            if(isEmpty())
                printf("Stack Overflow!");
            else
                printf("%d\n",peek());
        }
        break;
        case 4: {
            if(isEmpty())
                printf("The stack is empty.");
            else
                printf("The stack is not empty");
        }
        break;
        }
    } while (c);
    return 0;
}
