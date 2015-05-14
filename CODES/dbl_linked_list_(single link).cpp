#include<iostream>
using namespace std;

struct node
{
  int val;
  node *link;
}*start,*end,*pre;

void insert(int a)
{
  if(start==NULL)
  {
    node *ptr;
    ptr=new node;
    ptr->val=a;
    ptr->link=NULL;
    start=end=ptr;
  }
  else
  {
    node *ptr;
    ptr=new node;
    ptr->val=a;
    ptr->link=end;
    end->link=(node*)((int)(end->link)^(int)(ptr));
    end=ptr;
  }
}

int main()
{
    node *ptr1;
    ptr1=new node;
    cout<<ptr1<<" "<<(node*)((int)(ptr1)^(int)(NULL));
    start=NULL;
    int a;
    while(1)
    {
      cin>>a;
      if(a==0) break;
      
      insert(a);
    }
    
    node *ptr=end;
    node *pre=NULL;
    while(ptr!=NULL)
    {
      cout<<ptr->val<<" ";
      node *item=ptr;
      ptr=(node*)((int)(ptr->link)^(int)(pre));
      pre=item;
    }
    cout<<endl;
    
    
    system("pause");
    return 0;
}
    
