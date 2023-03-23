#include<stdio.h>
#include<stdlib.h>
struct dnode
{
    int data;
    struct dnode* llink;
    struct dnode* rlink;
};
struct dnode* first = NULL;
int a[2];
int i=0;
void insert(int x)
{
    struct dnode* p = (struct dnode*)malloc(sizeof(struct dnode));
    if(first)
    {
        p->llink = NULL;
        p->rlink = first;
        first->llink = p;
        first = p;
        p->data = x;
        printf("%d is inserted\n",x);
        
    }
    else
    {
        p->llink = NULL;
        p->rlink = NULL;
        p->data = x;
        first = p;
        printf("%d is inserted\n",x);
    }
}

void display()
{
    struct dnode* t = first;
    printf("Linked list : ");
    while(t)
    {
        printf("%d ",t->data);
        t = t->rlink;
    }
}

void merge()
{

}

int main()
{
    int j=0;
    for(j=0;j<5;j++)
    {
        create();
    }
    i++;
}