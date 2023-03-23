#include<stdio.h>
int main(int argc, char const *argv[])
{
    int n;
    printf("Enter the order of the square matrix\n");
    scanf("%d",&n);
    int no = (3*n)-2;
    int a[no],i,j,k=0;
    for ( i = 0; i < n; i++)
    {
        for ( j = 0; j < n; j++)
        {
            if(i == j || i-j == 1 || j-i == 1)
            {
                printf("Enter element\n");
                scanf("%d",&a[k]);
                k++;
            }
        }

    }

    for(i=0;i<n;i++)
    {
        for(j=0;j<n;j++)
        {
            if (i==j || i-j ==1 || j-i ==1)
            {
                int l = (i*(i+1))/2 + j;
                printf("%d\t",a[l]);
            }
            else
            {
                printf("%d\t",0);
            }
            
        }
        printf("\n");
    }    

    return 0;
}
