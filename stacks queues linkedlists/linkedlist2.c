#include<stdio.h>
#include<stdlib.h>
struct node
{
    int data;
    struct node* link;
};
struct node* first = NULL;
int count = 0;

void create()
{
    char c;
    do{
        struct node* t = (struct node*)malloc(sizeof(struct node*));
        scanf("%d",&t->data);
        t->link = first;
        first = t;
        printf("Enter (y/n):");
        getchar();
        scanf("%c",&c);
        count++;
    } while (c == 'y');

    // struct node* t = (struct node*)malloc(sizeof(struct node*));
    // scanf("%d",&t->data);
    // t->link = first;
    // first = t;
}

void display()
{
    struct node* t = first;
    while(t)
    {
        printf("%d ",t->data);
        t = t->link;
    }
}

void delete()
{
    struct node * t = first;
    struct node* p;
    if(!first) printf("Empty Linkedlist\n");
    else
    {
        while(t)
        {
            p=t;
            t=t->link;
            // free(p);
            p->link = NULL;
        }
        first = NULL;
    }
}

void insertBeginning()
{
    struct node* t = (struct node*)malloc(sizeof(struct node*));
    printf("Enter a number:");
    scanf("%d",&t->data);
    t->link = first;
    first = t;
    count++;
}

void insertLast()
{
    struct node* t = first;
    struct node* p = (struct node*)malloc(sizeof(struct node*));
    printf("Enter a number:");
    scanf("%d",&p->data);
    count++;
    while(t->link)
    {
        t = t->link;
    }
    t->link = p;
    p->link = NULL;     
}

void printAlternate()
{
    struct node* t = first;
    if(t && !t->link) printf("%d ",t->data);
    else
    {
        while(t && t->link)
        {
            printf("%d ",t->data);
            t = t->link->link;
        }
    }
}

void loop()
{
    struct node* f = first;
    struct node* s = first;
    while(f && f->link && s!=f)
    {
        s = s->link;
        f=f->link->link;
    }
    if(s==f) printf("Loop is present\n");
    else printf("Loop is not present\n");
}

void insertAtk(int k)
{
    int x,i=1;
    printf("Enter the element to enter:");
    scanf("%d",&x);
    struct node* t = first;
    struct node* p = (struct node*)malloc(sizeof(struct node*));
    if(!t) printf("There is no LinkedList\n");
    else
    {
        while(t && i<k-1)
        {
            t = t->link;
            i++;
        }
        if(!t) printf("We can't insert as k is %d and length of linked list is %d\n",k,count);
        else if(k!=1)
        {
            p->link = t->link;
            t->link = p;
            p->data = x;
            
        }
        else
        {
            // p->link = t->link;
            // p->data = x;
            // t->link = p;
            p->link = first;
            first = p;
            p->data = x;
        }
    }
    count++;
}

void deleteAtk(int k)
{
    int i=1;
    struct node* t = first;
    struct node* p;
    while(t && i<k-1)
    {
        t = t->link;
        i++;
    }
    if(!t) printf("k=%d is more",k);
    else
    {
        p = t->link;
        t->link = p->link;
        printf("%d is removed\n",p->data);
        
    }
    p->link = NULL;
    count--;
}

int main()
{
    create();
    display();
    insertBeginning();
    display();
    insertLast();
    display();
    printAlternate();
    loop();
    insertAtk(4);
    display();
    deleteAtk(4);
    display();
    delete();
    display();
    
    return 0;
}