#include<iostream>
using namespace std;

struct node{
    struct node *right;
    struct node *left;
    int data; 
};
struct node *head=NULL; 

void insertion(int value){
    struct node* temp=(struct node*)malloc(sizeof(struct node));
    temp->left=NULL;
    temp->data=value;
    temp->right=NULL;

    if(head==NULL)
    head=temp;

    else{
        struct node *parent, *current=head;     
        while(current!=NULL){       //loop willrun until current will point at null

            parent=current;     //eventually parent pointer will point to the parent of current 

            if(temp->data>=current->data)
            current=current->right;

            else 
            current=current->left;
        }
        //when current will point at NULL
        if(temp->data>=parent->data)  
        parent->right=temp;

        else
        parent->left=temp;
    }

}

void inorder(struct node *current){
    // left->parent->right
    if(current->left!=NULL)
    inorder(current->left);
    cout<<current->data<<endl;
    if(current->right!=NULL)
    inorder(current->right);
}

struct node* minimum(struct node* current){
    while(current->left!=NULL){
        current=current->left; 
    }
    return current; 
}
struct node* deletion(struct node* head, int val){
    if (head == NULL)
        return NULL;
    struct node* current= head; 
    struct node *parent;
    if(current->data!=val){
        //SEARCHING 
        while(current->data!=val){
            parent=current; 
            if(current->data>val)
               current=current->left; 
            else
                current=current->right; 
        }
        if(parent->left==current)
            parent->left=deletion(parent->left, current->data);
        else
            parent->right=deletion(parent->right, current->data);
    }
    //DELETION 
    else{
       
        //NO CHILD
        if(current->left==NULL&&current->right==NULL){
            free(current); 
            return NULL; 
        }
        
        //ONE CHILD 
        else if(current->left==NULL||current->right==NULL){
            if(current->left!=NULL){
                struct node* temp=current->left;
                free(current);
                return temp; 
            }
        else{
                struct node* temp=current->right;
                free(current);
                return temp; 
            }
          
        }
        
     //TWO CHILDREN
       else{
           //when (current->left!=NULL&&current->right!=NULL)
            struct node* min=minimum(current->right);
            current->data=min->data;
            current->right=deletion(current->right, min->data);
        }
       
    }
    return head; 
}

int main(){
    
    insertion(24);
    insertion(14);
    insertion(50);
    insertion(18);
    insertion(11);
    insertion(45);
    insertion(70);
    insertion(10);
    insertion(19);
    insertion(15);
    insertion(68);
    insertion(82);
    head=deletion(head, 24);
    head=deletion(head, 11);
    head=deletion(head, 68);
    head=deletion(head, 19);
    inorder(head);
    
    return 0; 
}