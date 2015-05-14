#include<iostream>
using namespace std;

struct node
{
  int val;
  node *next;
}*start1,*start2,*end1,*end2;

void insert(int a,int listno)
{
  if(listno==1)
  {
  
  if(start1==NULL)
  {
    node *ptr;
    ptr=new node;
    ptr->val=a;
    ptr->next=NULL;
    start1=end1=ptr;
  }
  else
  {
    node *ptr;
    ptr=new node;
    ptr->val=a;
    ptr->next=NULL;
    end1->next=ptr;
    end1=ptr;
    
  }
  
  }
  
  if(listno==2)
  {
  
  if(start2==NULL)
  {
    node *ptr;
    ptr=new node;
    ptr->val=a;
    ptr->next=NULL;
    start2=end2=ptr;
  }
  else
  {
    node *ptr;
    ptr=new node;
    ptr->val=a;
    ptr->next=NULL;
    end2->next=ptr;
    end2=ptr;
    
  }
  
  }
  
}
node *merge(node *ptr1,node *ptr2)
{
  if(ptr1==NULL)
   return ptr2;
  if(ptr2==NULL)
   return ptr1;
  node *res;
  
  if(ptr1->val>=ptr2->val) 
  {
    
    res=ptr2;
    res->next=merge(ptr1,ptr2->next);
  }
  else
  {
    res=ptr1;
    res->next=merge(ptr1->next,ptr2);
  } 
  
  return res;
    
}
int main()
{
  start1=NULL;
  start2=NULL;
    int a;
    cout<<"enter first sorted list : ";
    while(1)
    {
      cin>>a;
      if(a==0) break;
      insert(a,1);
    }
    cout<<"enter second sorted list : ";
    while(1)
    {
      cin>>a;
      if(a==0) break;
      insert(a,2);
    }
    
    node *start=merge(start1,start2);
    //node *start=start2;
    cout<<endl;
    
    while(start!=NULL)
    {
      cout<<start->val<<" ";
      start=start->next;
    }
    
    system("pause");
    return 0;
}
    
    
   
