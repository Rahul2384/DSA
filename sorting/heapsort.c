#include <stdio.h>

void heapify(int a[], int n, int i)
{
    int max = i;
    int left = 2*i+1;
    int right = 2*i+2;
    if(left<n && a[left] > a[max])
    {
        max = left;
    }
    if(right<n && a[right] > a[max])
    {
        max = right;
    }
    if(max!=i)
    {
        int temp = a[i];
        a[i] = a[max];
        a[max] = temp;

        heapify(a,n,max);
    }
}
void heapSort(int a[],int n)
{
    for(int i = n/2-1; i>=0;i--)
    {
        heapify(a,n,i);
    }

    for(int i = n-1;i>=0;i--)
    {
        int temp = a[0];
        a[0] = a[i];
        a[i] = temp;

        heapify(a,i,0);
    }
}

void print(int *a, int n)
{
    for(int i=0;i<n;i++)
    {
        printf("%d ",a[i]);
    }
}

int main()
{
    int i,n;
    printf("Enter the no.of elements : ");
    scanf("%d",&n);
    int a[n];
    printf("Enter the array elements\n");
    for(i=0;i<n;i++)
    {
        printf("a[%d] : ", i+1);
        scanf("%d",&a[i]);
    }
    heapSort(a,n);
    print(a,n);
    return 0;
}