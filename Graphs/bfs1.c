#include <stdio.h>
#define max 100
int front = -1, rear = -1;
int q[max];

int isfull()
{
    if(rear == max-1) return 1;
    else return 0;
}

int isempty()
{
    if(front == -1 || front > rear) return 1;
    else return 0;
}

void insert(int x)
{
    if(!isfull())
    {
        if(front == -1) 
            front = 0;
        rear++;
        q[rear] = x;
    }
    else printf("Queue overflow\n");
}

int delete()
{
    if(!isempty())
    {
        int ret = q[front];
        front++;
        return ret;
    }
    else printf("Queue Underflow\n");
}

int main()
{
    printf("Enter the no.of vertices : ");
    int v;
    scanf("%d",&v);
    int a[v][v],i,j;
    printf("Enter the adjacency matrix\n");
    for(i=0;i<v;i++)
    {
        for(j=0;j<v;j++)
        {
            printf("a[%d][%d] : ",i,j);
            scanf("%d",&a[i][j]);
        }
    }

    int visited[v];
    for(i=0;i<v;i++) {visited[i] = 0;}

    i=0;

    for(i=0;i<v;i++)
    {
        for(j=0;j<v;j++)
        {
            printf("%d ", a[i][j]);
        }printf("\n");}
        
    printf("Enter the vertice to be started : ");
    scanf("%d",&i);
    printf("%d ",i);
    visited[i] = 1;
    insert(i);
    while(!isempty())
    {
        int d = delete();
        
        for(j=0;j<v;j++)
        {
            if(a[d][j] == 1 && visited[j] == 0)
            {
                printf("%d ",j);
                visited[j] = 1;
                insert(j);
            }
        }
    }
    return 0;
}