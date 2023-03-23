#include<stdio.h>
#include<stdlib.h>
struct dnode
{
    int data;
    struct dnode* llink;
    struct dnode* rlink;
};
struct dnode* first = NULL;
int count = 0;
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
    count++;
}

void insertAtk(int k)
{
    struct dnode* p = (struct dnode*)malloc(sizeof(struct dnode));
    struct dnode* t = first;
    int i=1,x;
    printf("Enter element:");
    scanf("%d",&x);
    if(!t)
    {
        printf("Empty Linked list\n");
    }
    else{
    while(t && i<k-1)
    {
        t = t->rlink;
        i++;
    }
    if(!t)
    {
        printf("k:%d is more\n",k);
    }
    else if(k==count+1)
    {
        p->llink = t;
        p->rlink = t->rlink;
        t->rlink = p;
        p->data = x;
        count++;
    }
    else if (k!=1)
    {
        p->llink = t;
        p->rlink = t->rlink;
        // p->rlink = t->rlink;
        // p->llink = p->rlink->llink;
        t->rlink = p;
        p->rlink->llink = p;
        p->data = x;
        count++;
    }
    else
    {
        p->llink=NULL;
        p->rlink=t;
        t->llink=p;
        first = p;
        p->data = x;
        count++;
    }}
    
}

void delelteAtk(int k)
{
    struct dnode* t = first;
    int i = 1;
    while(t && i<k)
    {
        t = t->rlink;
        i++;
    }
        // if(!t)
        // {
        //     printf("k:%d is more\n",k);
        // }
        if(t==first && t)
        {
            if(t->rlink)
            {
                t->rlink->llink = NULL;
                first = t->rlink;
            }
            else
            {
                first = NULL;
            }
        }
        else if(!t->rlink)
        {
            t->llink->rlink = NULL;
            free(t);
        }
        else
        {
            t->rlink->llink = t->llink;
            t->llink->rlink = t->rlink;
        }
        count--;
}
void display()
{
    struct dnode* p = first;
    if(!p)
    {
        printf("Empty Linked List\n");
    }
    while(p)
    {
        printf("%d ",p->data);
        p = p->rlink;   
    }
    
    printf("\n");
}

int main()
{
    insert(10);
    // display();
    insert(20);
    display();
    insert(30);
    insert(40);
    insertAtk(1);
    insertAtk(3);
    printf("%d\n",count);
    insertAtk(8);
    printf("%d\n",count);
    insertAtk(7);
    display();
    printf("%d\n",count);
    delelteAtk(1);
    display();
    printf("%d\n",count);
    delelteAtk(6);
    display();
    display();
    delelteAtk(3);
    printf("%d\n",count);
    display();
    insert(30);
    insert(40);
    insert(50);
    display();
}