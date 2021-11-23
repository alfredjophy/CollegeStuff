#include <stdio.h>
#include <stdlib.h>

struct NODE{
    int data;
    struct NODE *prev,*next;
};
typedef struct NODE NODE;

NODE* create_node(int data){
    NODE *ptr = malloc(sizeof(struct NODE));
    ptr->next=NULL;
    ptr->prev=NULL;
    ptr->data=data;
    return ptr;
}

struct LIST{
    NODE* start;
};
typedef struct LIST LIST;

void create_list(LIST *l){
    l->start=NULL;
}

void append_list(LIST *l,int data){
    NODE* ptr=create_node(data);
    if(!l->start){
        l->start=ptr;
        return;
    }
    NODE*i=l->start;
    for(;i->next;i=i->next);
    ptr->prev=i;
    i->next=ptr;
}

void preppend_list(LIST *l,int data){
    NODE* ptr=create_node(data);
    if(!l->start){
        l->start=ptr;
        return;
    }
    ptr->prev=l->start;
    l->start=ptr;
}

void insert_after(LIST *l,int data,int element){
    NODE* ptr=create_node(data);
    if(!l->start){
        l->start=ptr;
        return;
    }
    NODE*i=l->start;
    for(;i->data!=element&&i;i=i->next);
    
    if(!i)
        return;
    ptr->next=i->next;
    ptr->prev=i;
    if((ptr->next))
        (ptr->next)->prev=ptr;
    i->next=ptr;
}
void insert_before(LIST *l,int data,int element){
    NODE* ptr=create_node(data);
    if(!l->start){
        l->start=ptr;
        return;
    }
    NODE*i=l->start;
    for(;i->data!=element&&i;i=i->next);

    if(!i)
        return;
    ptr->next=i;
    ptr->prev=i->prev;
    if((ptr->prev))
        (ptr->prev)->next=ptr;
    i->prev=ptr;
    if(i==l->start)
        l->start=ptr;
}
void delete_element(LIST *l,int element){
    NODE*i=l->start;
    for(;i->data!=element&&i;i=i->next);

    if(!i)
        return;
    if(i->next)
        (i->next)->prev=i->prev;
    if(i->prev)
        (i->prev)->next=i->next;
    if(i==l->start)
        l->start=i->next;

    free(i);
}
void delete_from_begining(LIST *l){
    if(!l->start)
        return;
    NODE *t=l->start;
    l->start=(l->start)->next;
}
void delete_from_end(LIST *l){
    if(!l->start)
        return;
    NODE*i=l->start;
    for(;i->next;i=i->next);
    (i->prev)->next=NULL;
    free(i);
}

int main(){

    return 0;
}
