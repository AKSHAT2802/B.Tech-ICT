#include<stdio.h>
#include<stdlib.h>

struct Node
{
    int data;
    int p;
    struct Node *next;
};


void menu();
void Enqueue();
void print();
void DeQueue();

struct Node *Front=NULL,*Rear=NULL;

void main()
{
    int ch;
    do
    {
        menu();
        printf("\nEnter your choice    ");
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
            DeQueue();
        }
    }while(ch!=4);
}


void menu()
{
    printf("\n1. Enqueue");
    printf("\n2. dequeue");
    printf("\n3. Print queue");
    printf("\n4. Exit");
}

void Enqueue()
{
    struct Node *temp=NULL,*head=NULL;
    temp=(struct Node *)malloc(sizeof(struct Node)*1);
    printf("Enter data   ");
    scanf("%d",&temp->data);
    printf("Enter priority   ");
    scanf("%d",&temp->p);
    temp->next=NULL;
    
    if(Front==NULL)
    {
        Front=temp;
        Rear=temp;
    }
    else if (Front==Rear)
    {
        if(temp->p > Front->p)
        {
            temp->next=Front;
            Front=temp;
        }
        else if(temp->p <= Rear->p)
        {
            Rear->next=temp;
            Rear=temp;
        }
    }
    else
    {
        head=Front;
        if(temp->p > Front->p)
        {
            temp->next=Front;
            Front=temp;
        }
        else if(temp->p <= Rear->p)
        {
            Rear->next=temp;
            Rear=temp;
        }
        else
        {
            while(head->next->p >= temp->p)
            {
                head=head->next;
            }
            temp->next=head->next;
            head->next=temp;
        }
    }
}

void print()
{
    if(Front!=NULL)
    {
        struct Node *head=Front;
        while(head!=Rear)
        {
            printf("d %d p %d->",head->data,head->p);
            head=head->next;
        }
        printf("d %d p %d->",head->data,head->p);
    }
    else
    {
        printf("\nQueue is Empty\n");
    }
}


void DeQueue()
{
    if(Front!=NULL)
    {
        struct Node *temp=NULL;
        temp=Front;
        Front=Front->next;
        printf("Dequeued d %d  p %d ",temp->data,temp->p);
        free(temp);
    }
    else
    {
        printf("\nQueue is Empty\n");
    }
}