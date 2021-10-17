#include <stdio.h>
#include <stdlib.h>

struct MATRIX {
    int **matrix;
    int rows,columns;
};
typedef struct MATRIX MATRIX;

void create_matrix(MATRIX* m){
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
MATRIX* compress_sparse_matrix(MATRIX m){
    int NNZ=0;
    for(int i=0;i<m.rows;i++)
        for(int j=0;j<m.columns;j++)
            if(m.matrix[i][j])
                NNZ++;
    if(NNZ >= m.rows*m.columns)
        return NULL;

    MATRIX *csm=calloc(1,sizeof(MATRIX));
    csm->rows=NNZ+1,csm->columns=3;
    create_matrix(csm);
    csm->matrix[0][0]=m.rows;
    csm->matrix[0][1]=m.columns;
    csm->matrix[0][2]=NNZ;

    int k=1;
    for(int i=0;i<m.rows;i++)
        for(int j=0;j<m.columns;j++)
            if(m.matrix[i][j]){
                csm->matrix[k][0]=i;
                csm->matrix[k][1]=j;
                csm->matrix[k++][2]=m.matrix[i][j];
            }

    return csm;
}

int main(){
    MATRIX matrix,*compressed_sparse_matrix;
    
    printf("Enter the number of rows for the matrix : ");
    scanf("%d",&(matrix.rows));
    printf("Enter the number of columns for the matrix : ");
    scanf("%d",&(matrix.columns));

    create_matrix(&matrix);
    
    printf("Enter the elements of the matrix :\n");
    for(int i= 0;i<matrix.rows;i++)
        for(int j=0;j<matrix.columns;j++)
            scanf("%d",&(matrix.matrix[i][j]));
    
    display_matrix(matrix);
    
    compressed_sparse_matrix=compress_sparse_matrix(matrix);
    if(!compressed_sparse_matrix)
        printf("The Matrix is not sparse.");
    else{
        printf("The Matrix is sparse");
        display_matrix(*compressed_sparse_matrix);
    }
    free_matrix(matrix);
    free_matrix(*compressed_sparse_matrix);
    return 0;
}
