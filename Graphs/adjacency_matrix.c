#include<stdio.h>
// void matrix(int mat[][10],int i, int j)
// {
//     mat[i][j]=1;
// }
int main()
{
    printf("Enter the no.of vertices:");
    int v;
    scanf("%d",&v);
    int mat[v][v];
    for(int i=0;i<v;i++)
    {
        for(int j=0;j<v;j++)
        {
            mat[i][j]=0;
        }
    }
    printf("Enter the edges\n");
    int c=1,x,y;
    while(c!=0)
    {
        scanf("%d %d",&x,&y);
        // matrix(mat,x,y);
        mat[x][y]=1;
        printf("c:");
        scanf("%d",&c);
    }
    for(int i=0;i<v;i++)
    {
        for(int j=0;j<v;j++)
        {
            printf("%d ",mat[i][j]);
        }
        printf("\n");
    }
}