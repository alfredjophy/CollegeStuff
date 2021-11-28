#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

struct NODE {
    int data;
    struct NODE *prev,*next;
};
typedef struct NODE NODE;

NODE* create_node(int data) {
    NODE *ptr = malloc(sizeof(struct NODE));
    ptr->next=NULL;
    ptr->prev=NULL;
    ptr->data=data;
    return ptr;
}

struct LIST {
    NODE* start;
};
typedef struct LIST LIST;

void create_list(LIST *l) {
    l->start=NULL;
}

void append_list(LIST *l,int data) {
    NODE* ptr=create_node(data);
    if(!l->start) {
        l->start=ptr;
        return;
    }
    NODE*i=l->start;
    for(; i->next; i=i->next);
    ptr->prev=i;
    i->next=ptr;
}

void preppend_list(LIST *l,int data) {
    NODE* ptr=create_node(data);
    if(!l->start) {
        l->start=ptr;
        return;
    }
    ptr->prev=l->start;
    l->start=ptr;
}

bool insert_after(LIST *l,int data,int element) {
    NODE* ptr=create_node(data);
    if(!l->start) {
        l->start=ptr;
        return true;
    }
    NODE*i=l->start;
    for(; i&&i->data!=element; i=i->next);

    if(!i)
        return false;
    ptr->next=i->next;
    ptr->prev=i;
    if((ptr->next))
        (ptr->next)->prev=ptr;
    i->next=ptr;
    return true;
}

bool insert_before(LIST *l,int data,int element) {
    NODE* ptr=create_node(data);
    if(!l->start) {
        l->start=ptr;
        return true;;
    }
    NODE*i=l->start;
    for(; i&&i->data!=element; i=i->next);

    if(!i)
        return false;
    ptr->next=i;
    ptr->prev=i->prev;
    if((ptr->prev))
        (ptr->prev)->next=ptr;
    i->prev=ptr;
    if(i==l->start)
        l->start=ptr;
    return true;
}

bool delete_element(LIST *l,int element) {
    NODE*i=l->start;
    for(; i&&i->data!=element; i=i->next);

    if(!i)
        return false;
    if(i->next)
        (i->next)->prev=i->prev;
    if(i->prev)
        (i->prev)->next=i->next;
    if(i==l->start)
        l->start=i->next;

    free(i);
    return true;
}

bool delete_from_begining(LIST *l) {
    if(!l->start)
        return false;
    NODE *t=l->start;
    l->start=(l->start)->next;
    return true;
}

bool delete_from_end(LIST *l) {
    if(!l->start)
        return false;
    NODE*i=l->start;
    for(; i->next; i=i->next);
    (i->prev)->next=NULL;
    free(i);
    return true;
}
void display_list(LIST l) {
    if(!l.start) {
        printf("\nThe list is empty.\n");
        return;
    }

    printf("\nSTART -> ");
    for(NODE* i=l.start; i; i=i->next)
        printf("{ %d } <-> ",i->data);
    printf("\b|\n");
}

int search_list(LIST l,int ele) {
    int count=0;
    NODE* i=l.start;

    for(; i && i->data!=ele; i=i->next)
        ++count;
    if(!i)
        return -1;
    return count;
}


void free_list(LIST *l) {
    NODE* temp=NULL;
    for(NODE* i=l->start; i; i=i->next) {
        free(temp);
        temp=i;
    }
    free(temp);
}

int main() {
    int num,ele,pos;
    int c;
    LIST l;
    create_list(&l);

    while(1) {
        printf("\n\n1. Append to list \n2. Display list\n3. Insert After Element\n4. Insert Before Element\n5. Delete First Element\n6. Delete Last Element\n7. Delete Element\n8. Search Element\n0. Exit\n");
        printf("Choice : ");
        scanf("%d",&c);

        switch(c) {
        case 1:
            printf("Enter number : ");
            scanf("%d",&num);
            append_list(&l,num);
            break;

        case 2:
            display_list(l);
            break;

        case 3:
            printf("Enter number : ");
            scanf("%d",&num);
            printf("Enter element : ");
            scanf("%d",&ele);
            if(insert_after(&l,num,ele))
                printf("Inserted successfully.");
            else
                printf("Insertion failed");
            break;

        case 4:
            printf("Enter number : ");
            scanf("%d",&num);
            printf("Enter element : ");
            scanf("%d",&ele);
            if(insert_before(&l,num,ele))
                printf("Inserted successfully.");
            else
                printf("Insertion failed");
            break;

        case 5:
            if(delete_from_begining(&l))
                printf("Deleted successfully.");
            else
                printf("Deleted failed");
            break;

        case 6:
            if(delete_from_end(&l))
                printf("Deleted successfully.");
            else
                printf("Deleted failed");
            break;

        case 7:
            printf("Enter element : ");
            scanf("%d",&ele);
            if(delete_element(&l,ele))
                printf("Deleted successfully.");
            else
                printf("Deleted failed");
            break;
        case 8:
            printf("Enter element : ");
            scanf("%d",&ele);
            pos=search_list(l,ele);
            if(pos==-1)
                printf("Element not found");
            else
                printf("Element found at node %d",pos);
            break;


        case 0:
            free_list(&l);
            return 0;
            break;

        default:
            printf("Invalid Choice\n");
        }
    }
    return 0;
}
