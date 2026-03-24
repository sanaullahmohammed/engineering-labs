/*
Binary Search Tree
Design, Develop and Implement a menu driven Program in C for the following operations on
Binary Search Tree (BST) of Integers.
a. Create a BST of N Integers: 6, 9, 5, 2, 8, 15, 24, 14, 7, 8, 5, 2
b. Traverse the BST in Inorder, Preorder and Post Order
c. Search the BST for a given element (KEY) and report the appropriate message
d. Exit
*/

#include <stdio.h>
#include <stdlib.h>
typedef struct NODE Node;
struct NODE
{
    int value;
    Node *left;
    Node *right;
};

Node *root = NULL;
/*
1. If tree is empty, create tree with new node
2. If the value < root value then insert value as left child
3. If the value > root value then insert value as right child
*/
Node *insert(Node *root, int value)
{
    if (root == NULL)
    {
        Node *node = malloc(sizeof(Node));
        node->value = value;
        node->left = node->right = NULL;
        return node;
    }
    if (value == root->value)
    {
        printf(" Duplicate Element Not Allowed !!!");
    }
    if (value < root->value)
    {
        root->left = insert(root->left, value);
    }
    if (value > root->value)
    {
        root->right = insert(root->right, value);
    }
    return root;
}
/*
1. Return NULL if tree is empty
2. if value = root value, found the value
3. If value < root value search in left tree
4. If value > root value search in right tree
*/
Node *search(Node *root, int value)
{
    if(root == NULL) /* Element is not found */
    {
        return NULL;
    }
    if (value == root->value)
    {
        return root; /* Element Found */
    }
    if(value < root->value) /* Search in the left sub tree. */
    {
        return search(root->left, value);
    }
    if(value > root->value) /* Search in the right sub tree. */
    {
        return search(root->right, value);
    }
}
/*
1. Print left tree
2. Print root node
3. Print right tree
*/
void inorder(Node *root)
{
    if (root != NULL)
    {
    inorder(root->left);
    printf(" %d ", root->value);
    inorder(root->right);
    }
}
/*
1. Print root node
2. Print left tree
3. Print right tree
*/
void preorder(Node *root)
{
    if (root != NULL)
    {
        printf(" %d ", root->value);
        preorder(root->left);
        preorder(root->right);
    }
}
/*
1. Print left tree
2. Print right tree
3. Print root node
*/
void postorder(Node *root)
{
    if (root != NULL)
    {
        postorder(root->left);
        postorder(root->right);
        printf(" %d ", root->value);
    }
}
/*
1. Traverse the tree and print preorder, inorder and postorder sequences
*/
void traverse()
{
    preorder(root);
    printf(" Preorder\n");
    inorder(root);
    printf(" Inorder\n");
    postorder(root);
    printf(" Postorder\n");
}
/*
1. Read the value to search
2. Print the search result as Found or NOT found
*/
void find()
{
Node *node;
int value;
printf("Enter item: ");
scanf("%d", &value);
node = search(root, value);
node == NULL ? printf("Not found.\n") : printf("Found %d.\n", node->value);
}
/*
1. Read tree size and the node values
2. Create the tree by insertion
*/
void create()
{
    int n;
    int value;
    printf("BST for How Many Nodes? : ");
    scanf("%d", &n);
    for (int i=0; i<n; i++)
    {
        printf("Enter the value of node %d: ", i+1);
        scanf("%d", &value);
        root = insert(root, value);
    }
    printf("BST created!!\n");
}

int main()
{
    int choice;
    typedef struct
    {
        char *name;
        void (*func)();
    } Menu;

    Menu menu[] =
    {
        {"Exit", exit},
        {"Create", create},
        {"traverse", traverse},
        {"Search", find}
    };
    int size = sizeof(menu)/sizeof(Menu);
    for(;;)
    {
        printf("\n-------BST Menu-------\n");
        for(int i=0; i < size; i++)
        {
            printf("%d. %s\n", i, menu[i].name);
        }
        printf("---------------------------------\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        (*menu[choice].func)();
    }
}
/*
Test cases

4
/ \
/ \
2 5
/ \ / \
/ \ / \
1 3 6 7
Create tree of 7 nodes 4 2 5 1 3 6 7
4 2 1 3 5 6 7 preorder
1 2 3 4 5 6 7 Inorder
1 3 2 6 7 5 4 postorder
find 7, found
find 8, not found
*/