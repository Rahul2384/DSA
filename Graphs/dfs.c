#include <stdio.h>
#define max 100
int v, a[max][max], visited[max];

void dfs(int i)
{
    printf("%d ",i);
    visited[i] = 1;
    for (int j = 0; j < v; j++)
    {
        if(a[i][j] == 1 && visited[j] == 0)
        {
            dfs(j);
        }
    }
}

int main()
{
    int i,j;
    printf("Enter the no.of vertices : ");
    scanf("%d",&v);
    printf("Enter the adjacency matrix\n");
    for(i=0;i<v;i++)
    {
        for(j=0;j<v;j++)
        {
            printf("a[%d][%d] : ",i,j);
            scanf("%d",&a[i][j]);
        }
    }

    for(i=0;i<v;i++) 
        visited[i] = 0;
    
    printf("Enter the vertice to be started : ");
    scanf("%d",&i);
    dfs(i);
    return 0;
}