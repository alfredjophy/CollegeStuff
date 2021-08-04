---
geometry: margin=3cm
header-includes:
 - \usepackage{fvextra}
 - \DefineVerbatimEnvironment{Highlighting}{Verbatim}{breaklines,commandchars=\\\{\}}
---
### Alfred Jophy
### CS27

# <Ttitle>


## 1. Question
        
Validate ISBN-13 and ISBN-10 codes.

### Source Code
```c
#include <stdio.h>
#include <stdbool.h>

bool validateISBN_13(char ISBN[]){
        int s=0;
        for(int i=0;i<13;i++)
                s+= (ISBN[i]-'0') + 2*(ISBN[i]-'0')*(i%2) ; 

        return !(s%10);
}

bool validateISBN_10(char ISBN[]){

        int s=0;
        for(int i=0;i<10;i++)
                s+=(11-i-1)*(ISBN[i]-'0');
        if ( ISBN[9]=='1' && ISBN[10] == '0')
                s+=9;

        return !(s%11);
}

int main(){
        
        printf("\t\t ISBN VALIDATOR\n");
        printf("\t\t\b*****************\n\n");

        printf("1. ISBN-13 validation\n");
        printf("2. ISBN-10 Validation\n");

        int c;

        printf("\nEnter selection : \n");
        scanf("%d",&c);

        char ISBN[15];
        
        printf("Enter the ISBN : ");
        scanf("%s",ISBN);
        
        bool isValid;

        if(c==1)
                isValid=validateISBN_13(ISBN);     
        else 
                isValid=validateISBN_10(ISBN);

        
        if(isValid)
                printf("The ISBN is valid.");
        else
                printf("The ISBN is invalid.");

        return 0;
}
```

### Output


#### 1
```
		ISBN VALIDATOR
		*****************

1. ISBN-13 validation
2. ISBN-10 Validation

Enter selection : 
1
Enter the ISBN : 9781861978769
The ISBN is valid.         
```
#### 2.

```
		ISBN VALIDATOR
		*****************

1. ISBN-13 validation
2. ISBN-10 Validation

Enter selection : 
1
Enter the ISBN : 9781861978760
The ISBN is invalid   
```
\newpage

#### 3.
```
		ISBN VALIDATOR
	        *****************

1. ISBN-13 validation
2. ISBN-10 Validation

Enter selection : 
2
Enter the ISBN : 08044295710
The ISBN is valid.   
```
### 4.
```
		ISBN VALIDATOR
	        *****************

1. ISBN-13 validation
2. ISBN-10 Validation

Enter selection : 
2
Enter the ISBN : 0804429579
The ISBN is invalid.  
```
