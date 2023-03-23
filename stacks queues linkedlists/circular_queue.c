#include <stdio.h>
#define MAX 10
int front = 0, rear = 0;
int queue[MAX];

int isfull()
{
    if ((rear + 1) % MAX == front)
        return 1;
    else
        return 0;
}

int isempty()
{
    if (front == rear)
        return 1;
    else
        return 0;
}

void insert(int x)
{
    if (!isfull())
    {
        rear = (rear + 1) % MAX;
        queue[rear] = x;
    }
    else
        printf("Queue Overflow\n");
}

void delete ()
{
    if (!isempty())
    {
        front = (front + 1) % MAX;
        printf("%d deleted\n", queue[front]);
    }
    else
        printf("Queue Underflow\n");
}

void display()
{
    int i;
    for (i = (front + 1) % MAX; i != (rear + 1) % MAX; i = (i + 1) % MAX)
    // for(i=front;i<rear;i++)
    {
        printf("%d ", queue[i]);
    }
}

int main()
{
    insert(10);
    insert(20);
    insert(30);
    delete ();
    //  delete();
    //  delete();
    //  delete();
    //  insert(2);
    //  insert(90);
    //  insert(8);
    //  delete();
    //  delete();
    delete ();
    insert(7);
    insert(11);
    //  insert(12);
    //  insert(13);
    //  insert(14);
    //  insert(1);
    //  insert(1);
    //  insert(1);
    //  insert(1);
    //  insert(1);
    //  insert(1);
    //  insert(1);
    display();
    return 0;
}