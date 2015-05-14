#include<iostream>
using namespace std;

struct node
{
	int data;
    node *l,*r;
}*root;

struct dllnode
{
  node *start,*end;
};

node* insert(int a,node *ptr)
{
   if(ptr==NULL)
	{
      ptr=new node;
	  ptr->data=a;
	  ptr->l=ptr->r=NULL;
	  return ptr;     
	}
   if(a>ptr->data)
     ptr->r=insert(a,ptr->r);
   else
     ptr->l=insert(a,ptr->l);
   return ptr;	
}

dllnode *BSTtoDLL(node *ptr)
{
   dllnode *temp,*temp1,*temp2;
   temp1=temp2=NULL;

  if(ptr->l==NULL&&ptr->r==NULL)
   {
	  temp=new dllnode;
      temp->start=temp->end=ptr;
      return temp;
   }
  temp=new dllnode;
  temp->start=temp->end=NULL;
  
  if(ptr->l!=NULL)
   {
     temp1=BSTtoDLL(ptr->l);
     temp1->end->r=ptr;
     ptr->l=temp1->end;
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
void inorder(node *ptr)
{
   if(ptr)
   {
	inorder(ptr->l);
	cout<<ptr->data<<" ";
	inorder(ptr->r);
   }
}
int find(int k,node *start,node *end)
{
	int c=0;
    while(1)
    {
	if(start==end)
      break;
    int ct=start->data+end->data; 
	if(ct==k)
     {
	   start=start->r;
	   end=end->l;
	   c++; 	
     }
    else if(ct>k)
      end=end->l;
    else
      start=start->r;
    
	if(start->l==end||end->r==start)
      break; 
    }
   return c;
}
int main()
{
	 root=NULL;
     int a;
	
	 cin>>a;
     while(a)
     {
	   root=insert(a,root);
	   cin>>a;  
     }  

    //inorder(root);
    
	dllnode *t;
   
   t=BSTtoDLL(root);
   
   node *ptr;
   ptr=t->start;
   while(ptr)
   {
     cout<<ptr->data<<" ";
     ptr=ptr->r;
   }
  int k;
  cout<<"now enter k :"<<endl;
  cin>>k;
  
  cout<<find(k,t->start,t->end)<<endl;

    return 0;
}
