#include<stdio.h>
#include<stdlib.h>
int f=0;
struct node
{
    int data;
    struct node* left;
    struct node* right;
};

struct node* newNode(int item)
{
    struct node* t = (struct node*)malloc(sizeof(struct node));
    t->data = item;
    t->left = NULL;
    t->right = NULL;
    return t;
}

struct node* create(struct node* node, int data)
{
    if(node == NULL) return newNode(data);

    if(data < node->data)
    {  
        node->left = create(node->left,data);
    }
    else
        node->right = create(node->right,data);
    return node;
}

void inOrder(struct node* t)
{
    if(t)
    {
        inOrder(t->left);
        printf("%d ",t->data);
        inOrder(t->right);
    }
}

struct node* minimum(struct node* t)
{
    struct node* pp = NULL;
    while(t->left!=NULL)
    {
        pp = t;
        t = t->left;
    }
    printf("%d",t->data);
    return t;
}

void search(struct node* t)
{
    int c;
    printf("\nEnter element to search : "); 
    scanf("%d",&c);
    while(t)
    {
        if(c > t->data) t = t->right;
        else if(c < t->data) t = t->left;
        else
        {
            printf("Present\n");
            return;
        }
    }
    printf("Not Present\n");
}


struct node* delete(struct node* root, int value)
{
    if(root == NULL)
    {
        return NULL;
    }

    if(value < root->data)
    {
        root->left = delete(root->left, value);
    }
    else if(value > root->data)
    {
        root->right = delete(root->right, value);
    }
    else
    {
        if(root->left == NULL)
        {
            struct node* temp = root->right;
            free(root);
            return temp;
        }
        else if(root->right == NULL)
        {
            struct node* temp = root->left;
            free(root);
            return temp;
        }
        else
        {
            struct node* temp = minimum(root->right);
            root->data = temp->data;
            root->right = delete(root->right,temp->data);
        }
    
    }
    return root;
}

void takeInput(struct node* root)
{
    int d;
    scanf("%d",&d);
    while(d!=-1)
    {
        root = create(root,d);
        scanf("%d",&d);
    }
}


int main()
{
    struct node* root = NULL;
    root = create(root,8);
    root = create(root,3);
    root = create(root, 1);
    root = create(root, 6);
    root = create(root, 7);
    root = create(root, 10);
    root = create(root, 14);
    root = create(root, 4);
    root = create(root, 12);
    root = create(root, 15);
    // printf("Enter data:\n");
    // takeInput(root);
    printf("InOrder:");
    inOrder(root);
    printf("\nMinimum : ");
    struct node* min = minimum(root);
    search(root);
    int del;
    printf("Enter the element to be deleted : ");
    scanf("%d",&del);
    delete(root,del);
    printf("InOrder:");
    inOrder(root);
    return 0;
}
