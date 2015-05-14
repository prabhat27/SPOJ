#include<iostream>
using namespace std;

struct node
{
   int data;
   node *l,*r;	
}*root,*ptr;

node* insert(node *ptr,int a)
{
	//cout<<"RAM";
   	if(ptr==NULL)
   	 {
   	    //cout<<"SHYAM";
   	   ptr=new node;
   	   ptr->data=a;
   	   ptr->l=ptr->r=NULL;
   	   return ptr;
   	 }
   	 if(a>ptr->data)
   	  ptr->r=insert(ptr->r,a);
   	 if(a<=ptr->data)
	  ptr->l=insert(ptr->l,a);	
	  
	  //cout<<"GHANSHYAM";
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
int main()
{
	int n=1;
	root=NULL;
	while(n)
	{
		cin>>n;
		root=insert(root,n);	
	}
  
   inorder(root);	 
	 
}
