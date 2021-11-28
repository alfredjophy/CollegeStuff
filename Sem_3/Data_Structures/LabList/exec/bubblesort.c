// bubble sort
#include <stdio.h>

void bubbleSort(int array[],int len){

    for(int i=0;i<len;i++)
        for(int j=0;j<len-i-1;j++)
        {
            if(array[j] > array[j+1]){
                
                // swap array[i] array[i+1]
                int temp=array[j];
                array[j]=array[j+1];
                array[j+1]=temp;
            }
        }
}

int main(){
    
    int array[10];
    // 10 integers
    /*
     *
     * TODO : enter number of elements
     *
     *
     */
    printf("Enter 10 numbers: ");
    for(int i=0;i<10;i++)
        scanf("%d",&array[i]);

    bubbleSort(array,10);

    for(int i=0;i<10;i++)
        printf("%d ",array[i]);

    return 0;
}
