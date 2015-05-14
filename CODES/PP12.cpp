/*
 Given a Binary Search tree along with the parent pointer, find the next largest
  node for the given node. Give the time and space complexity. 
*/

#include<iostream>
using namespace std;
struct node
{
       int data;
       node *l,*r,*p;
       }*root;
node *insert(node*ptr,int a)
{
     if(ptr==NULL)
     {
         ptr=new node;
         ptr->data=a;
         ptr->l=ptr->r=ptr->p=NULL;
         return ptr;
     }
     else
     {
       if(a>ptr->data)
       {
          node *temp=insert(ptr->r,a);
          ptr->r=temp;
          temp->p=ptr;
       }
       else
       {
         node *temp=insert(ptr->l,a);
         ptr->l=temp;
         temp->p=ptr;
       }
       return ptr;
     }
}
int find(node *ptr)
{
    int rl=9999;
   
      if(ptr->r!=NULL)
      {
        node *nptr=ptr->r;
        while(nptr->l!=NULL)
         nptr=nptr->l;
         
         rl=nptr->data;
      }
     int n=ptr->data;
     while(ptr->p!=NULL)
     {
       if(ptr->p->data>n)
        rl=min(rl,ptr->p->data);
        
      ptr=ptr->p;
     }  
     
     return rl;
}   
      
int main()
{
    root=NULL;
    
    root=insert(root,13);
    root=insert(root,10);
    root=insert(root,14);
    root=insert(root,5);
    root=insert(root,12);
    root=insert(root,16);
    root=insert(root,15);
    root=insert(root,11);
    
    cout<<find(root->l->l);
    
    system("pause");
}
    
