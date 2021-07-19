// all methods combined
#include <stdio.h>
#include <stdlib.h>

// matrix methods
void matrix_input(int** matrix,int *rows,int *columns,int *size){
        printf("Enter the number of rows and columns of the matrix\n");
        printf("Rows    : ");
        scanf("%d",rows);
        printf("Columns : ");
        scanf("%d",columns);
        
        *size=(*rows)*(*columns)*sizeof(int);
        *matrix=calloc((*rows)*(*columns),sizeof(int));
        
        printf("Enter the elements of the matrix : \n");
        for(int i=0;i<*rows;i++)
                for(int j=0;j<*columns;j++){
                        scanf("%d",((*matrix+i*(*columns))+j));
                }
}

void matrix_display(int* matrix,int rows,int columns){
        for(int i=0;i<rows;i++){
                printf("\n");
                for(int j=0;j<columns;j++)
                        printf("%d ",*((matrix+i*columns)+j));
        }

        printf("\n");
}

// linked list methods
struct node{
        int x,y,val;
        struct node* link;
};
typedef struct node node;

void prepend_list(node** start,int x,int y,int val){
        node* temp=(node *)calloc(1, sizeof(node));
        
        temp->link=(*start);
        (*start)=temp;
        
        (*start)->x=x;
        (*start)->y=y;
        (*start)->val=val;
}

void display_list(node* start){
        for(node* i=start;i!=NULL;i=i->link){
                //printf stuff
                printf("%d %d %d\n",i->x,i->y,i->val);
        }
}
void free_list(node** start){
        while((*start)){
                node* temp=*start;
                *start=(*start)->link;
                free(temp);
        }
}
int sizeof_list(node* start){
        int number_of_nodes=0;
        while(start){
                node* temp=start;
                start=start->link;
                number_of_nodes++;
        }
        return number_of_nodes*sizeof(node);
}

// compression methods
void csm_array_method(int rows,int columns,int *matrix,int **csm,int *csm_size,int *csm_rows,int *csm_cols){
        int number_of_ones=0;

        //counting number of ones
        for(int i=0;i<rows*columns;i++)
                if(matrix[i])
                        number_of_ones++;

        *csm_size=number_of_ones*3*sizeof(int);
        *csm=(int*)malloc(*csm_size);

        int csm_index=0;
        for(int i=0;i<rows;i++)
                for(int j=0;j<columns;j++)
                {       
                        if(matrix[i*columns+j]){
                                *((*csm+csm_index*3)+0)=i;
                                *((*csm+csm_index*3)+1)=j;
                                *((*csm+csm_index*3)+2)=matrix[i*columns+j];
                                csm_index++;
                        }
                }
        *csm_cols=3,*csm_rows=number_of_ones;
}

void csm_linkedL_method(node** start,int rows,int columns,int *matrix){
        *start=NULL;
        for(int i=0;i<rows;i++)
                for(int j=0;j<columns;j++)
                        if(*((matrix+i*columns)+j))
                                prepend_list(&*start,i,j,*((matrix+i*columns)+j));
}
int main(){


        return 0;
}
