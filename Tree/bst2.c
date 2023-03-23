#include<stdio.h>
#include<stdlib.h>
#include<string.h>
struct node
{
char name[30];
int id;
int salary;
struct node* left;
struct node* right;
};
//struct node* root = NULL;

struct node* newNode(char name[],int id, int salary)
{
struct node* t = (struct node*)malloc(sizeof(struct node));
strcpy(t->name,name);
t->id=id;
t->salary = salary;
t->left = NULL;
t->right = NULL;
return t;
}

struct node* create(struct node* node, char name[], int id, int salary)
{
if(node==NULL) return newNode(name,id,salary);
if(salary > node->salary) node->right= create(node->right,name,id,salary);
else if(salary < node->salary) node->left = create(node->left, name, id,salary);
else printf("No duplicates allowed");
return node;
}

void inorder(struct node* t){
if(t)
{
inorder(t->left);
printf("name : %s\n",t->name);
printf("id : %d\n",t->id);
printf("salary : %d\n",t->salary);
inorder(t->right);
}
}

void maximum(struct node* t)
{
while(t->right)
{
t=t->right;
}
printf("\nHighest salary for %s -- %d -- %d\n",t->name,t->id,t->salary);
}

void minimum(struct node* t)
{
while(t->left)
{
t = t->left;
}
printf("\nLowest salary for %s -- %d -- %d\n",t->name,t->id,t->salary);
}

void print(struct node* t)
{
printf("Employees whose salary is greater than 50000/- is\n");
while(t)
{if(t->salary > 50000)
{
 printf("%s -- %d -- %d\n", t->name, t->id, t->salary);
t=t->right;
}
else if(t->salary < 50000)
{
t=t->right;
}
else t= t->right;
}}

int main()
{
char c[30];
int id,salary;
struct node* root = NULL;
root = create(root,"Rahul",032,50100);
root = create(root, "Rakesh",033,100000);
root = create(root, "NRK", 031, 75000);
root = create(root, "Adithya",004, 85000);
root = create(root, "LOL", 050, 45000);

inorder(root);
maximum(root);
minimum(root);
print(root);
return 0;
}
