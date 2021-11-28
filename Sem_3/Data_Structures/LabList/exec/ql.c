#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

struct NODE {
    int n;
    struct NODE* link;
}*front=NULL,*rear=NULL;
typedef struct NODE NODE;

bool insert(int num) {
    NODE *ptr = malloc(sizeof(NODE));
    if(!ptr)
        return false;

    ptr->link=NULL;
    ptr->n=num;

    if(!front){
        front=rear=ptr;
        return true;
    }
    rear->link=ptr;
    rear=ptr;
    return true;
}

bool delete() {
    if(!front)
        return false;
    NODE* temp=front;
    front=front->link;
    free(temp);
    return true;
}

bool isEmpty() {
    return front==NULL;
}

int view_front() {
    return front->n;
}

int view_rear() {
    return rear->n;
}

int main() {
    int c;
    do {
        printf("\n1. Insert\n2. Delete\n3. View Front\n4. View Rear\n5. Is the queue empty?\n0. Exit\nEnter selection : ");
        scanf(" %d", &c);
        switch (c) {
        case 1: {
            int e;
            printf("\nEnter number : ");
            scanf(" %d",&e);
            if(insert(e))
                printf("Inserted into the queue successfully.\n");
            else
                printf("Queue is full!\n");
        }
        break;
        case 2: {
            if(isEmpty()) {
                printf("\nQueue is empty!\n");
                break;
            }
            printf("\nDeleted %d from the queue.\n",view_front());
            delete();
        }
        break;
        case 3: {
            if(isEmpty())
                printf("\nThe Queue is empty!");
            else
                printf("\nFRONT = %d\n",view_front());
        }
        break;
        case 4: {
            if(isEmpty())
                printf("\nThe stack is empty.\n");
            else
                printf("\nREAR = %d\n",view_rear());
        }
        break;
        case 5: {
            if(isEmpty())
                printf("\nThe Queue is empty!");
            else
                printf("\nThe queue is not empty.\n");
        }
        }
    } while (c);
    return 0;
}
