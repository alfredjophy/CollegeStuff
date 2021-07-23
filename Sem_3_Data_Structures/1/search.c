#include <stdio.h>
#include <stdlib.h>

int main (){

        int array_size,search_term;
        
        printf("Enter size of array : ");
        scanf("%d",&array_size);
        
        int *array=calloc(array_size,sizeof(int));
        
        printf("Enter the elements : \n");
        for(int i=0;i<array_size;++i)
                scanf("%d",&array[i]);
        
        printf("Enter the number to search for : ");
        scanf("%d",&search_term);
        
        for(int i=0;i<array_size;++i)
                if(search_term==array[i]){
                        printf("The number you searched for is at position %d index %d \n",i+1,i);
                        break;
                }
        free(array);
        return 0;
}
