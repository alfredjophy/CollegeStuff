#include <stdio.h>
#include <stdbool.h>
#define SIZE 5

int QUEUE[SIZE];
int front=-1,rear=-1;

bool isEmpty() {
    return front==-1;
}

bool isFull() {
    return (rear+1)%SIZE==front;
}
bool enque(int num) {
    if(isFull())
        return false;

    rear=(rear+1)%SIZE;
    QUEUE[rear]=num;
    if(isEmpty())
        front++;

    return true;
}

bool denque() {
    if(isEmpty())
        return false;
    if(front==rear)
        front=rear=-1;
    else
        front=(front+1)%SIZE;
    return true;
}

int view_front() {
    return QUEUE[front];
}


int view_rear() {
    return QUEUE[rear];
}

int main() {


    int c;
    do {
        printf("\n1. Insert\n2. Delete\n3. View Front\n4. Is the queue empty?\n5. Is the queue full?\n6. View Rear\n0. Exit\nEnter selection : ");
        scanf(" %d", &c);
        switch (c) {
        case 1: {
            int e;
            printf("\nEnter number : ");
            scanf(" %d",&e);
            if(enque(e))
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
            denque();
        }
        break;
        case 3: {
            if(isEmpty())
                printf("\nQueue is empty!\n");
            else
                printf("\n FRONT = %d\n",view_front());
        }
        break;
        case 4: {
            if(isEmpty())
                printf("The queue is empty.");
            else
                printf("The queue is not empty.");
        }
        break;
        case 5: {
            if(isFull())
                printf("The queue is full.");
            else
                printf("The queue is not full.");
        }
        break;
        case 6: {
            if(isEmpty())
                printf("\nQueue is empty!\n");
            else
                printf("\n REAR = %d\n",view_rear());
        }
        break;

        }
    } while (c);
    return 0;
}


