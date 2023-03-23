#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct node
{
    char word[128], meaning[256];
    struct node* left;
    struct node* right;
};
struct node *root = NULL;

struct node* newNode(char word[], char meaning[])
{
    struct node* t = (struct node*)malloc(sizeof(struct node));
    strcpy(t->word, word);
    strcpy(t->meaning, meaning);
    t->left = NULL;
    t->right = NULL;
    return t;
}


void deleteNode(char str[])
{
    struct node *parent = NULL, *current = NULL, *temp = NULL;
    int flag = 0, res = 0;
    if (!root)
    {
        printf("BST is not present!!\n");
        return;
    }
    current = root;
    while (1)
    {
        res = strcasecmp(current->word, str);
        if (res == 0)
            break;
        flag = res;
        parent = current;
        current = (res > 0) ? current->left : current->right;
        if (current == NULL)
            return;
    }
    /* deleting leaf node */
    if (current->right == NULL)
    {
        if (current == root && current->left == NULL)
        {
            free(current);
            root = NULL;
            return;
        }
        else if (current == root)
        {
            root = current->left;
            free(current);
            return;
        }

        flag > 0 ? (parent->left = current->left) : (parent->right = current->left);
    }
    else
    {
        /* delete node with single child */
        temp = current->right;
        if (!temp->left)
        {
            temp->left = current->left;
            if (current == root)
            {
                root = temp;
                free(current);
                return;
            }
            flag > 0 ? (parent->left = temp) : (parent->right = temp);
        }
        else
        {
            /* delete node with two children */
            struct node *successor = NULL;
            while (1)
            {
                successor = temp->left;
                if (!successor->left)
                    break;
                temp = successor;
            }
            temp->left = successor->right;
            successor->left = current->left;
            successor->right = current->right;
            if (current == root)
            {
                root = successor;
                free(current);
                return;
            }
            (flag > 0) ? (parent->left = successor) : (parent->right = successor);
        }
    }
    free(current);
    return;
}

struct node* create (struct node* node, char word[], char meaning[])
{
    if(node == NULL)
    {
        root = newNode(word, meaning);
        return root;
    }
    else if(strcasecmp(word, node->word) >= 1)
    {
        node->right = create(node->right, word, meaning);
    }
    else if(strcasecmp(word, node->word) <= 1)
    {
        node->left = create(node->left, word, meaning);
    }
    else{
        printf("No duplicates are allowed\n");
    }
}

void inorder(struct node* t)
{
    if(t)
    {
        inorder(t->left);
        printf("Word : %s\n",t->word);
        printf("Meaning : %s\n",t->meaning);
        inorder(t->right);
    }
}

void findElement(char str[])
{
    struct node *temp = NULL;
    int flag = 0, res = 0;
    if (root == NULL)
    {
        printf("No Binary Search Tree!!\n");
        return;
    }
    temp = root;
    while (temp)
    {
        if ((res = strcasecmp(temp->word, str)) == 0)
        {
            printf("Word   : %s", str);
            printf("Meaning: %s", temp->meaning);
            flag = 1;
            break;
        }
        temp = (res > 0) ? temp->left : temp->right;
    }
    if (!flag)
        printf("Search Element not found in Binary Search Tree\n");
    return;
}

int main()
{
    
    char word[128], meaning[256];
    int ch;
    while (1)
    {
        printf("\n1. Insertion\t2. Deletion\n");
        printf("3. Searching\t4. Traversal\n");
        printf("5. Exit\nEnter ur choice:");
        scanf("%d", &ch);
        getchar();
        switch (ch)
        {
        case 1:
            printf("Enter the word to insert : ");
            gets(word);
            printf("Enter the meaning : ");
            gets(meaning);
            root = create(root, word, meaning);
            break;
        case 2:
            printf("Enter the word to delete:");
            gets(word);
            deleteNode(word);
            break;
        case 3:
            printf("Enter the word to be searched : ");
            gets(word);
            // struct node* temp = search(root, word);
            findElement(word);
            break;
        case 4:
            inorder(root);
            break;
        case 5:
            exit(0);
        default:
            break;
        }
    }
    return 0;
}