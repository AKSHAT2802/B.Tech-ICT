#include<stdio.h>

void InsertionSort(int arr[],int n);
void RadixSort(int arr[],int n);
void ShellSort(int arr[],int n);


int main()
{
    int choice,n,i;
    printf("\nEnter Total No. of Elements  :-    ");
    scanf("%d",&n);
    int arr[n];
    for(i=0; i<n; i++)
    {
        scanf("%d",&arr[i]);
    }
    printf("\n1. For Insertion Sort");
    printf("\n2. For Radix Sort");
    printf("\n3. For Shell Sort");
    printf("\n===========================");
    printf("\nMake Your Choice :");
    scanf("%d",&choice);
    switch(choice)
    {
    case 1:
    	printf("\nInsetion Sort\n");
        InsertionSort(arr,n);
        break;
    case 2:
    	printf("\nRadix Sort\n");
        RadixSort(arr,n);
        break;
    case 3:
        printf("\nShell Sort\n");
        ShellSort(arr,n);
        break;
    default :
        printf("\nPlease Make a Valid Choice ");
        break;
    }
    return 0;
}

void ShellSort(int arr[],int n)
{
    int i,j,stepsize;
    for(stepsize=n/2; stepsize>0; stepsize=stepsize/2)
    {
        for(i=stepsize;i<n;i++)
        {
            int temp=arr[i];
            for(j=i; j>=stepsize; j=j-stepsize)
            {
                if(temp<arr[j-stepsize])
                {
                    arr[j]=arr[j-stepsize];
                }
                else
                {
                    break;
                }
            }
            arr[j]=temp;
        }
    }
    for(i=0; i<n; i++)
    {
        printf("%d ",arr[i]);
    }

}


void RadixSort(int arr[],int n)
{
   int bucket[10][10],cnt[10];
   int i,j,k,r,NOP=0,D=1,lar,pass;
   lar=arr[0];
   for (i=1; i<n; i++)
   {
        if (arr[i]>lar)
        {
            lar=arr[i];
        }
   }
   while (lar>0)
    {
      NOP++;
      lar=lar/10;
    }
   for (pass=0; pass<NOP; pass++)
   {
      for (i=0; i<10; i++)
      {
         cnt[i]=0;
      }
      for (i=0; i<n; i++)
      {
         r=(arr[i]/D)%10;
         bucket[r][cnt[r]]=arr[i];
         cnt[r]++;
      }
      i = 0;
      for (k=0; k<10; k++)
      {
         for (j=0; j<cnt[k]; j++)
         {
            arr[i] = bucket[k][j];
            i++;
         }
      }
      D=D*10;
      printf ("After pass %d : ", pass + 1);
      for (i=0; i<n; i++)
      {
        printf ("%d ", arr[i]);
      }
      printf ("\n");
   }
}

void InsertionSort(int arr[],int n)
{
    int a,i;
    for (a=1; a<n; a++)
    {
        int key=arr[a];
        int j=a-1;
        while (key<arr[j] && j>=0)
        {
          arr[j+1]=arr[j];
          j--;
        }
        arr[j+1]=key;
  }
  for(i=0; i<n; i++)
  {
      printf("%d ",arr[i]);
  }
}
