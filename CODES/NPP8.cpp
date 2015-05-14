/*
 Given two sorted linked list, create a third list which contains only those elements of first list, 
 which are not common with second list. Do this with O(n) time.
*/
#include<iostream>
using namespace std;
struct node
{
   int data;
   node *next;
}*strt1,*end1,*strt2,*end2,*strt3,*end3;

void insert(int a,int list)
{
   node *ptr;
   ptr=new node;
   ptr->data=a;
   ptr->next=NULL;
   if(list==1)
   {
     if(end1==NULL)
      strt1=end1=ptr;
     else
      {
         end1->next=ptr;
         end1=ptr;
      }
   } 
   if(list==2)
   {
     if(end2==NULL)
      strt2=end2=ptr;
     else
      {
         end2->next=ptr;
         end2=ptr;
      }
   } 
   if(list==3)
   {
     if(end3==NULL)
      strt3=end3=ptr;
     else
      {
         end3->next=ptr;
         end3=ptr;
      }
   } 
   return;
}

void newlist(node *ptr1,node *ptr2)
{
   if(ptr1==NULL)
    return;
    
   if(ptr2==NULL)
   {
      insert(ptr1->data,3);
      newlist(ptr1->next,NULL);
   }
   else
   {
      if(ptr1->data!=ptr2->data)
      {
         if(ptr1->data<ptr2->data)
         {
           insert(ptr1->data,3);
           newlist(ptr1->next,ptr2);
         }
         else
         newlist(ptr1,ptr2->next);
      }
      else
      newlist(ptr1->next,ptr2->next);
   }
   return;
} 
int main()
{
   strt1=end1=strt2=end2=strt3=end3=NULL;
   
   insert(1,1);
   insert(3,1);
   insert(5,1);
   insert(6,1);
   insert(7,1);
   
   node *ptr;
   ptr=strt1;
   while(ptr)
   {
      cout<<ptr->data<<" ";
      ptr=ptr->next;
   }
   cout<<endl;

   insert(2,2);
   insert(3,2);
   insert(4,2);
   insert(5,2);
   insert(6,2); 
   insert(8,2); 
   
   ptr=strt2;
   while(ptr)
   {
      cout<<ptr->data<<" ";
      ptr=ptr->next;
   }
   cout<<endl;
   
   newlist(strt1,strt2);
   
   ptr=strt3;
   while(ptr)
   {
      cout<<ptr->data<<" ";
      ptr=ptr->next;
   }
   cout<<endl;
   
   system("pause");
   return 0;
}
