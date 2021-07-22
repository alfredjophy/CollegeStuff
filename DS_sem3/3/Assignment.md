---
geometry: margin=3cm
header-includes:
 - \usepackage{fvextra}
 - \DefineVerbatimEnvironment{Highlighting}{Verbatim}{breaklines,commandchars=\\\{\}}
---
### Alfred Jophy
### CS27

# <Ttitle>

## 1. Find Crossover Points 
Consider a list of points on a cartesian plan of the form $(x,y)$,where\newline
$x_0<x_1<x_2<...<x_n$\newline
$y_1<y_1<y_2<...<y_n$\newline
$x_0 > y_0$\newline
$x_n < y_n$\newline

A crossover point $i$ in the list is defined where\newline
$x_i > y_i$\newline
$x_{i+1} < y_{i+1}$\newline

### Source Code
```c
#include <stdio.h>

struct CORD{
        int x,y;
};
typedef struct CORD CORD;

void find_crossover(CORD* list , int length){
        for(int i=2;i<length;i++)
                if( list[i].x>list[i].y && list[i+1].x<list[i+1].y )
                        printf("\nCrossover at %d",i);
}

int main(){
        const int length=8;
        CORD list[length];
        printf("Enter list elements : \n");
        for(int i=0;i<length;i++)
                scanf("%d %d",&list[i].x,&list[i].y);
        
        printf("\nIndex : ");
        for(int i=0;i<length;i++)
                printf("%d  ",i);
        printf("\n  X   : ");
        for(int i=0;i<length;i++)
                printf("%d  ",list[i].x);
        printf("\n  Y   : ");
        for(int i=1;i<length;i++)
                printf("%d  ",list[i].y);

        find_crossover(list, length);

        return 0;
}
```

### Output

\newpage
