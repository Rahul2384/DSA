
#include <stdio.h>
#define MAX 100
#include<string.h>
char s[MAX];
int top = -1;

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
        s[top] = x;
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
        
        // printf("%s ",s[top]);
        top--;
    }
    else
    {
        printf("Stack Underflow\n");
    }
}

int main()
{
    int i,f=1;
    printf("Input Expression : ");
    scanf("%s",s);
    for(i=0;i<strlen(s);i++)
    {
        if(s[i]=='(')
            push(s[i]);
        else if(s[i] == ')')
        {
            if(!isempty())
                pop();
            else
            {
                f=0;
                printf("Not proper\n");
                break;
            }
        }
    }
    if(isempty() && f==1)
        printf("Proper\n");
    else if(top!=-1)
        printf("Not proper\n");
    // else
    //     printf("Not proper\n");
    puts(s);
    return 0;
}
