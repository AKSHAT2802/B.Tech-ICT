#include<stdio.h>
#include<stdlib.h>
struct Node
{
    int data;
    struct Node *next;
};
void printMenu(void);
struct Node * createLL(int);
void printLL(struct Node *);
struct Node * InsertFirst(struct Node *);
struct Node * InsertLast(struct Node *);
void countNodes(struct Node *);
struct Node * reverseLL(struct Node *);
struct Node * concatenateLL(struct Node *,struct Node *);
struct Node * copyLL(struct Node *);
struct Node * evenLL(struct Node *);
struct Node * oddLL(struct Node *);


void main()
{
    struct Node *first=NULL;
    struct Node *temp=NULL;
    struct Node *head=NULL;
    struct Node *second=NULL;
    struct Node *copy=NULL;
    struct Node *even=NULL;
    struct Node *odd=NULL;
    int n,value;
    int ch;
    do
    {
        printMenu();
        printf("\nEnter your choice   ");
        scanf("%d",&ch);
        if(ch == 1)
        {
            printf("\nEnter the number of Nodes   ");
            scanf("%d",&n);
            first = createLL(n);
        }
        else if (ch==2)
        {
            printLL(first);        
        }
        else if (ch==3)
        {
            first=InsertFirst(first);
        }
        else if (ch==4)
        {
            first=InsertLast(first);
        }
        else if (ch==5)
        {
            countNodes(first);
        }
        else if (ch==6)
        {
            second=reverseLL(first);
        }
        else if (ch==7)
        {
            first=concatenateLL(first,second);
        }
        else if (ch==8)
        {
            copy=copyLL(first);
        }
        else if (ch==9)
        {
            even=evenLL(first);
            odd=oddLL(first);
        }
    }while(ch!=10);
}
struct Node * createLL(int n)
{
    struct Node *first=NULL;
    struct Node *temp=NULL;
    struct Node *head=NULL;
    while (n>0)
    {
        temp=(struct Node *)malloc(sizeof(struct Node)*1);
        temp->next=NULL;
        printf("\nEnter data   ");
        scanf("%d",&(temp->data));
        if (first==NULL)
        {
            first=temp;
        }
        else
        {
            head=first;
            while(head->next!=NULL)
            {
                head=head->next;
            }
            head->next=temp;
        }
        n--;
    }
    return first;
}
void printMenu()
{
    printf("\nEnter 1 for creating a link list");
    printf("\nEnter 2 for printing a link list");
    printf("\nEnter 3 for inserting node at first");
    printf("\nEnter 4 for inserting node at last");
    printf("\nEnter 5 for counting number of Nodes");
    printf("\nEnter 6 for printing List in reverse order");
    printf("\nEnter 7 for concatenate two Linked List");
    printf("\nEnter 8 for making a copy of Link List");
    printf("\nEnter 9 for splitting Link List");
}
void printLL(struct Node *head)
{
    struct Node *temp=NULL;
    temp=head;
    while(temp!=NULL)
    {
        printf("%d ->",temp->data);
        temp=temp->next;
    }
}
struct Node * InsertFirst(struct Node *first)
{ 
    struct Node *temp=NULL;
    struct Node *head=NULL;
    temp=(struct Node *)malloc(sizeof(struct Node)*1);
    temp->next=NULL;
    head=first;
    temp->next=head;
    printf("\nEnter the value for the Node  ");
    scanf("%d",&(temp->data));
    first=temp;
    return first;
}
struct Node * InsertLast(struct Node *first)
{
    struct Node *head=NULL;
    struct Node *temp=NULL;
    temp=(struct Node *)malloc(sizeof(struct Node));
    temp->next=NULL;
    printf("\nEnter the value for the Node  ");
    scanf("%d",&(temp->data));
    head=first;
    while (head->next!=NULL)
    {
        head=head->next;
    }
    head->next=temp;
    return first;
}
void countNodes(struct Node *first)
{
    int a=0;
    struct Node *head=NULL;
    head=first;
    while(head!=NULL)
    {
        a++;
        head=head->next;
    }
    printf("\nThe Numbers of nodes in the giver LL is :-  %d\n",a);
}
struct Node * reverseLL(struct Node * first)
{
    struct Node *second=NULL;
    struct Node *head=NULL;
    struct Node *temp=NULL;
    struct Node *shead=NULL;
    head=first;
    while(head!=NULL)
    {
        temp=(struct Node *)malloc(sizeof(struct Node)*1);
        temp->next=NULL;
        temp->data=head->data;
        if (second==NULL)
        {
            second=temp;
        }
        else
        {
            temp->next=second;
            second=temp;
        }
        head=head->next;
    }
    printLL(second);
    return second;
}
struct Node * concatenateLL(struct Node *first,struct Node *second)
{
    struct Node * head=NULL;
    head=first;
    while(head->next!=NULL)
    {
        head=head->next;
    }
    head->next=second;
    return first;
}
struct Node * copyLL(struct Node *first)
{
    struct Node *copy=NULL;
    struct Node *temp=NULL;
    struct Node *head=NULL;
    struct Node *chead=NULL;
    head=first;
    while(head!=NULL)
    {
        temp=(struct Node *)malloc(sizeof(struct Node)*1);
        temp->next=NULL;
        temp->data=head->data;
        if(copy==NULL)
        {
            copy=temp;
        }
        else
        {
            chead=copy;
            while(chead->next!=NULL)
            {
                chead=chead->next;
            }
            chead->next=temp;
        }
        head=head->next;
    }
    printLL(copy);
    return copy;
}

struct Node * evenLL(struct Node *first)
{
    struct Node *even=NULL;
    struct Node *head=NULL;
    struct Node *temp=NULL;
    struct Node *ehead=NULL;
    head=first;
    while(head!=NULL)
    {
        if ((head->data) % 2 == 0)
        {
            temp=(struct Node *)malloc(sizeof(struct Node)*1);
            temp->next=NULL;
            temp->data=head->data;
            if(even==NULL)
            {
                even=temp;
            }
            else
            {
                ehead=even;
                while(ehead->next!=NULL)
                {
                    ehead=ehead->next;
                }
                ehead->next=temp;
            }
        }
        head=head->next;
    }
    printf("\n Even LL \n")
    printLL(even);
    return even;
}




struct Node * oddLL(struct Node *first)
{
    struct Node *odd=NULL;
    struct Node *head=NULL;
    struct Node *temp=NULL;
    struct Node *ohead=NULL;
    head=first;
    while(head!=NULL)
    {
        if ((head->data) % 2 == 1)
        {
            temp=(struct Node *)malloc(sizeof(struct Node)*1);
            temp->next=NULL;
            temp->data=head->data;
            if(odd==NULL)
            {
                odd=temp;
            }
            else
            {
                ohead=odd;
                while(ohead->next!=NULL)
                {
                    ohead=ohead->next;
                }
                ohead->next=temp;
            }
        }
        head=head->next;
    }
    printf("\nOdd LL \n");
    printLL(odd);
    return odd;
}






