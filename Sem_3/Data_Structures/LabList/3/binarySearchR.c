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
//
//  returns -1 if element is not found , else returns index of the element
//
int binarySearch(int array[],int begin,int end,int num){
    
    if(begin>end)
        return -1;

    int center=begin + (begin-end)/2;
    if(array[center]==num)
        return center;
    else if(array[center]<num)
        return binarySearch(array,center+1, end,num);
    return binarySearch(array,begin,center-1, num);
}

int main(){

    int num,len;
    int array[100];
    printf("Enter 10 numbers: ");
    for(int i=0;i<len;i++)
        scanf("%d",&array[i]);

    displayArray(array,len);

    printf("Enter the number to search : ");
    scanf("%d",&num);

    bubbleSort(array,10);

    printf("\nThe sorted list\n");
    displayArray(array,len);

    printf("\n");
    
    int index=binarySearch(array,0,len,num);

    if(index == -1)
        printf("Element not found");
    else
        printf("Element found at index %d",index);

    return 0;
}

