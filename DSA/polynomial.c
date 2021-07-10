#include<stdio.h>
#include<stdlib.h>
struct poly
{
	int constant;
	int power;
	struct poly *next;
};



struct poly * createPoly();
void printPoly(struct poly *);
void printMenu();
struct poly * addPoly(struct poly *,struct poly *);
struct poly * subPoly(struct poly *,struct poly *);



void main()
{
    struct poly *first=NULL;
    struct poly *second=NULL;
    struct poly *temp=NULL;
    struct poly *head=NULL;
    struct poly *add=NULL;
    struct poly *subtract=NULL;
    int ch,n;
    do
    {
    	printMenu();
    	printf("\nEnter your choice   ");
    	scanf("%d",&ch);
    	if(ch==1)
    	{	
    		first=createPoly();
    	}	
    	if(ch==2)
    	{
    		second=createPoly();
    	}
    	if(ch==3)
    	{
    	    printPoly(first);
    	    printf("\n");
    	    printPoly(second);
    	}
    	if(ch==4)
    	{
    	    add=addPoly(first,second);
    	}
    	if(ch==5)
    	{
    	    subtract=subPoly(first,second);
    	}
    }while(ch!=6);
}

void printMenu()
{
    printf("\nEnter 1 for creating first polynomial");
    printf("\nEnter 2 for creating second polynomial");
    printf("\nEnter 3 for printing the polynomials");
    printf("\nEnter 4 for Adding two polynomials");
    printf("\nEnter 5 for Subtacting two polynomials");
    printf("\nEnter 6 to Exit");
}
struct poly * createPoly()
{
    struct poly *first=NULL;
    struct poly *head=NULL;
    struct poly *temp=NULL;
    int n;
    printf("\nEnter the Highest power of polynomial   ");
    scanf("%d",&n);
    while(n>=0)
    {
        temp=(struct poly *)malloc(sizeof(struct poly)*1);
        temp->next=NULL;
        printf("\nEnter const value for power of %d:  ",n);
        scanf("%d",&temp->constant);
        temp->power=n;
        if(first==NULL)
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
    printPoly(first);
    return first;
}

void printPoly(struct poly *first)
{
    struct poly *head=NULL;
    head=first;
    while(head!=NULL)
    {
        printf("%d*X^%d",head->constant,head->power);
        if(head->next!=NULL)
        {
            printf(" + ");
        }
        head=head->next;
    }
}

struct poly * addPoly(struct poly *first,struct poly *second)
{
    struct poly *add=NULL;
    struct poly *head=NULL;
    struct poly *shead=NULL;
    struct poly *temp=NULL;
    struct poly *abc=NULL;
    head=first;
    shead=second;
    if(head->power >= shead->power)
    {
        while(head!=NULL)
        {
            temp=(struct poly *)malloc(sizeof(struct poly)*1);
            temp->next=NULL; 
            if(head->power == shead->power)
            {
                temp->power=head->power;
                temp->constant=head->constant + shead->constant;
                if(add==NULL)
                {
                    add=temp;
                }
                else
                {
                    abc=add;
                    while(abc->next!=NULL)
                    {
                        abc=abc->next;
                    }
                    abc->next=temp;
                }
                shead=shead->next;
            }
            else
            {
                temp->power=head->power;
                temp->constant=head->constant;
                if(add==NULL)
                {
                    add=temp;
                }
                else
                {
                    abc=add;
                    while(abc->next!=NULL)
                    {
                        abc=abc->next;
                    }
                    abc->next=temp;
                }
            }
            head=head->next;
        }
    }
    else
    {
        while(shead!=NULL)
        {
            temp=(struct poly *)malloc(sizeof(struct poly)*1);
            temp->next=NULL; 
            if(head->power == shead->power)
            {
                temp->power=head->power;
                temp->constant=head->constant + shead->constant;
                if(add==NULL)
                {
                    add=temp;
                }
                else
                {
                    abc=add;
                    while(abc->next!=NULL)
                    {
                        abc=abc->next;
                    }
                    abc->next=temp;
                }
                head=head->next;
            }
            else
            {
                temp->power=shead->power;
                temp->constant=shead->constant;
                if(add==NULL)
                {
                    add=temp;
                }
                else
                {
                    abc=add;
                    while(abc->next!=NULL)
                    {
                        abc=abc->next;
                    }
                    abc->next=temp;
                }
            }
            shead=shead->next;
        }
    }
    printPoly(add);
    return add;
}



struct poly * subPoly(struct poly *first,struct poly *second)
{
    struct poly *sub=NULL;
    struct poly *head=NULL;
    struct poly *shead=NULL;
    struct poly *temp=NULL;
    struct poly *abc=NULL;
    head=first;
    shead=second;
    if(head->power >= shead->power)
    {
        while(head!=NULL)
        {
            temp=(struct poly *)malloc(sizeof(struct poly)*1);
            temp->next=NULL; 
            if(head->power == shead->power)
            {
                temp->power=head->power;
                temp->constant=head->constant - shead->constant;
                if(sub==NULL)
                {
                    sub=temp;
                }
                else
                {
                    abc=sub;
                    while(abc->next!=NULL)
                    {
                        abc=abc->next;
                    }
                    abc->next=temp;
                }
                shead=shead->next;
            }
            else
            {
                temp->power=head->power;
                temp->constant=head->constant;
                if(sub==NULL)
                {
                    sub=temp;
                }
                else
                {
                    abc=sub;
                    while(abc->next!=NULL)
                    {
                        abc=abc->next;
                    }
                    abc->next=temp;
                }
            }
            head=head->next;
        }
    }
    else
    {
        while(shead!=NULL)
        {
            temp=(struct poly *)malloc(sizeof(struct poly)*1);
            temp->next=NULL; 
            if(head->power == shead->power)
            {
                temp->power=head->power;
                temp->constant=head->constant - shead->constant;
                if(sub==NULL)
                {
                    sub=temp;
                }
                else
                {
                    abc=sub;
                    while(abc->next!=NULL)
                    {
                        abc=abc->next;
                    }
                    abc->next=temp;
                }
                head=head->next;
            }
            else
            {
                temp->power=shead->power;
                temp->constant=shead->constant;
                if(sub==NULL)
                {
                    sub=temp;
                }
                else
                {
                    abc=sub;
                    while(abc->next!=NULL)
                    {
                        abc=abc->next;
                    }
                    abc->next=temp;
                }
            }
            shead=shead->next;
        }
    }
    printPoly(sub);
    return sub;
}






