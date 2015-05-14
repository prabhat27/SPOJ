/*
Check if a character link list is palindrome or not.
*/
#include<iostream>
using namespace std;
struct node
{
       char data;
       node *next;
}*start,*end;

int l;
void insert(char ch)
{
    node *ptr;
    if(end==NULL)
    {
        ptr=new node;
        ptr->data=ch;
        ptr->next=NULL;
        start=end=ptr;
        return;
    }
    
    ptr=new node;
    ptr->data=ch;
    ptr->next=NULL;
    end->next=ptr;
    end=ptr;
    return;
}

node *getMid(node *ptr)
{
     int m=(l-1)/2;
     int c=0;
     while(c<=m)
     {
       ptr=ptr->next;
       c++;
     }
     return ptr;
}

node *reverse(node *ptr)
{
  node *nptr;
  nptr=NULL;
  while(ptr)
  {
      node *temp;
      temp=ptr;
      ptr=ptr->next;
      temp->next=nptr;
      nptr=temp;
  }
  return nptr;
}
bool isPalindrome(node *ptr)
{
   bool hai=false;
    node *mid,*nptr;
    mid=getMid(ptr);
    nptr=reverse(mid);
    while(nptr)
    {
      if(nptr->data==ptr->data)
       hai=true;
      else
       return false; 
      //cout<<nptr->data;
      ptr=ptr->next;
      nptr=nptr->next;
    }
    return hai;
}       
int main()
{
  start=end=NULL;
  char str[100];
  cin>>str;
  
  l=strlen(str);
  
  for(int i=0;i<l;i++)
  insert(str[i]);
  
  cout<<isPalindrome(start);
  /*
  node *ptr;
  ptr=start;
  
  while(ptr)
  {
    cout<<ptr->data;
    ptr=ptr->next; 
  }
  */
  system("pause");
  return 0;
} 
      
