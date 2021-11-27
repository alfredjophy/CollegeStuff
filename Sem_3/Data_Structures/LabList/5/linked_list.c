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
        NODE* ptr = malloc(sizeof(NODE));
        ptr->data=data;
        ptr->next=NULL;

        if(!l->start){
                l->start=ptr;
        }
        else{
            NODE* i=l->start;
            for(;i->next;i=i->next);
            i->next=ptr;            
        }
}

bool insert_after_list(LIST *l,int data,int ele){
    NODE* ptr = malloc(sizeof(NODE));
    ptr->data=data;
    ptr->next=NULL;
    
    for(NODE*i = l->start;i;i=i->next)
        if(i->data==ele){
            ptr->next=i->next;
            i->next=ptr;
            return true;
        }

    return false;
}

bool delete_after_list(LIST *l,int ele){

    for(NODE*i = l->start;i;i=i->next)
        if(i->data==ele){
            NODE* temp=i->next;
            i->next=(i->next)->next;
            free(temp);
            return true;
        }
    return false;
}


void display_list(LIST l){
    if(!l.start){
        printf("\nThe list is empty.\n");
        return;
    }

    printf("\nSTART -> ");
    for(NODE* i=l.start;i;i=i->next)
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

        int num,ele;
        int c;
        LIST l;
        create_list(&l);

        while(1){
                printf("\n1. Append to list \n2. Display list\n3. Insert After Element\n4. Deletion After Element\n0. Exit\n");
                printf("Choice : ");
                scanf("%d",&c);

                switch(c){
                        case 1: printf("Enter number : ");
                                scanf("%d",&num);
                                append_list(&l,num);
                                break;

                        case 2: display_list(l);
                                break;

                        case 3: printf("Enter number : ");
                                scanf("%d",&num);
                                printf("Enter element : ");
                                scanf("%d",&ele);
                                if(insert_after_list(&l,num,ele))
                                    printf("Inserted successfully.");
                                else
                                    printf("Insertion failed");
                                break;

                        case 4: printf("Enter element : ");
                                scanf("%d",&ele);
                                if(delete_after_list(&l,ele))
                                    printf("Deleted successfully.");
                                else
                                    printf("Deleted failed");
                                break;

                        case 0: free_list(&l);
                                return 0;
                                break;

                        default: printf("Invalid Choice\n");
                }
        }
} 
