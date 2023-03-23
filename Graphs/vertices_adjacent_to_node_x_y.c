#include<stdio.h>
int main()
{
    int n;
    scanf("%d",&n);
    int a[n][n],i,j;
    for(i=0;i<n;i++)
    {
        for(j=0;j<n;j++)
        {
            scanf("%d",&a[i][j]);
        }
    }
    int x,y,k=0;
    int b[n];
    scanf("%d %d",&x,&y);
    for(i=0;i<n;i++)
    {
        if(a[i][x]!=0 || a[i][y]!=0)
        {
            b[k++]=i;
        }
    }
    for(i=0;i<n;i++)
        printf("%d ",b[i]);
    return 0;
}