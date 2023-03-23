
#include <stdio.h>
#include<string.h>
#define MAX 100
// char s[MAX];
int top = -1;
typedef struct
{
    char c;
}stack;
stack s[MAX];

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

void push(char x)
{
    if(!isfull())
    {
        top++;
        s[top].c = x;
    }
    else
    {
        printf("Stack Overflow\n");
    }
}

void pop()
{
    printf("\n");
    if(!isempty())
    {
        printf("%c ",s[top].c);
        top--;
    }
    else
    {
        printf("Stack Underflow\n");
    }
}

void display()
{
    int i;
        printf("\n");
        for(i=0;i<=top;i++)
        {
            printf("%c ",s[i].c);
        }
}

int main()
{
    push('V');
    push('a');
    push('s');
    push('a');
    push('v');
    push('i');
    display();
    pop();
    pop();
    pop();
    pop();
    pop();
    pop();
    pop();
    display();
    for(int i;i<6;i++)
    {
        printf("%c ",s[i].c);
    }
    
    printf("%s ",s);
    return 0;
}
