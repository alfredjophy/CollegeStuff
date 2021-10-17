#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

struct NODE {
    int data;
    struct NODE *next;
};
struct NODE *head=NULL; 

struct NODE* create_node(int n){
    struct NODE *ptr = malloc(sizeof(struct NODE));
    ptr->next=NULL;
    ptr->data=n;
    return ptr;
}

void append_list(struct NODE *n){
    if(head == NULL)
        head=n;
    else{
        struct NODE *i=head;
        do{
            i=i->next;
        }while(i->next!=head);

        i->next=n;
    }
    n->next=head;
}

void prepend_list(struct NODE *n){
    append_list(n);
    head=n; 
}

bool isEmpty(){
    return !head;
}

int search_list(int x){
    int count=0;
    struct NODE *i=head;
    do{
        if(i->data==x)
            return count;
        i=i->next;
    }while(i!=head);
    return -1;

}
bool delete_list(int x){
    bool found=false;
    struct NODE *cur=head,*prev=NULL;
    do{
        if(cur->data==x){
            found=true;
            break;
        }
        prev=cur;
        cur=cur->next;
    }while(cur!=head);
    
    if(!found) 
        return false;
    if(cur==cur->next){
        head=NULL;
        free(cur);
        return true;
    }
    else if(cur==head){
        prev=head;
        do{
            prev=prev->next;
        }while(prev->next!=head);
        head=head->next;
    }
    prev->next=cur->next;
    free(cur);
    return true;
}

void display_list(){
    if(isEmpty())
        printf("Empty List");
    else{
        struct NODE *i=head;
        do{
            printf("%d ",i->data);
            i=i->next;
        }while(i!=head);
    }
}

void free_list(){
    struct NODE *temp=NULL,*i=head;
    do{
        free(temp);
        temp=i;
        i=i->next;
    }while(i!=head);
    free(i);
}
int main(){
    
    int num=0,c=1;
    struct NODE *ptr;
    printf("1.Append to the list\n2.Prepend to the list\n3.Search in list\n4.Is the list empty?\n5.Delete from the list\n6. Display list\n");
    do{
        printf("\nEnter your choice : ");
        scanf("%d",&c);

        switch(c){
            case 1 : printf("Enter the number to be inserted : ");
                     scanf("%d",&num);
                     ptr=create_node(num);
                     append_list(ptr);
                     break;

            case 2 : printf("Enter the number to be inserted : ");
                     scanf("%d",&num);
                     ptr=create_node(num);
                     prepend_list(ptr);
                     break;

            case 3 : printf("Enter the number to be searched : ");
                     scanf("%d",&num);
                     int loc = search_list(num);
                     if(loc==-1)
                         printf("Number not found.");
                     else
                        printf("The number at location %d",num);
                     break;

            case 4 : if(isEmpty()==true)
                        printf("The list is empty");
                     else
                        printf("The list is not empty");
                     break;

            case 5 : printf("Enter the number to be deleted : ");
                     scanf("%d",&num);
                     if(delete_list(num))
                        printf("%d deleted successfully",num);
                     else
                        printf("Deletion failed. Number not found.");
                     break;

            case 6 : display_list();
                     break;;
        }
    }while(c!=0);

    free_list();
    return 0;
}
