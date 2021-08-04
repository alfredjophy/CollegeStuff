#include <stdio.h>

struct CORD{
        int x,y;
};
typedef struct CORD CORD;

void find_crossover(CORD* list , int length){
        for(int i=0;i<length;i++)
                if( list[i].x>list[i].y && list[i+1].x<list[i+1].y )
                        printf("\nCrossover at %d",i);
}

int main(){
        int length;
        CORD list[20];

        printf("Enter the number of points : ");
        scanf("%d",&length);
        printf("Enter the points : \n");
        for(int i=0;i<length;i++){
                scanf("%d%d",&list[i].x,&list[i].y);
                printf("\n");
        }

        printf("\nIndex : ");
        for(int i=0;i<length;i++)
                printf("%d  ",i);
        printf("\n  X   : ");
        for(int i=0;i<length;i++)
                printf("%d  ",list[i].x);
        printf("\n  Y   : ");
        for(int i=0;i<length;i++)
                printf("%d  ",list[i].y);

        find_crossover(list, length);

        return 0;
}
