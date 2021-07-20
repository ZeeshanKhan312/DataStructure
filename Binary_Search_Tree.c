#include<stdio.h>
#include<stdlib.h>
struct node {
    int data;
    struct node* left;
    struct node* right;
};
struct node* root = NULL;
void add()
{
    for (int i = 0; i < 9; i++)
    {
        int x;
        struct node* temp = (struct node*)malloc(sizeof(struct node));
        printf("Enter the data: ");
        scanf("%d", &temp->data);
        temp->left = NULL;
        temp->right = NULL;
        if (root == NULL)
        {
            root = temp;
        }
        else
        {
            struct node* parent, * current;
            current = root;
            parent = root;
            while (current)
            {
                parent = current;
                if (temp->data >= current->data)
                    current = current->right;
                else
                    current = current->left;
            }
            if (temp->data >= parent->data)
                parent->right = temp;
            else
                parent->left = temp;
        }
    }
}
struct node* find_minimum(struct node* root)
{
    while (root->left != NULL)
    {
        root = root->left;
    }
    return root;
}
struct node* delete(struct node* root, int x)
{
    //searching for the item to be deleted
    if (root == NULL)
        return NULL;
    struct node* parent = root;
    struct node* current = root;
    if (x != root->data)
    {

        while (x != root->data)
        {
            parent = root;
            if (x > root->data)
                root = root->right;
            else
                root = root->left;
        }
        if (parent->right == root)
            parent->right = delete(root, x);
        else
            parent->left = delete(root, x);
    }
    /* else if (x > root->data)
         root->right = delete(root->right, x);
     else if (x < root->data)
         root->left = delete(root->left, x);*/
    else
    {
        //No Children
        if (root->left == NULL && root->right == NULL)
        {
            free(root);
            return NULL;
        }
        //One Child
        else if (root->left == NULL || root->right == NULL)
        {
            struct node* temp;
            if (root->left == NULL)
                temp = root->right;
            else
                temp = root->left;
            free(root);
            return temp;
        }
        //Two Children
        else
        {
            struct node* temp = find_minimum(root->right);
            root->data = temp->data;
            root->right = delete(root->right, temp->data);
        }
    }
    return current;
}
int height(struct node* temp)
{
    int h;
    if (temp == NULL)
        return 0;
    int left = height(temp->left);
    int right = height(temp->right);
    if (left > right)
        h =1+  left;
    else
        h = right;
    return h;
}
void inorder_traverse(struct node* current)
{
    if (current != NULL)
    {
        if (current->left)
            inorder_traverse(current->left);
        printf("%d\n", current->data);
        if (current->right)
            inorder_traverse(current->right);
    }
    else
        printf("Tree is empty\n");
}
void preorder_traverse(struct node* current)
{
    printf("%d\n", current->data);
    if (current->left)
        preorder_traverse(current->left);
    if (current->right)
        preorder_traverse(current->right);
}
void postorder_traverse(struct node* current)
{
    if (current->left)
        postorder_traverse(current->left);
    if (current->right)
        postorder_traverse(current->right);
    printf("%d\n", current->data);
}
void main()
{
    printf("***********************Binary Search Tree**********************\n1.Insertion\n2.Delete\n3.Inorder Traverse\n4.Preorder Traverse\n5.Postorder Traverse\n6.Height\n\n");

    while (1)
    {
        int x;
        printf("Enter the choice: ");
        scanf("%d", &x);
        switch (x)
        {
        case 1: add();
            break;
        case 2:
        {
            int x;
            printf("Enter the number to delete: ");
            scanf("%d", &x);
            root = delete(root, x);
            break;
        }
        case 3:inorder_traverse(root);
            break;
        case 4:preorder_traverse(root);
            break;
        case 5:postorder_traverse(root);
            break;
        case 6:
        {int x = height(root);
        printf("height=%d\n", x);
        break;
        }
        
        case 7: printf("Exiting.......\n");
            exit(1);
        default:printf("CHOOSE FROM THE GIVEN OPTION...!!!\n");
        }
    }
}