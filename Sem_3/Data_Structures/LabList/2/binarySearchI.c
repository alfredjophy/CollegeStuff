/* 
*   iterative binary search
*/
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
//  returns -1 if elemenent is not found in the array else returns index of the elemenent
//
int binarySearch(int array[],int len,int num){
    int begin=0;
    int end=len;

    while(begin <= end){
        int center=(end+begin)/2;

        if(array[center] == num )
            return center;
        else if(array[center] < num)
            begin=center+1;
        else
            end=center-1;
    }

    return -1;
}

int main(){
    int array[10];
    int num,len;

    printf("Enter 10 numbers: ");
    for(int i=0;i<10;i++)
        scanf("%d",&array[i]);

    printf("Enter the number to search : ");
    scanf("%d",&num);

    displayArray(array,len);

    bubbleSort(array,10);

    printf("\nThe Sorted Array\n");
    displayArray(array,len);

    printf("\n");

    int index=binarySearch(array,10,num);
    if(index==-1)
        printf("Not found");
    else
        printf("Found at %d",index);

    return 0;
}
