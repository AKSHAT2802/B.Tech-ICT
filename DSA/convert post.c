#include<stdio.h>
#include<stdlib.h>
struct convert
{
    char ch;
    struct convert *next;
};

struct convert *Infix=NULL,*Postfix=NULL,*Stack=NULL;

void getString();
void printLL(struct convert *);
void InfixtoPostfix();
void setStack();
void push(char);
char pop();
void addtoPostfix(char);

int checkchar(char);

void main()
{
    struct convert *head=NULL,*temp=NULL;
    getString();
    head=Infix;
    printf("Your Infix is  ");
    printLL(head);
    setStack();
    printf("\n");
    printLL(Stack);
    InfixtoPostfix();
    printf("\n Your postfix is   ");
    printLL(Postfix);
}

void getString()
{
    char *str;
    str=(char *)malloc(sizeof(char)*30);
    printf("\nEnter your mathematical expression   ");
    scanf("%s",str);
    int i=0;
    struct convert *temp=NULL,*head=NULL;
    while(*(str+i)!='\0')
    {
        temp=(struct convert *)malloc(sizeof(struct convert)*1);
        temp->next=NULL;
        temp->ch=*(str+i);
        
        if(Infix==NULL)
        {
            Infix=temp;
        }
        else
        {
            head=Infix;
            while(head->next!=NULL)
            {
                head=head->next;
            }
            head->next=temp;
        }
        i++;
    }
}

void printLL(struct convert *a)
{
    while(a!=NULL)
    {
        printf("%c ",a->ch);
        a=a->next;
    }
}

void InfixtoPostfix()
{
    struct convert *head=NULL,*temp=NULL,*ihead=NULL;
    ihead=Infix;
    while(ihead!=NULL)
    {
        if(checkchar(ihead->ch)==0)
        {
            push(ihead->ch);
        }
        else if(checkchar(ihead->ch)==5)
        {
            addtoPostfix(ihead->ch);
        }
        else if (checkchar(ihead->ch)==4)
        {
            while(Stack->ch!='(')
            {
                addtoPostfix(pop());
            }
            char abc=pop();
        }
        else
        {
            if(checkchar(Stack->ch)<checkchar(ihead->ch))
            {
                push(ihead->ch);
            }
            else
            {
                while(checkchar(Stack->ch)>=checkchar(ihead->ch))
                {
                    addtoPostfix(pop());
                }
                push(ihead->ch);
            }
        }
        ihead=ihead->next;
    }
    while(Stack->ch!='(')
    {
        addtoPostfix(pop());
    }
}

void setStack()
{
    struct convert *temp=NULL;
    temp=(struct convert *)malloc(sizeof(struct convert)*1);
    temp->ch='(';
    temp->next=NULL;
    Stack=temp;
}

void push(char ch)
{
    struct convert *temp=NULL;
    temp=(struct convert *)malloc(sizeof(struct convert)*1);
    temp->ch=ch;
    temp->next=Stack;
    Stack=temp;
}

char pop()
{
    char c;
    struct convert *temp=NULL;
    temp=Stack;
    Stack=Stack->next;
    c=temp->ch;
    free(temp);
    return c;
}

void addtoPostfix(char ch)
{
    struct convert *temp=NULL,*head=NULL;
    temp=(struct convert *)malloc(sizeof(struct convert)*1);
    temp->ch=ch;
    temp->next=NULL;
    if(Postfix==NULL)
    {
        Postfix=temp;
    }
    else
    {
        
        head=Postfix;
        while(head->next!=NULL)
        {
            head=head->next;
        }
        head->next=temp;
    }
}

int checkchar(char ch)
{
    if (ch=='(')
    {
        return 0;
    }
    else if (ch=='+' || ch=='-')
    {
        return 1;
    }
    else if (ch=='/' || ch=='*')
    {
        return 2;
    }
    else if (ch=='^')
    {
        return 3;
    }
    else if (ch==')')
    {
        return 4;
    }
    else
    {
        return 5;
    }
}
