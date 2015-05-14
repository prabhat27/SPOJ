/*
CONVERT A BST INTO DLL
*/

#include<iostream>
using namespace std;

struct node
{
   int data;
   node *l,*r;	
}*root,*ptr;

struct nodeg
{
  node *start,*end;
};

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

nodeg *BSTtoDLL(node *ptr)
{
   nodeg *temp,*temp1,*temp2;
   temp1=temp2=NULL;
   if(ptr->l==NULL&&ptr->r==NULL)
   {
      temp=new nodeg;
      temp->start=temp->end=ptr;
      return temp;
   }
   
   temp=new nodeg;
   temp->start=temp->end=NULL;
   
   if(ptr->l!=NULL)
   {
     temp1=BSTtoDLL(ptr->l);
     //cout<<"RAM";
     temp1->end->r=ptr;
     ptr->l=temp1->end;
        //cout<<"qRAM";
     temp->start=temp1->start;
     if(ptr->r==NULL)
     temp->end=ptr;   
   }
   
   if(ptr->r!=NULL)
   {
      temp2=BSTtoDLL(ptr->r);
      ptr->r= temp2->start;
      temp2->start->l=ptr;
      temp->end=temp2->end;
      if(ptr->l==NULL)
      temp->start=ptr;
      
   }
    return temp;
}    
   
   
   
int main()
{
	int n=1;
	root=NULL;
	while(1)
	{
		cin>>n;
		if(n==0) break;
		root=insert(root,n);	
	}
  
   //inorder(root);
   nodeg *t;
   
   t=BSTtoDLL(root);
   
   node *ptr;
   ptr=t->start;
   while(ptr)
   {
     cout<<ptr->data<<" ";
     ptr=ptr->l;
   }
   
   //system("pause");
   return 0;	 
	 
}
