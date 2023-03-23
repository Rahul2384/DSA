#include<stdio.h>
#include<stdlib.h>

struct node
{
    int data;
    struct node* left;
    struct node* right;
};
struct node* root = NULL;

struct node* buildTree()
{
    struct node* t = (struct node*)malloc(sizeof(struct node));
    printf("Enter data:");
    int da;
    scanf("%d",&da);
    t->data = da;
    if(da == -1){
        return 0;
    }
    printf("Enter data for inserting in left of %d : \n",t->data);
    t->left = buildTree();
    printf("Enter data for inserting in right of %d : \n",t->data);
    t->right = buildTree();
    return t;
}

void preOrder(struct node* t)
{
    // printf("\n");
    if(t)
    {
        printf("%d ",t->data);
        preOrder(t->left);
        preOrder(t->right);
    }
}

void postOrder(struct node* t)
{
    if(t)
    {
        postOrder(t->left);
        postOrder(t->right);
        printf("%d ",t->data);
    }
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

int height(struct node* t)
{
    int h1,h2;
    if(!t) return 0;
    h2 = height(t->right);
    h1 = height(t->left);
    if(h1>h2) return ++h1;
    else return ++h2;
}

int search(struct node* t, int d)
{
    if(!t)
    {
        return 0;
    }
    if(d == t->data)
        {
            return 1;
        }
        int res1 = search(t->left,d);
        if(res1 == 1) return 1;
        int res2 = search(t->right,d);
        if(res2 ==1) return 1;
}

int main()
{
    struct node* root = buildTree();
    printf("%d\n",root->data);
    printf("PreOrder : ");
    preOrder(root);
    printf("\nPostOrder : ");
    postOrder(root);
    printf("\nInOrder : ");
    inOrder(root);
    printf("\nHeight : %d",height(root));
    int d;
    printf("Enter the data to be searched:");
    scanf("%d",&d);
    int v = search(root,d);
    if(v==1) printf("Present\n");
    else printf("NOt present\n");
    return 0;
}