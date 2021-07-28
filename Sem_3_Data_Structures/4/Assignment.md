---
geometry: margin=3cm
header-includes:
 - \usepackage{fvextra}
 - \DefineVerbatimEnvironment{Highlighting}{Verbatim}{breaklines,commandchars=\\\{\}}
---
### Alfred Jophy
### CS27

# Pattern Matching


##  Question
Implement Naive String Matching Algorithm

### Algorithm
1. Start
2. Accept string and pattern from the user
3. Initialize i and j with zero
4. While i < length of string and j < length of pattern , do\newline
        1. if string[i] = pattern[j] , then j++\newline
        2. else if j > 0 , then j=0\newline 
        3. i++
5. If j = length of pattern , print pattern present
6. Else , print pattern not present
7. End

### Source Code
```c
#include <stdio.h>
#include <string.h>

int is_pattern_present(char* str, char* pttr){
        int str_len=strlen(str);
        int pttr_len=strlen(pttr);
        int i,j;

        for (i=0;i<str_len-pttr_len;i++){
                for(j=0;j<pttr_len;j++){
                        if(str[i+j]!=pttr[j]){
                                break;
                        }
                }
                if(j==pttr_len)
                        return 1;

        }
        return 0;
}

int main(){

        char string[20],pattern[20];

        printf("Enter the string : ");
        scanf("%s",string);
        printf("Enter the pattern to search for : ");
        scanf("%s",pattern);

        printf("The String  : %s\n",string);
        printf("The Pattern : %s\n",pattern);

        if(is_pattern_present(string, pattern)){
                printf("The pattern is present in the string.");
                return 0;
        }

        printf("The pattern is not present in the string.");

        return 0;
}
```

### Output
#### 1. 
```
Enter the string : AbcHHDefjkHEYxzswa
Enter the pattern to search for : HEY
The String  : AbcHHDefjkHEYxzswa
The Pattern : HEY
The pattern is present in the string.

```

#### 2.
```
Enter the string : AbcHHDefjkHEYxzswa
Enter the pattern to search for : Hello
The String  : AbcHHDefjkHEYxzswa
The Pattern : Hello
The pattern is not present in the string.

```
