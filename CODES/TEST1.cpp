/*
TWO NODES OF BST ARE INTERCHANGED , CORRECT THE BST
*/
#include<iostream>
using namespace std;

struct node 
{
       int data;
       node *l,*r;
}*root,*swp1,*swp2;;
node *insert(int a,node *ptr)
{
   if(ptr==NULL)
   {
      ptr=new node;
      ptr->data=a;
      ptr->l=ptr->r=NULL;
      root=ptr;
   }
   else
   {
       if(a>ptr->data)
        ptr->r=insert(a,ptr->r);
       else
        ptr->l=insert(a,ptr->l);  
   }
   
   return ptr;
}

void inorder(node *ptr)
{
     if(ptr)
     {
        inorder(ptr->l);
        cout<<ptr->data<<" ";
        inorder(ptr->r);
     }
}
int t=-1;
void first(node *ptr)
{
   if(ptr)
   {
       first(ptr->l);
       if(ptr->data<t)
         return;
         
       t=ptr->data;
       swp1=ptr;
       first(ptr->r);
   }
}
void second(node *ptr)
{
    if(ptr)
   {
       second(ptr->l);
       if(ptr->data<t)
        swp2=ptr;
        
       t=ptr->data;
       
       second(ptr->r);
   }  
}  
int main()
{
  root=NULL;
  /*
  root=insert(13,root);
  root=insert(8,root);
  root=insert(17,root);
  root=insert(6,root);
  root=insert(10,root);
  root=insert(15,root);
  root=insert(19,root);
  
  root->l->data=17;
  root->r->data=8;
  */
  root=insert(3,root);
  root=insert(7,root);
  root=insert(2,root);
   
  root->data=2;
  root->l->data=3;
  inorder(root);
  
  swp1=swp2=NULL;
  //inorder(root);
  first(root);
  second(root);
  cout<<"swp1:"<<swp1->data<<" "<<"swp2: "<<swp2->data<<endl;
  int t=swp1->data;
  swp1->data=swp2->data;
  swp2->data=t;
  
 inorder(root);
  //system("pause");
  return 0;
}
  
