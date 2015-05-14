/*
Lowest common ancestor in a BST
*/
#include<iostream>
using namespace std;
struct node
{
   int data;
   node *l,*r;
}*root;

node *insert(int a,node *ptr)
{
  if(ptr==NULL)
  {
    ptr=new node;
    ptr->data=a;
    ptr->l=ptr->r=NULL;
  }
  else if(a>ptr->data)
  ptr->r=insert(a,ptr->r);
  else
  ptr->l=insert(a,ptr->l);
  
  return ptr;
}
void inorder(node *ptr)
{
     if(ptr)
     {
       inorder(ptr->l);
       cout<<ptr->data<<" ";;
       inorder(ptr->r);
     }
}
int LCA(int l,int h,node *ptr)
{
     if(ptr==NULL)  return -1;
     
     if(l<ptr->data&&ptr->data<h)
      return ptr->data;
     
     else if(l>ptr->data)
     return LCA(l,h,ptr->r);
     
     else
     return LCA(l,h,ptr->l);
}
       
int main()
{
    root=NULL;
    int n;
    cin>>n;
    while(n)
    {
      root=insert(n,root);
      cin>>n;
    }
    //inorder(root);
    cout<<endl<<LCA(1,7,root);
    system("pause");
    return 0;
}
