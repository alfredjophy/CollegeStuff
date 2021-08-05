#include <stdio.h>
#include <stdlib.h>

struct NODE{

        int data;
        struct NODE* next;
};
typedef struct NODE NODE;

NODE* start=NULL;

void append_LIST(int data){
        int pos=0;

        NODE* ptr = malloc(sizeof(NODE));
        ptr->data=data;
        ptr->next=NULL;

        if(start==NULL){
                start=ptr;
        }
        else{
                pos=1;
                NODE* temp=start;
                while(temp->next){
                        pos++;
                        temp=temp->next;
                }
                temp->next=ptr;
        }

        printf("Node Inserted at %dth position\n",pos);
}

void display_LIST(){

        printf("START ->");
        for(NODE* i=start;i;i=i->next)
                printf("{ %d } -> ",i->data);

        printf("\b|\n");
}

void free_LIST(){
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
                                append_LIST(num);
                                break;

                        case 2: display_LIST();
                                break;

                        case 3: free_LIST();
                                return 0;
                                break;
                        default: printf("Invalid Choice\n");
                }
        }
        free_LIST();
        return 0;
} 
