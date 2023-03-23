#include<stdio.h>
#include<stdlib.h>
struct node
{
    int data;
    struct node * link;
};
struct node* first = NULL;

void insertBeg()
{
    struct node* t = (struct node*)malloc(sizeof(struct node));
    printf("Enter data:");
    scanf("%d",&t->data);
    t->link = first;
    first = t;
}

void display()
{
    struct node* t = first;
    printf("Linked list is: ");
    while(t)
    {
        printf("%d ",t->data);
        t  = t->link;
    }
    printf("\n");
}

void insertLast()
{
    int x;
    struct node* t = (struct node*)malloc(sizeof(struct node));
    printf("Enter data:");
    scanf("%d",&x);
    struct node*p=first;
    while(p->link)
    {
        p = p->link;
    }
    p->link = t;
    t->data = x;
    t->link = NULL;
}

void insertAtk()
{int k;
    printf("Enter k:");
    scanf("%d",&k);
    struct node* t = (struct node*)malloc(sizeof(struct node));
    struct node*p = first;
    int i=1;
    printf("Enter data:");
    scanf("%d",&t->data);
    if(!p)
    {
        printf("No linked list\n");
    }
    else{
        if(k!=1)
        {
            while(i<k-1 && p)
            {
                p = p->link;
                i++;
            }
            if(!p)
            {
                printf("k : %d is more\n",k);
            }
            else{
            t->link = p->link;
            p->link = t;
            }
        }
        else
        {
            t->link = first;
            first = t;
        }
    }
}

int main()
{
    printf("\n\n1-insertBeg\n2-insertLast\n3-insertAtk\n4-display\n5-exit\n");
    int c;
    scanf("%d",&c);
    while(c!=5)
    {
        if(c==1) insertBeg();
        else if(c==2) insertLast();
        else if (c==3) insertAtk();
        else if (c==4) display();
        else printf("Enter correct\n");
        printf("\n\n1-insertBeg\n2-insertLast\n3-insertAtk\n4-display\n5-exit\n");
        printf("Enter again\n");
        scanf("%d",&c);
    }
    return 0;
}