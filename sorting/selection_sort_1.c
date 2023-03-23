#include <stdio.h>

void selection(int a[], int n)
{
    int i,j=0,small;
    for(i=0;i<n-1;i++)
    {
        small = i;
        for(j=i+1;j<n;j++)
        {
            if(a[j] < a[small]) small = j;
        }
    int temp = a[small];
    a[small] = a[i];
    a[i] = temp;
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
    selection(a,n);
    print(a,n);
    return 0;
}