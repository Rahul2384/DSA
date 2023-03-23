#include<stdio.h>
int main(int argc, char const *argv[])
{
    int r,c,sr=0,er=r-1,sc=0,ec=c-1;
    printf("Enter the no.of rows and columns\n");
    scanf("%d %d",&r,&c);
    int a[r][c],i,j,count=1;
    while (sr<=er && sc<=ec)
    {
        for(i=sc;i<=ec;i++)
        {
            a[sr][i] = count;
            count++;
        }
        for(i=sr+1;i<=er;i++)
        {
            a[i][ec] = count;
            count++;
        }
        for(i=ec-1;i>=sc;i--)
        {
            a[er][i] = count;
            count++;
        }
        for(i=er-1;i>sr;i--)
        {
            a[i][sr] = count;
            count++;
        }
        sr++;
        sc++;
        er--;
        ec--;
    }
    for(i=0;i<r;i++)
    {
        for(j=0;j<c;j++)
        {
            printf("%d\t",a[i][j]);
        }
        printf("\n");
    }
    
    return 0;
}
