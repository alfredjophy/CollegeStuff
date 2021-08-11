#include <stdio.h>

int array[10];

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

void binarySearch(int begin,int end,int num){
    
    if(begin<end){
        printf("Not found");
        return;
    }
    int center=(begin+end)/2;
    if(array[center]==num){
        printf("Found at %d",center);
        return;
    }
    else if(array[center]<num){
        binarySearch(center+1, end,num);
    }
    else{
        binarySearch(begin,center-1, num);
    }
}

int main(){

    int num;

    printf("Enter 10 numbers: ");
    for(int i=0;i<10;i++)
        scanf("%d",&array[i]);

    printf("Enter the number to search : ");
    scanf("%d",&num);

    for(int i=0;i<10;i++)
        printf(" %d ",array[i]);
    //sort the list

    bubbleSort(array,10);

    printf("\n");
    for(int i=0;i<10;i++)
        printf(" %d ",array[i]);

    printf("\n");
    
    binarySearch(0,9,num);

    return 0;
}

