---
geometry: margin=3cm
header-includes:
 - \usepackage{fvextra}
 - \DefineVerbatimEnvironment{Highlighting}{Verbatim}{breaklines,commandchars=\\\{\}}
---
### Alfred Jophy
### CS27

## 1. Find Crossover Points 
Consider a list of points on a cartesian plan of the form $(x,y)$,where\newline
$x_0<x_1<x_2<...<x_n$\newline
$y_1<y_1<y_2<...<y_n$\newline
$x_0 > y_0$\newline
$x_n < y_n$\newline

A crossover point $i$ in the list is defined where\newline
$x_i > y_i$\newline
$x_{i+1} < y_{i+1}$\newline

Find all crossover points.

### Source Code
```c
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
```

### Output
```
Enter the number of points : 8
Enter the points : 
1
0

2
3

5
4

6
5

7
8

8
10

10
12

12
13


Index : 0  1  2  3  4  5  6  7  
  X   : 1  2  5  6  7  8  10  12  
  Y   : 0  3  4  5  8  10  12  13  
Crossover at 0
Crossover at 3    
```
\newpage
