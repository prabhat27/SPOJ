#include<iostream>
using namespace std;
struct node
{
	char data;
	node *nxt;
}*start;
void insert(char ch)
{
  node *ptr;
  ptr=new node;
  ptr->data=ch;
  ptr->nxt=NULL;
  if(start==NULL)
  start=ptr;
  else
  {
	ptr->nxt=start;
	start=ptr;
  }
}
void display(node *ptr)
{
	while(ptr)
    {
	cout<<ptr->data<<" ";
	ptr=ptr->nxt;
    }
}
int main()
{
	insert('d');
	insert('c');
	insert('b');
	insert('a');
	display(start);
	node *ptr,*nptr,*temp;
	ptr=start;
	nptr=NULL;
	while(ptr)
	{
	temp=ptr;
	ptr=ptr->nxt;
	temp->nxt=nptr;
	nptr=temp;
	}
	cout<<endl;
	display(nptr);
	
	return 0;
}

