#include<stdio.h>
#include<stdlib.h>

void Enqueue();
void print();
void Dequeue();
int start=0,size=0,end=0;
int arr[100];
void main()
{
    printf("Enter the size of Queue   ");
    scanf("%d",&size);
    int ch;
    do
    {
        printf("\nEnter 1 to ENQUEUE");
        printf("\nEnter 2 to DEQUEUE");
        printf("\nEnter 3 to print QUEUE");
        printf("\nEnter 4 EXIT");
        printf("\nEnter Your Choice     ");
        scanf("%d",&ch);
        if(ch==1)
        {
           Enqueue(); 
        }
        if(ch==3)
        {
            print();
        }
        if(ch==2)
        {
            Dequeue();
        }
        
    }while(ch!=4);
}

void Enqueue()
{
    if(end<size)
    {
        printf("\nEnter the number to Enqueue    ");
        scanf("%d",&arr[end]);
        end++;
    }
    else
    {
        printf("\nSize Limit Exceeded");
    }
}

void print()
{
    for(int i=start;i<end;i++)
    {
        printf("%d  ",arr[i]);
    }
}

void Dequeue()
{
    if(start<end)
    {
        printf("\nDequeue element   %d",arr[start]);
        start++;
        size++;
    }
    else
    {
        printf("\nNo element found in queue");
    }
}





