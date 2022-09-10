#include<stdio.h>
#include<stdlib.h>
struct node {
    int data;
    struct node* left;
    struct node* right;
};
struct node* root = NULL;
void add(int x)
{
        struct node* temp = (struct node*)malloc(sizeof(struct node));
        temp->data=x;
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
struct node* find_minimum(struct node* root)
{
    while (root->left != NULL)
    {
        root = root->left;
    }
    return root;
}

struct node* delete(struct node* head, int x)
{
    if (head == NULL)
        return NULL;
    struct node* parent ;
    struct node* current = head;
     //searching for the item to be deleted
    if (x != current->data)
    {
        while (x != current->data)
        {
            parent = current;
            if (x > current->data)
                current =current->right;
            else
                current = current->left;
        }
        if (parent->right == current)
            parent->right = delete(current, x);
        else
            parent->left = delete(current, x);
    }
    else  //performing the deletion operation
    {
        //NODE HAS NO CHILD
        if (current->left == NULL && current->right == NULL)
        {
            free(current);
            return NULL;
        }
        //NODE HAS ONE CHILD
        else if (current->left == NULL || current->right == NULL)
        {
            struct node* temp;
            if (current->left == NULL)
                temp = current->right;
            else
                temp = current->left;
            free(current);
            return temp;
        }
        //NODE HAS TWO CHILD
        else
        {
            struct node* temp = find_minimum(current->right);
            current->data = temp->data;
            current->right = delete(current->right, temp->data);
        }
    }
    return head;
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
   add(24);
   add(14);
   add(50);
   add(18);
   add(11);
   add(45);
   add(70);
   add(10);
   add(19);
   add(15);
   add(68);
   add(82);
    root=delete(root,24);
    // root=delete(root,11);
    // root=delete(root,68);
    // root=delete(root,19);
    inorder_traverse(root);

    // while (1)
    // {
    //     int x;
    //     printf("Enter the choice: ");
    //     scanf("%d", &x);
    //     switch (x)
    //     {
    //     case 1: add();
    //         break;
    //     case 2:
    //     {
    //         int x;
    //         printf("Enter the number to delete: ");
    //         scanf("%d", &x);
    //         root = delete(root, x);
    //         break;
    //     }
    //     case 3:inorder_traverse(root);
    //         break;
    //     case 4:preorder_traverse(root);
    //         break;
    //     case 5:postorder_traverse(root);
    //         break;
    //     case 6:
    //     {int x = height(root);
    //     printf("height=%d\n", x);
    //     break;
    //     }
        
    //     case 7: printf("Exiting.......\n");
    //         exit(1);
    //     default:printf("CHOOSE FROM THE GIVEN OPTION...!!!\n");
    //     }
    // }
}