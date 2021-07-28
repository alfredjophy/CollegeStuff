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
                        return 1;       // return true

        }
        return 0;               //return false
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
