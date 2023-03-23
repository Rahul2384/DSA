#include<stdio.h>
#include<stdlib.h>
int main()
{
    int n;
    printf("Enter the n value : ");
    scanf("%d",&n);
    int *p = (int *)malloc(n*sizeof(int));
    int i;
    printf("Enter elements\n");
    for(i=0;i<n;i++)
    {
        scanf("%d",(p+i));
    }
    printf("Elements are\n");
    for(i=0;i<n;i++)
    {
        printf("%d\t",*(p+i));
    }
    printf("\n%d\n",sizeof(*p));
    int s;
    printf("Enter the changed size : ");
    scanf("%d",&s);
    p = (int *)realloc(p,sizeof(int));
    // printf("\n%d\n",sizeof(p));
    for(i=0;i<s;i++)
    {
        scanf("%d",(p+i));
    }
    for(i=0;i<s;i++)
    {
        printf("%d\t",*(p+i));
    }
    free(p);
    return 0;
}