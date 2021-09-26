---
geometry: margin=2cm
header-includes:
 - \usepackage{fvextra}
 - \DefineVerbatimEnvironment{Highlighting}{Verbatim}{breaklines,commandchars=\\\{\}}
---

## GROUP 7
#### Members

    1. AKSHAI. M K
    2. ALFRED JOPHY
    3. ALWIN VARGHESE T
    4. AMAL JOSHY

# Assignment 2

### Source Code
```c
#include <stdio.h>
#include <string.h>

#define SIZE_OF_CONTACT_LIST 100

//*********************************************

int substring_search(char pttr[],char str[]){
    int str_len=strlen(str);
    int pttr_len=strlen(pttr);

    for (int i=0;i<=str_len-pttr_len;i++){
        int j=0;
        for(;j<pttr_len;j++)
            if(str[i+j]!=pttr[j])
                break;
        
        if(j==pttr_len)
        return 1;       // return true

    }
    return 0;               //return false
}

// ********************************************
struct CONTACT {
    char number[13];
    char name[50];
    char email[25];
    char DOB[12];
};
typedef struct CONTACT CONTACT;

CONTACT List[SIZE_OF_CONTACT_LIST];
int last_pos=0;

void add_contact(CONTACT c){
    int pos=last_pos;
    for(int i=0;i<last_pos;i++)
        if(strcasecmp(List[i].name,c.name)>0)
            pos=i;
    for(int i=last_pos;i>pos;i--)
        List[i]=List[i-1];

    List[pos]=c;
    last_pos++;
}

void delete_contact(int contact_index){
    CONTACT temp = List[contact_index];

    for(int i=contact_index;i<last_pos;i++)
        List[i]=List[i+1];

    last_pos--;
}

void edit_contact(CONTACT edited_contact,int index){
    List[index]=edited_contact;
}

void display_contact(CONTACT C){
    printf("\n-----------------------------------------------------\n");
    printf("\tName         : %s\n",C.name);
    printf("\tPhone Number : %s\n",C.number);
    printf("\tEmail        : %s\n",C.email);
    printf("\tBirthday     : %s\n",C.DOB);
    printf("-----------------------------------------------------\n");
}

int search_contact_by_name(char name[]){
    for(int i=0;i<last_pos;i++)
        if( substring_search(name,List[i].name))
        return i;
    return -1;
}

int search_contact_by_number(char number[]){
    for(int i=0;i<last_pos;i++)
        if( strcmp(number,List[i].number)==0)
        return i;
    return -1;
}

void accept_contact_details(CONTACT *c){
    printf("\nEnter name : ");
    scanf(" %[^\n]s",(c->name));
    printf("Enter phone number : ");
    scanf("%s",(c->number));
    printf("Enter email : ");
    scanf(" %s",(c->email));
    printf("Enter birthday : ");
    scanf(" %s",(c->DOB));
}

//**************************************************************

void display_contacts(CONTACT list[],int length){
    printf("\nContact List\n\n");
    for(int i=0;i<length;i++){
        printf("%d )",i+1);
        display_contact(list[i]);
        printf("\n");
    }
}

//***************************************************************

void menu_display(){
    printf("\n1. Add Contact");
    printf("\n2. Delete Contact");
    printf("\n3. Edit Contact");
    printf("\n4. Display Contacts");
    printf("\n5. Search Contact By Name");
    printf("\n6. Search Contact By Number");
    printf("\n0. Exit\n");
    printf("Enter option : ");
}

void menu(){
    int choice=1;

    while(choice){

        menu_display();
        scanf("%d",&choice);

        switch(choice){

            case 1: {
                CONTACT C;
                accept_contact_details(&C);
                add_contact(C);
            }
                break;

            case 2: {
                int index;
                printf("Enter Index : ");
                scanf("%d",&index);
                delete_contact(index-1);
            }
                break;

            case 3: {
                int index;

                printf("Enter Index : ");
                scanf("%d",&index);
                CONTACT C;
                accept_contact_details(&C);

                // display original contact
                printf("\nOriginal Contact : ");
                display_contact(List[index-1]);

                // display edited contact
                printf("\nModified Contact : ");
                display_contact(C);

                char c;
                printf("Save edited contact?(Y/N)? ");
                scanf(" %c",&c);
                if(c=='y'||c=='Y')
                    edit_contact(C,index-1);
            }
                break;

            case 4: display_contacts(List,last_pos);
                break;

            case 5: {
                char name[50];
                printf("Enter Name : ");
                scanf("%s",name);

                int index=search_contact_by_name(name);
                if(index == -1){
                    printf("Not Found");
                    break;
                }
                printf("%d )",index+1);
                display_contact(List[index]);

            } 
                break;

            case 6: {

                char number[50];
                printf("Enter number : ");
                scanf("%s",number);

                int index=search_contact_by_number(number);
                if(index == -1){
                    printf("Not Found");
                    break;
                }
                printf("%d )",index+1);
                display_contact(List[index]);

            }
                break;
        }
    }
}

void init(){
    FILE * f=fopen("contacts.dat","rb");
    if(!f)
        return;
    while(fread(&List[last_pos++],sizeof(CONTACT),1,f));
    last_pos--;
    fclose(f);
}

void conl(){
    remove("contacts.dat");    
    FILE* f=fopen("contacts.dat","wb");
    fwrite(List,sizeof(CONTACT),last_pos,f);
    fclose(f);
}

int main(void) {
    init();    
    menu();
    conl();

    return 0;
}
```

### Output

![](./pic/1.png)
![](./pic/2.png)
![](./pic/3.png)
![](./pic/4.png)
![](./pic/5.png)
![](./pic/6.png)
![](./pic/7.png)
![](./pic/8.png)
![](./pic/9.png)
![](./pic/10.png)
![](./pic/11.png)
![](./pic/12.png)
