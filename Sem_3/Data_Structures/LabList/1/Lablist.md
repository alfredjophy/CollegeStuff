---
geometry: margin=3cm
header-includes:
 - \usepackage{fvextra}
 - \DefineVerbatimEnvironment{Highlighting}{Verbatim}{breaklines,commandchars=\\\{\}}
---
### Alfred Jophy
### CS27

## 1. Search an element in a two dimensional array

### FlowChart

![](./fl1.jpg)

\newpage

### Source Code
```c

/*
 *      To search for an element in a two dimensioanl array 
 */

#include <stdio.h>

int main(){

        int array[10][10];
        int rows,columns;

        int search_term;

        printf("Enter the number of rows and columns for the 2-D array:\n");
        scanf("%d%d",&rows,&columns);

        printf("Enter the elements of the array : \n");
        for(int i=0;i<rows;i++)
                for(int j=0;j<columns;j++)
                        scanf("%d",&array[i][j]);

        printf("\nThe 2D Array\n");
        for(int i=0;i<rows;i++){
                printf("\n");
                for(int j=0;j<columns;j++)
                        printf(" %d ",array[i][j]);
        }

        printf("\n\nEnter the number you want to search for : ");
        scanf("%d",&search_term);

        int flag=0;

        for(int i=0;i<rows;i++)
                for(int j=0;j<columns;j++)
                        if(array[i][j]==search_term)
                                flag=1,printf("Number found at row %d column %d\n",i+1,j+1);
        
        if(!flag)
                printf("Number not found in the 2-D array.\n");

        return 0;
}
```

### Output
1. ![](./1.png)

2. ![](./2.png)


