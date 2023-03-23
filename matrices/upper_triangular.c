
#include<stdio.h>
int main()
{
    int n,i,j,e;
    printf("Enter the order of the square matrix\n");
    scanf("%d",&n);
    int no = ((n*(n+1))/2);
    int a[no],k=0;
    for ( i = 0; i < n; i++)
    {
        for ( j = 0; j < n; j++)
        {
            if(i<=j)
            {
                printf("Enter the element\n");
                scanf("%d",&e);
                a[k] = e;
                k++;
            }
            
        }
        
    }
    
    // for(i=0;i<k;i++){
    //     printf("%d\t",a[i]);
    // }
    for ( i = 0; i < n; i++)
    {
        for ( j = 0; j < n; j++)
        {
            if (i>j)
            {
                printf("%d\t",0);
            }
            else
            {
                int l = (i*(i+1)/2)+j;
                printf("%d\t",a[l]);
            }
    
        }
        printf("\n");
        
    }
    
    return 0;
}
