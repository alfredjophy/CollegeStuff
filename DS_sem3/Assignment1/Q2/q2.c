#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

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

// compress_sparse_matrix methods
int * compress_sparse_matrix(int rows,int columns,int *matrix){
        int NNZ=0;

        //counting number of ones
        for(int i=0;i<rows*columns;i++)
                if(matrix[i])
                        NNZ++;

        int *csm=(int*)malloc(3*NNZ*sizeof(int));

        int csm_index=0;

        *((csm+csm_index*3)+0)=rows;
        *((csm+csm_index*3)+1)=columns;
        *((csm+csm_index*3)+2)=NNZ;
        csm_index++;
        
        for(int i=0;i<rows;i++)
                for(int j=0;j<columns;j++)
                {       
                        if(matrix[i*columns+j]){
                                *((csm+csm_index*3)+0)=i;
                                *((csm+csm_index*3)+1)=j;
                                *((csm+csm_index*3)+2)=matrix[i*columns+j];
                                csm_index++;
                        }
                }
        
        return csm;
}

void display_from_compressed_sparse_matrix(int *matrix){
        int rows,columns;
        rows=*(matrix),columns=*(matrix+1);
        
        int csm_index=1;
        for(int i=0;i<rows;i++){
                printf("\n");
                for(int j=0;j<columns;j++){
                        if( i == *((matrix+3*csm_index)+0) && j == *((matrix+3*csm_index)+1) ){
                                       printf("%d ",*((matrix+3*csm_index)+2));
                                       csm_index++;
                        }
                        else
                                printf("0 ");
                }
        }
}

bool is_matrix_sparse(int* matrix,int rows,int columns){
        int NNZ=0;
        for(int i=0;i<rows*columns;i++)
                if(matrix[i])
                        NNZ++;
        return (NNZ<(rows*columns)/2)?true:false;
}
int main(){
        int *matrix=NULL;
        int rows,columns;
        int matrix_size;
        int size;

        int *compressed_sparse_matrix=NULL;

        matrix_input(&matrix,&rows, &columns,&size);
        printf("The Matrix : \n");
        matrix_display(matrix,rows,columns);
        
        if(!is_matrix_sparse(matrix, rows,columns)){
                printf("\nThe matrix is not sparse.");
                return 0;
        }

        printf("\nThe matrix is sparse\n");
        compressed_sparse_matrix=compress_sparse_matrix(rows,columns,matrix);
        printf("\nCompressed Reperesentation of the sparse Matrix\n");
        matrix_display(compressed_sparse_matrix,(*(compressed_sparse_matrix+2)+1),3);
        printf("\nRecreated matrix from compressed sparse matrix\n");
        display_from_compressed_sparse_matrix(compressed_sparse_matrix);

        free(matrix);
        free(compressed_sparse_matrix);

        return 0;
}

