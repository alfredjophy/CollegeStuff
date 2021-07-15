// sparse matrix to array
#include <stdio.h>
#include <stdlib.h>

int* matrix_input(int *rows,int *columns,int *size){
        printf("Enter the number of rows and columns of the matrix\n");
        printf("Rows    : ");
        scanf("%d",rows);
        printf("Columns : ");
        scanf("%d",columns);
        
        *size=(*rows)*(*columns)*sizeof(int);
        int *matrix=calloc((*rows)*(*columns),sizeof(int));
        
        printf("Enter the elements of the matrix : \n");
        for(int i=0;i<*rows;i++)
                for(int j=0;j<*columns;j++){
                        scanf("%d",((matrix+i*(*columns))+j));
                }
 
        return matrix;
}

void matrix_display(int rows,int columns,int* matrix){
        for(int i=0;i<rows;i++){
                printf("\n");
                for(int j=0;j<columns;j++)
                        printf("%d ",*((matrix+i*columns)+j));
        }

        printf("\n");
}

int* csm_array_method(int rows,int columns,int *matrix,int *csm_size,int *csm_rows,int *csm_cols){
        int number_of_ones=0;

        //counting number of ones
        for(int i=0;i<rows*columns;i++)
                if(matrix[i])
                        number_of_ones++;
        
        *csm_size=number_of_ones*3*sizeof(int);
        int* csm=(int*)malloc(*csm_size);
        
        int csm_index=0;
        for(int i=0;i<rows;i++)
                for(int j=0;j<columns;j++)
                {       
                        if(matrix[i*columns+j]){
                                csm[csm_index*3+0]=i;
                                csm[csm_index*3+1]=j;
                                csm[csm_index*3+2]=matrix[i*columns+j];
                                csm_index++;
                        }
                }
        *csm_cols=3,*csm_rows=number_of_ones;
        return csm;
}

int main(){
        int *matrix=NULL;
        int rows,columns;
        int matrix_size;
        int size;
        
        int *compresses_sparse_matrix=NULL;
        int rows_csm,columns_csm;               // csm - compresses_sparse_matrix 
        int size_csm;

        matrix=matrix_input(&rows, &columns,&size);
        printf("The Matrix : \n");
        matrix_display(rows,columns,matrix);
        
        compresses_sparse_matrix=csm_array_method(rows,columns,matrix,&size_csm,&rows_csm,&columns_csm);
        printf("\nX Y Value");
        matrix_display(rows_csm,columns_csm,compresses_sparse_matrix);

        printf("Size of Sparse Matrix(Bytes)    :  %d \n",size);
        printf("Size of Compressed Matrix(Bytes) :  %d  \n ",size_csm);
        
        free(matrix);
        free(compresses_sparse_matrix);
        
        return 0;
}
