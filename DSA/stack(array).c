#include<stdio.h>
#include<stdlib.h>
int stack[10] , i=0 , ch=0;
int size = 0 , con = 0 , val,pos=-1;

void printMenu();
void push();
void pop();
void peek();
void printstack();

void main()
{
    printf("Enter the stack size  ");
    scanf("%d",&size);
    while(ch!=5)
    {
        printMenu();
        printf("\nEnter your choice   ");
        scanf("%d",&ch);
        if (ch==1)
        {
            push();
        }
        else if (ch==2)
        {
            pop();
        }
        else if (ch==3)
        {
            peek();
        }
        else if(ch==4)
        {
            printstack();
        }
    }
}

void printMenu()
{
    printf("\nEnter 1 to push an element");
    printf("\nEnter 2 to pop an element");
    printf("\nEnter 3 to peek in stack");
    printf("\nEnetr 4 to print the stack");
    printf("\nEnter 5 to QUIT");
}

void push()
{
    int a;
    if(pos==size-1)
    {
        printf("\nStack overflow\n");
    }
    else
    {
        printf("\nEnter the value to enter in stack    ");
        scanf("%d",&a);
        pos++;
        printf("%d",pos);
        stack[pos]=a;
    }
}

void pop()
{
    if (pos==-1)
    {
        printf("\nStack Underflow\n");
    }
    else
    {
        printf("\nPOPPED element from stack  : %d",stack[pos]);
        pos--;
    }
}

void printstack()
{
    for (int i=0;i<=pos;i++)
    {
        printf("\nstack[%d] -  %d",i,stack[i]);
    }
}


void peek()
{
    printf("\nTop of the stack is   : %d",stack[pos]);
}






