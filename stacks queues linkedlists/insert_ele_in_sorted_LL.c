#include <stdio.h>
#include <stdlib.h>
struct node
{
    int data;
    struct node *link;
};

struct node *first = NULL;


void create()
{
    char c;
    do
    {
        struct node *t = (struct node *)malloc(sizeof(struct node));
        printf("Enter data:");
        scanf("%d", &t->data);
        t->link = first;
        first = t;
        printf("Enter (y/n):");
        getchar();
        scanf("%c", &c);
    } while (c == 'y');
}

void sorted(int x)
{
    struct node *t = (struct node *)malloc(sizeof(struct node));
    struct node *p = first;
    struct node *prev=NULL;
    t->data = x;
    if (!first)
    {
        t->link = NULL;
        first = t;
    }
    else
    {
        while (p && p->data >= x)
        {
            prev = p;
            p = p->link;
        }
        if (!prev)
        {
            t->link = first;
            first = t;
        }
        else
        {
            t->link = prev->link;
            prev->link = t;
        }
    }
}

void display()
{
    struct node *t = first;
    while (t)
    {
        printf("%d ", t->data);
        t = t->link;
    }
}

int main()
{
    create();
    display();
    sorted(0);
    display();
    return 0;
}
// #include<stdio.h>
// #include<stdlib.h>
// struct node
// {
//     int data;
//     struct node* link;
// };
// struct node* first = NULL;

// void create()
// {
//     struct node* t = (struct node*)malloc(sizeof(struct node));
//     printf("Enter element:");
//     scanf("%d",&t->data);
//     t->link = first;
//     first = t;
// }

// void display()
// {
//     struct node* t = first;
//     while(t)
//     {
//         printf("%d ",t->data);
//         t = t->link;
//     }
// }

// void sort(int x)
// {
//     struct node* t = first;
//     struct node* p = (struct node*)malloc(sizeof(struct node));
//     struct node* prev;
//     p->data = x;
//     if(!first)
//     {
//         p->link = NULL;
//         first = p;
//     }
//     else
//     {
//         while(t && t->data<x)
//         {
//             prev = t;
//             t = t->link;
//         }
//         if(x<first->data)  first = p;
//         else prev->link = p;
//         p->link = t;
//     }
// }

// int main()
// {
//     for(int i=0;i<5;i++)
//     {
//         create();
//     }
//     display();
//     sort(60);
//     display();
//     return 0;
// }