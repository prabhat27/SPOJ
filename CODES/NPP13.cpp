/*
Reverse a Linked List without making recursive calls.
*/

#include<iostream>
using namespace std;
struct node
{
  int data;
  node *nxt;
}*start,*end;
void insert(int a)
{
  node *ptr;
  ptr=new node;
  ptr->data=a;
  ptr->nxt=NULL;
  
  if(end==NULL)
  start=end=ptr;
  else
  {
    end->nxt=ptr;
    end=ptr;
  }
}
node *reverse(node *ptr)
{
  node *nptr,*rstart;
  rstart=NULL;
  while(ptr)
  {
    nptr=ptr;
    ptr=ptr->nxt;
    nptr->nxt=rstart;
    rstart=nptr;
  }
  
  return rstart;
}
    
int main()
{
    start=end=NULL;
    int n;
    cin>>n;
    while(n)
    {
      insert(n);
      cin>>n;
    }
    
    node *ptr=reverse(start);
    while(ptr)
    {
      cout<<ptr->data<<" ";
      ptr=ptr->nxt;
    }
      
    system("pause");
    return 0;
}
  
