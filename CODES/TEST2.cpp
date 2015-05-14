#include<iostream>
using namespace std;
struct node
{
  int data;
  node *next;
}*start,*end;
void insert(int a)
{
  node *ptr;
  ptr=new node;
  ptr->data=a;
  ptr->next=NULL;
  
  if(end==NULL)
   end=start=ptr;
  else
   {
     end->next=ptr;
     end=ptr;
   }
}

void sortlist(node *ptr)
{
     int z=0;
     while(ptr)
     {
        if(ptr->data==0)
         z++;
         
         ptr=ptr->next;
     }
     //cout<<endl<<z<<endl;
     int t=0;
     
     ptr=start;
     while(ptr)
     {
        if(t<z)
        {
         ptr->data=0;
         t++;
        }
        else
         ptr->data=1;
         
         ptr=ptr->next;
     }
     
} 
     
        
int main()
{
  start=end=NULL;
  insert(0);
  insert(0);
  insert(1);
  insert(0);
  insert(1);
  insert(0);
  
  sortlist(start);
  
  node *ptr=start;
  while(ptr)
  {
    cout<<ptr->data<<" ";
    ptr=ptr->next; 
  }
  
  system("pause");
  return 0;
} 
  
