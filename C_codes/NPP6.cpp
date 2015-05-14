/*
MIDDLE ELEMENT OF A CIRCULAR LINKED LIST
*/
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
      start=end=ptr;
     else
     {
       end->next=ptr;
       end=ptr;
     }
}

node *getMid(node *ptr)
{
  node *sptr,*fptr;
  sptr=fptr=ptr;
  if(ptr->next==ptr||ptr->next->next==ptr)
   return ptr;
   int n;
   //cout<<end->next<<" "<<start<<endl;
  while(1)
  {
        if(fptr->next==ptr)
         break;
        //cout<<"The greatest thing i have ever seen :"<<(fptr->next->next==ptr)<<endl;
        if(fptr->next->next==ptr)
         break;
        sptr=sptr->next;
        fptr=fptr->next->next;
        //cin>>n;
  }
  
  return sptr;
}                                               
  
       
int main()
{
  start=end=NULL;
  int n;
  while(1)
  {
      cin>>n;
      if(n==0)
       break;
      insert(n);
  }
  end->next=start;
  
  node *ptr;
  ptr=getMid(start);
  //ptr=start;
 
   cout<<ptr->data<<endl;
 
  system("pause");
  return 0;
}        
