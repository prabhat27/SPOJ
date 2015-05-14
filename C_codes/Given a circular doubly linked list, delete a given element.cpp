#include<iostream>
using namespace std;
struct node
{
	int data;
	node* next;
}*start,*end;
void insert(int a)
{
	node *ptr;
	ptr=new node;
	ptr->data=a;
	if(start==NULL)
	{
	ptr->next=ptr;
	end=start=ptr;
	}
	else
    {
	end->next=ptr;
	ptr->next=start;
	end=ptr;
    }
}
void print(node *ptr)
{
	if(ptr==NULL) { cout<<"NONE"; return ;} 
	while(ptr!=end)
	{
	cout<<ptr->data<<" ";
	ptr=ptr->next;
	}
	cout<<ptr->data<<" ";
}
void deletenode(int a)
{
	node *ptr;
	ptr=start;
	if(ptr->data==a)
	{
	if(ptr->next->data==a)
     start=NULL;	//delete (ptr);
	else
    {
	 start->data=ptr->next->data;
	 start->next=ptr->next->next;
	 if(start->next==start) end=start;
	  return;
	//delete (ptr->next);
    }
	return;
	}
	while(ptr->next->data!=a)
	ptr=ptr->next;
	
	if(ptr->next==end) end=ptr;
	ptr->next=ptr->next->next;
	//delete (ptr->next);
}
int main()
{
   start=end=NULL;
   insert(2);
   insert(3);
   insert(5);
   insert(4);  /*	*/
   print(start);
   deletenode(4);
   cout<<endl;
   print(start);
}
