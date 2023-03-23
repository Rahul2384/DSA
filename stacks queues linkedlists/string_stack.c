
#include <stdio.h>
#include<string.h>
#define MAX 100
int top = -1;
char s[MAX][100];


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

void push(char x[])
{
    if(!isfull())
    {
        top++;
        int i;
        for(i=0;i<strlen(x);i++)
        {
            s[top][i] = x[i];
        }
        s[top][i]=' ';
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
        printf("%s ",s[top]);
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
        for(i=0;i<=top;i++)
        {
            printf("%s ",s[i]);
        }
}

int main()
{
    push("Vasavi");
    push("College");
    push("Of");
    push("Engineering");
    display();
    pop();
    pop();
    pop();
    pop();
    pop();
    push("RAhul");
    push("Kasula");
    display();
    pop();
    display();
    int i;
    for(i=0;i<1;i++)
    {
        printf("%s",s[i]);
    }
    return 0;
}
