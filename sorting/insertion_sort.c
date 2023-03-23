#include <stdio.h>

void insertionsort(int a[], int n)
{
    int i,j,key;
    for(i=1;i<n;i++)
    {
        key = a[i];
        j = i-1;
        while(j>=0 && a[j]>=key)
        {
            a[j+1] = a[j];
            j--;
        }
        a[j+1] = key;
    }
}

void print(int a[], int n)
{
    for(int i =0;i<n;i++)
    {
        printf("%d ",a[i]);
    }
}

int main()
{
    printf("Enter the no.of elements : ");
    int i,n;
    scanf("%d",&n);
    int a[n];
    printf("Enter the array elements\n");
    for(i=0;i<n;i++)
    {
        scanf("%d",&a[i]);
    }
    insertionsort(a,n);
    print(a,n);
    return 0;
}