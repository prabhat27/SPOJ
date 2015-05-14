/*
Level order print of tree without queue
*/
#include<iostream>
#include<queue>
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
	return ptr;
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
	cout<<ptr->data<<" ";
	inorder(ptr->r);
	}
}
int height(node* ptr)
{
   if (ptr==NULL)
       return 0;
   else
   {
     /* compute the height of each subtree */
     int lheight = height(ptr->l);
     int rheight = height(ptr->r);
 
     /* use the larger one */
     if (lheight > rheight)
         return(lheight+1);
     else return(rheight+1);
   }
} 
void levelorder(node *ptr,int level)
{
	if(ptr==NULL) return;
	if(level==1)
	{
    cout<<ptr->data<<" ";
	return;
    }
	levelorder(ptr->l,level-1);
	levelorder(ptr->r,level-1);
	return;
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
    int h=height(root);
    
 	for(int i=1;i<=h;i++)
	levelorder(root,i);

	return 0;
}
