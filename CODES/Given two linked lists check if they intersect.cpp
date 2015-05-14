#include<iostream>
using namespace std;
struct node
{
	int data;
	node *next;
}*start1,*start2;

void insert(int a,int flag)
{
	node *ptr;
	ptr=new node;
	ptr->data=a;
	ptr->next=NULL;
	if(flag==1)
	{ 
     ptr->next=start1;
	 start1=ptr;
	}
	else
    {
	ptr->next=start2;
	start2=ptr;
    }
}

void print(node *ptr)
{
	while(ptr!=NULL)
	{
	cout<<ptr->data<<" ";
	ptr=ptr->next;
	}
}

int length(node *ptr)
{
	int l=0;
	while(ptr)
	{
	ptr=ptr->next;
	l++;
	}
	return l;
}
bool intersect(node *ptr1,node *ptr2)
{
	int l1=length(ptr1);
	int l2=length(ptr2);
	node *shift,*nshift;
	int diff;
	if(l1>l2)
	{
	diff=l1-l2;
	shift=ptr1;
	nshift=ptr2;
	}
	else
	{
	diff=l2-l1;
	shift=ptr2;
	nshift=ptr1;
	}
   while(diff--)
   {
	shift=shift->next;
   }
   //cout<<shift->data<<" ";
   bool ans=false;
   while(1)
   {
	if(shift==NULL||nshift==NULL)  return false;
	if(shift==nshift) return true;
	shift=shift->next;
	nshift=nshift->next;
   }
}
int main()
{
 	start1=start2=NULL;
	insert(7,1);insert(6,1);insert(5,1),insert(6,1);
	insert(1,2);insert(2,2);insert(3,2);
	//print(start1);
//	cout<<endl;
	//print(start2);
	start2->next=start1->next->next;
	cout<<intersect(start1,start2);
	return 0;
}
