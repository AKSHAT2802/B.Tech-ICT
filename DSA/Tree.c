#include<stdio.h>
#include<malloc.h>

struct Btree
{
    struct Btree *left;
    int data;
    struct Btree *right;
};


void menu(void);
struct Btree * InsertNode(struct Btree *,int);
void InOrderT(struct Btree *);
void PostOrderT(struct Btree *);
void PreOrderT(struct Btree *);
void SearchNode(struct Btree *,int);

int main()
{
    struct Btree *tree = NULL;
    int n,data;
    while(n != 6)
    {
        menu();
        scanf("%d",&n);
        switch(n)
        {
        case 1:
            printf("\nEnter value:");
            scanf("%d",&data);
            tree = InsertNode(tree,data);
            break;
        case 2:
            printf("\nInOrder Traversal: ");
            InOrderT(tree);
            printf("\n");
            break;
        case 3:
            printf("\nPreOrder Traversal: ");
            PreOrderT(tree);
            break;
        case 4:
            printf("\n PostOrder Traversal: ");
            PostOrderT(tree);
            break;
        case 5:
            printf("\nEnter Element: ");
            scanf("%d",&data);
            SearchNode(tree,data);
            break;
        case 6:
            break;
        default :
            printf("\nPlease make a valid choice");
            break;
        }

    }
    return 0;
}

void menu()
{
    printf("\n1.Insert");
    printf("\n2.InOrder");
    printf("\n3.PreOrder");
    printf("\n4.PostOrder");
    printf("\n5.SearchNode");
    printf("\n6.End program");
    printf("\nEnter your choice: ");
}

struct Btree * InsertNode(struct Btree *tree,int n)
{
    struct Btree *temp = NULL , *head = NULL, *parent = NULL;
    temp = (struct Btree *)malloc(sizeof(struct Btree)*1);
    temp->data = n;
    temp->left = NULL;
    temp->right = NULL;
    if(tree == NULL)
    {
        tree = temp;
    }
    else
    {
        head = tree;
        while(head != NULL)
        {
            parent = head;
            if(n < head->data)
            {
                head = head->left;
            }
            else
            {
                head = head->right;
            }
        }
        if(n < parent->data)
        {
            parent->left = temp;
        }
        else
        {
            parent->right = temp;
        }

    }
    return tree;
}

void InOrderT(struct Btree *tree)
{
    while(tree!=NULL)
    {
        InOrderT(tree->left);
        printf("%d->",tree->data);
        InOrderT(tree->right);
        return;
    }
}

void PostOrderT(struct Btree *tree)
{
    while(tree!=NULL)
    {
        PostOrderT(tree->left);
        PostOrderT(tree->right);
        printf("%d->",tree->data);
        return;
    }
}

void PreOrderT(struct Btree *tree)
{
    while(tree!=NULL)
    {
        printf("%d->",tree->data);
        PreOrderT(tree->left);
        PreOrderT(tree->right);
        return;
    }
}

void SearchNode(struct Btree *tree,int data)
{
    struct Btree *head = tree;
    while(head->data != data)
    {
      if(head->data > data)
        {
            head = head->left;
        }

      else
      {
         head = head->right;
      }


      if(head == NULL)
      {
          printf("\nNot found");
         return;
      }
   }
    printf("\nElement %d is present",data);
}
