#include<stdio.h>
#include<stdlib.h>
struct node 
{
    int data;
    struct node* link;
};
struct node* first = NULL;
void create()
{
    char c;
    int count=0;
    printf("Enter your choice(y/n):");
    scanf("%c",&c);
    do
    {
        struct node *t = (struct node*)malloc(sizeof(struct node));
        printf("Enter data:");
        scanf("%d",&t->data);
        count++;
        t->link = first;
        first = t;
        printf("Enter your choice(y/n):");
        getchar();
        scanf("%c",&c);
    } while (c=='y');
    printf("%d ",count);
    
}

void insert(int x)
{
    struct node* t = (struct node*)malloc(sizeof(struct node));
    t->link = first;
    t->data = x;
    first = t;
}


void display()
{
    struct node *t = first;
    struct node *p;
    while(t)
    {
        if(t->data < 5)
            t->data+=30; printf("%d ",t->data);
        p=t;
        t = t->link;
        free(p);
    }first = NULL;
}

int main()
{
    create();
    insert(500);
    display();
    return 0;
}