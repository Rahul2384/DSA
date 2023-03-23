
#include <stdio.h>
int MAX = 100;
int top = -1;

typedef struct
{
    int ele;
    int max;
}stack;
stack s[100];

int isfull()
{
    if(top == MAX-1)
        return 1;
    else
        return 0;
}

int isempty()
{
    if(top==-1)
        return 1;
    else
        return 0;
}

void push(int x)
{
    if(!isfull())
    {
        top++;
        s[top].ele = x;
        s[top].max = x;
        if(s[top-1].max > x)
        {
            s[top].max = s[top-1].max;
        }
    }
    else
    {
        printf("Stack Overflow\n");
    }
}

void pop()
{
    if(!isempty())
    {
        top--;
    }
    else
    {
        printf("Stack Underflow\n");
    }
}

void print()
{
    if(top>=0)
    {
        int i;
        for(i=0;i<=top;i++)
        {
            printf("%d ",s[i].ele);
        }
    }
    else
    {
        printf("Stack Underflow\n");
    }
}

int main()
{
    int i;
    push(10);
    push(20);
    push(30);
    pop();
    pop();
    pop();
    push(20);
    push(2);
    push(30);
    pop();
    pop();
    push(30);
    push(2);
    push(13);
    push(32);
    push(23);
    print();
    
    printf("\nMaximum element in the stack is : %d\n",s[top].max);
    // for(i=0;i<11;i++){
    //     printf("%d ",s[i].ele);
    // }
    

    return 0;
}
