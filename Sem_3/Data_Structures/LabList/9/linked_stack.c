#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

typedef struct node node;
struct node{
    int n;
    node* link;
}*top=NULL;

bool push(int e) {
    node* ptr=malloc(sizeof(node));
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
    node* ptr=top;
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
        printf("\n1. Push\n2. Pop\n3. Peek\n0. Exit\nEnter "
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
            } break;
            case 2:{
                if(isEmpty()){
                    printf("Stack Underflow!\n");
                    break;
                }
                printf("Confirm to pop %d (y/n).\n",peek());
                char c;
                scanf(" %c",&c);
                if(c=='y'||c=='Y')
                    pop();
            }break;
            case 3:{
                if(isEmpty())
                    printf("Empty Stack!");
                else
                printf("%d\n",peek());
            } break;
        }
    } while (c);
    return 0;
}
