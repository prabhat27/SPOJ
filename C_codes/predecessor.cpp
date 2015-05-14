#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;
struct node
{
    int data;
    node *left,*right;
};
node *insert(node *ptr,int n)
{
    if(ptr==NULL)  
    {
        ptr=new node;
        ptr->data=n;
        ptr->left=ptr->right=NULL;
        return ptr;
    }
    if(n>ptr->data)
      ptr->right=insert(ptr->right,n);
    else
      ptr->left=insert(ptr->left,n);
    
    return ptr;
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
node *parent(node *ptr,int n)
{
    if(ptr==NULL) return NULL;
    if(ptr->data==n) return NULL;
    if(ptr->data<n)
    {
        if(ptr->right==NULL) return NULL;
        if(ptr->right->data==n) return ptr;
        return parent(ptr->right,n);
    }
    else
    {
    if(ptr->left==NULL) return NULL;
    if(ptr->left->data==n) return ptr;
    return parent(ptr->left,n);
    }
}
node *RTMOLST(node *ptr)
{
    if(ptr==NULL) return ptr;
    while(ptr->right)
        ptr=ptr->right;
    return ptr;
}
node *predecessor(node *ptr,int n)
{
    if(ptr->data==n) return RTMOLST(ptr->left);
    node *temp,*cur; //PARENT of n
    temp=parent(ptr,n);
    //cout<<endl<<"parent is "<<temp->data<<endl;
    if(temp==NULL)
        return NULL;
    if(n>temp->data)
        cur=temp->right;
    else
    {
       cur=temp->left;
       return RTMOLST(cur->left);
    }
       if(cur->left==NULL)
           return temp;
    return RTMOLST(cur->left);
}

int main() {
    
    node *root=NULL;
    root=insert(root,14);
    root=insert(root,10);
    root=insert(root,20);
    root=insert(root,9);
    root=insert(root,13);
    root=insert(root,16);
    root=insert(root,12);
    root=insert(root,17);
    inorder(root);
    cout<<endl;
    node *temp;
    temp=predecessor(root,17);
    if(temp)
    cout<<"predecessor is : "<<temp->data;
    else
    cout<<"NO predecessor exists";
    
    return 0;
}
