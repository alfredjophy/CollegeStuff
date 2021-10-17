#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

struct NODE{
        int data;
        struct NODE* next;
};
typedef struct NODE NODE;

NODE* start=NULL;

void append_list(int data){
        int pos=0;

        NODE* ptr = malloc(sizeof(NODE));
        ptr->data=data;
        ptr->next=NULL;

        if(!start){
                start=ptr;
        }
        else{
                pos=1;
                for(NODE* i=start;i->next;i=i->next)
                    pos++;
        }
        printf("Node Inserted at %dth position\n",pos);
}

/*i am too lazy to write two functions*/
/*lol*/
bool insert_into_list(int data,int pos,bool before){

    NODE* ptr = malloc(sizeof(NODE));
    ptr->data=data;
    ptr->next=NULL;

    if(before)
       pos--;

    NODE *node_pos;
    int count=0;
    for(NODE* i=start; (i && count<pos) ;i=i->next)
        count++;
     
    if(count!=pos)          // the position doesnt exist in the list
           return false; 

    ptr->next=node_pos->next;
    node_pos->next=ptr;

    return true;
}

void display_list(){

        printf("START ->");
        for(NODE* i=start;i;i=i->next)
            printf("{ %d } -> ",i->data);

        printf("\b|\n");
}

void free_list(){
        NODE* temp=NULL;
        for(NODE* i=start;i;i=i->next){
                free(temp);
                temp=i;
        }
        free(temp);
}
int main(){

        int num;
        int c;

        while(1){
                printf("\n1. Append to list \n2. Display list\n3. Exit\n");
                printf("Choice : ");
                scanf("%d",&c);

                switch(c){
                        case 1: printf("Enter number : ");
                                scanf("%d",&num);
                                append_list(num);
                                break;

                        case 2: display_list();
                                break;

                        case 3: free_list();
                                return 0;
                                break;
                        default: printf("Invalid Choice\n");
                }
        }
} 
