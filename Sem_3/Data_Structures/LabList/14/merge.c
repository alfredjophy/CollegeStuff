#include <stdio.h>

int main(){
    int a[10],b[10],m[20];
    
    printf("Enter the first sorted list  (10 numbers) : ");
    for(int i=0;i<10;i++)
        scanf("%d",&a[i]);
    
    printf("Enter the second sorted list (10 numbers) : ");
    for(int i=0;i<10;i++)
        scanf("%d",&b[i]);

    int a_i=0,b_i=0,m_i=0;
    
    while(m_i<20){
        if(a[a_i] < b[b_i])
            m[m_i++]=a[a_i++];
        else
            m[m_i++]=b[b_i++];

        if(a_i==10){
            while(b_i<10)
                m[m_i++]=b[b_i++];
            break;
        }

        if(b_i==10){
            while(a_i<10)
                m[m_i++]=a[a_i++];
            break;
        }
    }
    
    printf("     The Merged List                      : ");
    for(int i=0;i<20;i++){
        printf("%d ",m[i]);
    }
    return 0;
}
