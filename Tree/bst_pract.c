#include <stdio.h>
#include<stdlib.h>

struct node
{
    int data;
    struct node* left;
    struct node* right;
};

struct node* root = NULL;

void newNode(int data)
{
    struct node* t = (struct node*)malloc(sizeof(struct node));
    t->data = data;
    t->left = NULL;
    t->right = NULL;
    
}


void create(struct node* root,int data)
{
    if(root = NULL) newNode(data);
    if(data < root->data) create(root->left,data);
}
int main()
{

}