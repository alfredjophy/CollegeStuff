#include <stdio.h>
#include <stdbool.h>
#include <string.h>

bool is_pattern_present(char* str, char* pttr){
        int i=0,j=0;
        
        int str_len=strlen(str);
        int pttr_len=strlen(pttr);
        
        while(i<str_len && j<pttr_len){
                if( str[i] == pttr[j])
                        j++;
                else if(j)
                        j=0;
                i++;

        }

        return (j==pttr_len);
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
