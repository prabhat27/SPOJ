/*
Level order print of tree using queue
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
void print(queue<node *>&que)
{
	while(!que.empty())
    {
	node *ptr;
	ptr=que.front();
	cout<<ptr->data<<" ";
	que.pop();
	if(ptr->l!=NULL)
	que.push(ptr->l);
    if(ptr->r!=NULL)
	que.push(ptr->r);
    }
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
    queue<node*> que;
    que.push(root);
	print(que);

	return 0;
}
