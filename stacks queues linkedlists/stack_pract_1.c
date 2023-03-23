#include<stdio.h>
#include<stdlib.h>
struct node
{
    int data;
    struct node* link;
};
struct node* top =  NULL;

void push()
{
    struct node* t = (struct node*)malloc(sizeof(struct node));
    printf("Enter element:");
    scanf("%d",&t->data);
    t->link = top;
    top=t;
}

void pop()
{
    struct node* t= top;
    if(!t)
    {
        printf("Stack Underflow\n");
    }
    else
    {
        printf("%d ",t->data);
        top = top->link;
    }
}

int main()
{
    printf("\n1-push\n2-pop\n3-exit\n");
    int c;
    scanf("%d",&c);
    while(c!=3)
    {
        if(c==1) push();
        else if(c==2)pop();
        else printf("Enter correct\n");
        printf("\n1-push\n2-pop\n3-exit\n");
        scanf("%d",&c);
    }
    return 0;
}