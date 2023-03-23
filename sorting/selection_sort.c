#include<stdio.h>

void selectionSort(int a[], int n)
{
    int i,pos;
    for(i=n-1;i>=0;i--) 
    {
        pos = maxi(a,i);
        swape(a,i,pos);
    }
    for(i=0;i<n;i++)
    {
        printf("%d ",a[i]);
    }
}

int maxi(int a[], int n)
{
    int m=a[0],in = 0,i;
    for(i=0;i<n;i++)
    {
        if(a[i] > m) m = a[i], in=i;
    }
    return in;
}

void swape(int a[], int i, int pos)
{
    int temp = a[i];
    a[i] = a[pos];
    a[pos] = temp;
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
    selectionSort(a,n);
    return 0;
}