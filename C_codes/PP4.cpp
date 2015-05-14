/*
Convert a given Binary Tree to Doubly Linked List
*/

#include<iostream>
#include<string.h>
#include<cstdio>
using namespace std;

struct node
{
    int data;
    node* left;
    node* right;
};

node* newNode(int data)
{
    node* new_node = new node;
    new_node->data = data;
    new_node->left = new_node->right = NULL;
    return (new_node);
}

void inorder(node *ptr)
{
     if(ptr)
     {
       inorder(ptr->left);
       cout<<ptr->data<<" ";
       inorder(ptr->right);
     }
}
node *rightmost(node *ptr)
{
     if(ptr==NULL) return ptr;
     while(ptr->right)
     ptr=ptr->right;
     
     return ptr;
}

node *leftmost(node *ptr)
{
     if(ptr==NULL) return ptr;
     while(ptr->left)
     ptr=ptr->left;
     
     return ptr;
}

void dll(node *ptr)
{
 
  
}
        
int main()
{
    node *root        = newNode(15);
    root->left        = newNode(10);
    root->right       = newNode(17);
   // root->left->left  = newNode(5);
   // root->left->right = newNode(12);
   // root->right->left = newNode(16);
   // root->right->right = newNode(18); 
    
    //inorder(root);
    
    dll(root);
    //cout<<rightmost(root)->data;
    //cout<<root->left->data;
    /*
    while(root)
    {
      cout<<root->data<<" ";
      root=root->right;
    }
    */
    system("pause");
    return 0;
} 
    
