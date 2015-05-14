#include<iostream>
using namespace std;
struct node
{
  int val;
  node *next;
}*start,*end;

void insert(int a)
{
     if(start==NULL)
     {
       node *ptr;
       ptr=new node;
       ptr->val=a;
       ptr->next=NULL;
       start=end=ptr;
     }
     else
     {
       node *ptr;
       ptr=new node;
       ptr->val=a;
       ptr->next=NULL; 
       end->next=ptr;
       end=ptr;
     }
}
node *reverse(node *ptr)
{
     if(ptr->next==NULL)
      {
        start=ptr;
        return ptr;
      }
      //cout<<"RAM"<<endl;
      node *temp;
      temp=ptr;
      
      
      node *nptr=reverse(ptr->next);
      //cout<<"SHAM"<<endl;
      temp->next=NULL;
      nptr->next=temp;
      
      return temp;
}
         
int main()
{
    start=NULL;
    int a;
    while(1)
    {
      cin>>a;
      if(a==0) break;
      
      insert(a);
    }
    node *ptr=start;
    while(ptr!=NULL)
    {
      cout<<ptr->val<<" ";
      ptr=ptr->next;
    }
    cout<<endl;
    
    end=reverse(start);
    
    ptr=start;
    while(ptr!=NULL)
    {
      cout<<ptr->val<<" ";
      ptr=ptr->next;
    }
    
    system("pause");
    return 0;
}

