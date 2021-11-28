#include <stdio.h>

void bubbleSort(int array[],int len){
    for(int i=0;i<len;i++)
        for(int j=0;j<len-i-1;j++)
            if(array[j] > array[j+1]){
                int temp=array[j];
                array[j]=array[j+1];
                array[j+1]=temp;
            }
}

void displayArray(int array[],int len){
    for(int i=0;i<len;i++)
        printf(" %d ",array[i]);
}

int binarySearch(int array[],int begin,int end,int num){
    
    if(begin>end)
        return -1;

    int center=(begin + end)/2;
    if(array[center]==num)
        return center;
    else if(array[center]<num)
        return binarySearch(array,center+1, end,num);
    return binarySearch(array,begin,center-1, num);
}

int main(){

    int num;
    int array[10];
    printf("Enter 10 numbers: ");

    for(int i=0;i<10;i++)
        scanf("%d",&array[i]);

    displayArray(array,10);

    printf("\nEnter the number to search : ");
    scanf("%d",&num);

    bubbleSort(array,10);

    printf("\nThe sorted list\n");
    displayArray(array,10);

    printf("\n");
    
    int index=binarySearch(array,0,10,num);

    if(index == -1)
        printf("Element not found");
    else
        printf("Element found at index %d",index);

    return 0;
}

