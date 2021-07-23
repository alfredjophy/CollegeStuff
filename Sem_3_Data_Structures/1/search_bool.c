#include <stdio.h>
#define array_size 50

int main(){

        int array[array_size];
        int search_term,number_of_elements;

        /*
         *      accept stuff
         */
        for(int i=0;i<number_of_elements;i++)
                if(search_term==array[i]){
                        printf("Element found!!");
                        return 0;
                }
        printf("Element not found!!!");
        return 0;
}
