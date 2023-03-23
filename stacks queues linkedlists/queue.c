
#include <stdio.h>
#define MAX 100
int front = -1;
int rear = -1;
int s[MAX];

int isfull()
{
    if(rear == MAX-1)
    {
        return 1;
    }
    else
        return 0;
}

int isempty()
{
    if(front == -1 || front>rear)
        return 1;
    else
        return 0;
}

void insert(int x)
{
    if(!isfull())
    {
        if(front==-1)
            front = 0;
        rear++;
        s[rear] = x;
    }
    else
        printf("Queue Overflow\n");
}

void delete()
{
    if(!isempty())
    {
        // printf("%d",s[front]);
        front++;
    }
    else
        printf("Queue Underflow");
}

void print()
{
    for(int i = front; i<=rear;i++)
    {
        printf("%d ",s[i]);
    }
}

int main()
{
    insert(10);
    insert(20);
    insert(30);
    delete();
    insert(40);
    delete();
    print();
    return 0;
}
