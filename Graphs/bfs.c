// #include <stdio.h>
// #define MAX 100
// int front = -1;
// int rear = -1;
// int s[MAX];

// int isfull()
// {
//     if(rear == MAX-1)
//     {
//         return 1;
//     }
//     else
//         return 0;
// }

// int isempty()
// {
//     if(front == -1 || front>rear)
//         return 1;
//     else
//         return 0;
// }

// void insert(int x)
// {
//     if(!isfull())
//     {
//         if(front==-1)
//             front = 0;
//         rear++;
//         s[rear] = x;
//     }
//     else 
//         printf("Queue Overflow\n"); 
// }

// int delete()
// {
//     if(!isempty())
//     {
//         // printf("%d",s[front]);
//         int ret = s[front];
//         front++;
//         return ret;
//     }
//     else
//         {// {printf("Queue Underflow");
//         return 0;}
// }

// void bfs(int a[][100],int n,int i)
// {
//     int v[100],k,j;
//     for(k=1;k<=n;k++)
//         v[k]=0;
//     for(i=1;i<=n;i++)
//         printf("%d ",v[i]);
//     printf("%d ",i);
//     v[i]=1;
//     insert(i);
//     for(i=1;i<=n;i++)
//         printf("%d ",v[i]);
//     while(!isempty())
//     {
//         // printf("%d",1);
//         j = delete();
//         // printf("%d",j);
//         for(k=1;k<=n;k++)
//         {
//             // printf("%d %d",a[j][k],v[k]);
//             if(a[j][k]!=0 && !v[k])
//             {
//                 printf("%d",2);
//                 insert(k);
//                 printf("%d ",k);
//                 v[k]=1;
//             }
//             else continue;
//         }

//     }
// }

// int main()
// {
//     printf("Enter the no.of rows\n");
//     int r;
//     scanf("%d",&r);
//     int a[r][r],i,j;
//     for(i=1;i<=r;i++)
//     {
//         for(j=1;j<=r;j++)
//         {
//             scanf("%d",&a[i][j]);
//         }
//     }
//     bfs(a,r,1);
//     return 0;
// }

#include <stdio.h>
 
int n, i, j, visited[10], queue[10], front = -1, rear = -1;
int adj[10][10];
 
void bfs(int v)
{
    for (i = 1; i <= n; i++)
        if (adj[v][i] && !visited[i])
            queue[++rear] = i;
    if (front <= rear)
    {
        visited[queue[front]] = 1;
        bfs(queue[front++]);
    }
}
 
void main()
{
    int v;
    printf("Enter the number of vertices: ");
    scanf("%d", &n);
    for (i = 1; i <= n; i++)
    {
        queue[i] = 0;
        visited[i] = 0;
    }
    printf("Enter graph data in matrix form:    \n");
    for (i = 1; i <= n; i++)
        for (j = 1; j <= n; j++)
            scanf("%d", &adj[i][j]);
    printf("Enter the starting vertex: ");
    scanf("%d", &v);
    bfs(v);
    printf("The node which are reachable are:    \n");
    for (i = 1; i <= n; i++)
        if (visited[i])
            printf("%d\t", i);
        else
            printf("BFS is not possible. Not all nodes are reachable");
    return 0;
}