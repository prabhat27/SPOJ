/*
reverse a linked list
*/
#include<iostream>
using namespace std;
struct node
{
       char data;
       node *next;
       }*start,*end,*ptr;
       
void insert(char ch)
{
     
  if(end==NULL)
  {
     ptr=new node;
     ptr->data=ch;
     ptr->next=NULL;
     end=start=ptr;
  }
  else
  {
     ptr=new node;
     ptr->data=ch;
     ptr->next=NULL;
     end->next=ptr;
     end=ptr;
  }
}
node* reverse(node *nptr)
{
    node *st=NULL;
    
    while(nptr)
    {
      //cout<<nptr->data;
      node *temp;
      temp=nptr;
      nptr=nptr->next; 
      temp->next=st;
      st=temp;
      
         
    }
    
   return st; 
    
}    
int main()
{
    end=start=NULL;
    insert('r');
    insert('a');
    insert('m');
    
    start=reverse(start);
    
    ptr=start;
    while(ptr)
    {
      cout<<ptr->data;
      ptr=ptr->next;
    }
    
    system("pause");
    return 0;
}
    
