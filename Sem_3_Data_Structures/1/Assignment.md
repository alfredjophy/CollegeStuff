---
geometry: margin=3cm
header-includes:
 - \usepackage{fvextra}
 - \DefineVerbatimEnvironment{Highlighting}{Verbatim}{breaklines,commandchars=\\\{\}}
---
### Alfred Jophy
### CS27

# Linear Search


## Question
Implement linear search

### Source Code
```c
#include <stdio.h>
#include <stdlib.h>

int main (){

        int array_size,search_term;
        
        printf("Enter size of array : ");
        scanf("%d",&array_size);
        
        int *array=calloc(array_size,sizeof(int));
        
        printf("Enter the elements : \n");
        for(int i=0;i<array_size;++i)
                scanf("%d",&array[i]);
        
        printf("Enter the number to search for : ");
        scanf("%d",&search_term);
        
        for(int i=0;i<array_size;++i)
                if(search_term==array[i]){
                        printf("The number you searched for is at position %d index %d \n",i+1,i);
                        break;
                }
        free(array);
        return 0;
}
```

### Output
```
Enter size of array : 10
Enter the elements : 
7
6
3
9
0
1
5
6
3
8
Enter the number to search for : 1
The number you searched for is at position 6 index 5

```
