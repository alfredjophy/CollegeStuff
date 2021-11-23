#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

struct NODE{
        int data;
        struct NODE* next;
};
typedef struct NODE NODE;

struct LIST{
    NODE *start;

};
typedef struct LIST LIST;

void append_list(LIST *l,int data){
        int pos=0;

        NODE* ptr = malloc(sizeof(NODE));
        ptr->data=data;
        ptr->next=NULL;

        if(!l->start){
                l->start=ptr;
        }
        else{
                pos=1;
                for(NODE* i=l->start;i->next;i=i->next)
                    pos++;
        }
        printf("Node Inserted at %dth position\n",pos);
}

/*i am too lazy to write two functions*/
/*lol*/
bool insert_into_list(LIST *l,int data,int pos,bool before){

    NODE* ptr = malloc(sizeof(NODE));
    ptr->data=data;
    ptr->next=NULL;

    if(before)
       pos--;

    NODE *node_pos;
    int count=0;
    for(NODE* i=l->start; (i && count<pos) ;i=i->next)
        count++;
     
    if(count!=pos)          // the position doesnt exist in the list
           return false; 

    ptr->next=node_pos->next;
    node_pos->next=ptr;

    return true;
}

void display_list(LIST *l){

        printf("START ->");
        for(NODE* i=l->start;i;i=i->next)
            printf("{ %d } -> ",i->data);

        printf("\b|\n");
}

void free_list(LIST *l){
        NODE* temp=NULL;
        for(NODE* i=l->start;i;i=i->next){
                free(temp);
                temp=i;
        }
        free(temp);
}

void create_list(LIST *l){
    l->start=NULL;
}
int main(){

        int num;
        int c;
        LIST l;
        create_list(&l);

        while(1){
                printf("\n1. Append to list \n2. Display list\n3. Exit\n");
                printf("Choice : ");
                scanf("%d",&c);

                switch(c){
                        case 1: printf("Enter number : ");
                                scanf("%d",&num);
                                append_list(&l,num);
                                break;

                        case 2: display_list(&l);
                                break;

                        case 3: free_list(&l);
                                return 0;
                                break;
                        default: printf("Invalid Choice\n");
                }
        }
} 
