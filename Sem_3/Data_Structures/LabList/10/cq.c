#include<stdio.h>
#include<stdbool.h>
#define SIZE 5

int queue[10];
int front=-1,rear=-1;

bool IsEmpty()
{
  if(front==-1)
    return true;
  else
    return false;
}

bool IsFull()
{
  if((front==0 && rear==SIZE-1)||(front == rear+1))
    return true;
  else
    return false;
}


void Enqueue(int num)
{
  if(IsFull()){
    printf("\n Queue is FULL ");
    return;
  }

  if(IsEmpty())
    front++;
  
  rear=(rear+1)%SIZE;

  queue[rear]=num;
}

void Dequeue()
{
  if(IsEmpty())
  {
    printf("\n Queue is EMPTY ");
    return;
  }

  if(front==rear)
  {
    printf("\n %d removed from queue : ",queue[front]);
    front=rear=-1;
    return;
  }
  printf("\n %d removed from queue : ",queue[front]);
  front=(front+1)%SIZE;
}


void Front()
{
  printf("\n The first number in Queue is %d at index %d ",queue[front],front);
}

void Rear()
{
  printf("\n The last number in Queue is %d at index %d ",queue[rear],rear);
}

void display()
{
    int i;
    for(i=front;i%SIZE!=rear;i++)
        printf("%d ",queue[i%SIZE]); 
    printf("%d ",queue[i%SIZE]);
}

int main()
{
  int choice=1,num;

  printf(" IMPLEMENTATION OF QUEUE !");

  while(choice)
  {
    printf("\n\n 1.Enter number to queue \n 2.Delete from queue \n 3.IsEmpty \n 4.IsFull \n 5.See Front \n 6.See Rear \n 7.Display queue \n\n Enter your choice : ");
    scanf("%d",&choice);

    switch(choice)
    {
      case 1 :{
        printf("\n Enter number : ");
        scanf("%d",&num);
        Enqueue(num);
        break;
      }
      case 2 :{
        Dequeue();
        break;
      }
      case 3 :{
        bool x=IsEmpty();
        if(x==true)
          printf("\n The queue IS empty !");
        else
          printf("\n The queue IS NOT empty !");
        break;
      }
      case 4:{
        bool x=IsFull();
        if(x==true)
          printf("\n The queue IS full !");
        else
          printf("\n The queue IS NOT full !");
        break;
      }
      case 5:{
        Front();
          break;
      }
      case 6:{
        Rear();
        break;
      }
      case 7:{
        printf("The Queue is ");
        display();
        break;
      }
    }
  }
  return 0;
}
