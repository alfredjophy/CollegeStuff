#include <stdio.h>
#include <stdlib.h>

struct NODE{
    int data;
    struct NODE *left,*right;
};
typedef struct NODE NODE;

NODE* create_node(int data){
    NODE *ptr=malloc(sizeof(NODE));
    ptr->data=data;
    ptr->left=ptr->right=NULL;
    return ptr;
}

void insert_btree(int data,NODE** root){
    if(*root==NULL){
        *root=create_node(data);
        return;
    } 
    if(data > (*root)->data)
        insert_btree(data,&((*root)->right));
    else
        insert_btree(data,&((*root)->left));

}

void inorder_btree(NODE* root){
    if(!root)   return;
    inorder_btree(root->left);
    printf("%d ",root->data);
    inorder_btree(root->right);
}

void free_btree(NODE* root){

    if(!root)   return;
    free_btree(root->left);
    free_btree(root->right);
    free(root);
}


int main(int argc , char** argv){
    
    int count=0,data=0;
    NODE* root=NULL;

    printf("Enter the number of elements : ");
    scanf("%d",&count);
    printf("Enter the numbers : ");
    for(int i=0;i<count;i++){
        scanf("%d",&data);
        insert_btree(data,&root);
    }

    printf("\nIN-ORDER   : ");
    inorder_btree(root);

    return 0;
}
