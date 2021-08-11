// iterative binary search
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

int binarySearch(int array[],int len,int num){
    int begin=0;
    int end=len-1;

    while(begin < end){
        int center=(begin+end)/2;

        if(array[center] == num )
            return center;
        else if(array[center] < num){
            begin=center+1;
        }
        else{
            end=center-1;
        }
    }

    if(!(begin<end))
        return -1;
}

int main(){
    int array[10];
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

    // binary search
    int index=binarySearch(array,10,num);
    if(index==-1){
        printf("Not found");
    }
    else{
        printf("Found at %d",index);
    }

    return 0;
}
