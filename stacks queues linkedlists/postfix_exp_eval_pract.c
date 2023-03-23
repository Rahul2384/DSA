#include<stdio.h>
#include<ctype.h>
#define MAX 100
int s[MAX];
int top=-1;

void push(int item)
{

    if (top >= MAX - 1) {
        printf("stack over flow");
        return;
    }
    else {
        top = top + 1;
        s[top] = item;
    }
}

/* define pop operation */
int pop()
{
    int item;
    if (top < 0) {
        printf("stack under flow");
    }
    else {
        item = s[top];
        top = top - 1;
        return item;
    }
}

void evalPostfix(char postfix[])
{
    char ch;
    int A,B,val;
    for(int i=0; postfix[i]!='\0'; i++)
    {
        if(isdigit(postfix[i]))
        {
            push((int)(postfix[i]));
        }
        else if (ch == '+' || ch == '-' || ch == '*' || ch == '/') {
            /* we saw an operator
* pop top element A and next-to-top elemnet B
* from stack and compute B operator A
*/
            A = pop();
            B = pop();

            switch (ch) /* ch is an operator */
            {
            case '*':
                val = B * A;
                break;

            case '/':
                val = B / A;
                break;

            case '+':
                val = B + A;
                break;

            case '-':
                val = B - A;
                break;
            }

            /* push the value obtained above onto the stack */
            push(val);
        }
    
    }
printf(" \n Result of expression evaluation : %d \n", pop());
}
int main()
{
    char postfix[MAX];
    printf("Enter expression : ");
    gets(postfix);
    evalPostfix(postfix);
    return 0;
}