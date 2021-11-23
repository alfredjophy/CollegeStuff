#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

struct MATRIX {
    int **matrix;
    int rows,columns;
};
typedef struct MATRIX MATRIX;

void create_matrix(MATRIX* m,int rows,int columns){
    m->rows=rows;
    m->columns=columns;
    m->matrix=calloc(m->rows,sizeof(int*));
    for(int i=0;i<m->rows;i++)
        m->matrix[i]=calloc(m->columns,sizeof(int));
}
void free_matrix(MATRIX m){
    for(int i=0;i<m.rows;i++)
        free(m.matrix[i]);
    free(m.matrix);
}
void display_matrix(MATRIX m){
    for(int i=0;i<m.rows;i++){
        for(int j=0;j<m.columns;j++)
            printf("%d  ",m.matrix[i][j]);
    }
}

//  returns the compressed sparse matrix or NULL if the matrix is not sparse
bool check_if_sparse(MATRIX m){
    int count=0;
    for(int i=0;i<m.rows*m.columns ;i++)
        if(*(m.matrix+i) != 0)
            count++;
    return (count < m.rows*m.columns);
}
MATRIX compress_sparse_matrix(MATRIX m){
    int NNZ=0;
    for(int i=0;i<m.rows;i++)
        for(int j=0;j<m.columns;j++)
            if(m.matrix[i][j])
                NNZ++;

    MATRIX csm;

    if(NNZ >= m.rows*m.columns)
        return csm;

    int rows=NNZ+1,columns=3;
    create_matrix(&csm,rows,columns);
    csm.matrix[0][0]=m.rows;
    csm.matrix[0][1]=m.columns;
    csm.matrix[0][2]=NNZ;

    int k=1;
    for(int i=0;i<m.rows;i++)
        for(int j=0;j<m.columns;j++)
            if(m.matrix[i][j]){
                csm.matrix[k][0]=i;
                csm.matrix[k][1]=j;
                csm.matrix[k++][2]=m.matrix[i][j];
            }

    return csm;
}

int main(){
    MATRIX matrix,compressed_sparse_matrix;
    int r,c; 
    printf("Enter the number of rows for the matrix : ");
    scanf("%d",&r);
    printf("Enter the number of columns for the matrix : ");
    scanf("%d",&c);

    create_matrix(&matrix,r,c);
    
    printf("Enter the elements of the matrix :\n");
    for(int i= 0;i<matrix.rows;i++)
        for(int j=0;j<matrix.columns;j++)
            scanf("%d",&(matrix.matrix[i][j]));
    
    display_matrix(matrix);
    
    if(check_if_sparse(matrix))
        printf("The Matrix is not sparse.");
    else{
        printf("The Matrix is sparse");
        compressed_sparse_matrix=compress_sparse_matrix(matrix);
        display_matrix(compressed_sparse_matrix);
    }
    free_matrix(matrix);
    free_matrix(compressed_sparse_matrix);
    return 0;
}
