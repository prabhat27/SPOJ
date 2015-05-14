#include<iostream>
using namespace std;
struct node
{
   char data;
   node *next;
}*start;

void insert(char ch)
{
    node *ptr;
    ptr=new node;
    ptr->data=ch;
    ptr->next=NULL;
    if(start==NULL)
    start=ptr;
    else
    {
        ptr->next=start;
        start=ptr;
    }
} 
void print(node *ptr)
{
     while(ptr)
     {
       cout<<ptr->data;
       ptr=ptr->next;
     }
}
int length(node *ptr)
{
    int l=0;
    while(ptr)
    {
     l++;
     ptr=ptr->next;
    }
    return l;
}
node *findmid(node *ptr,int l)
{
    int t=(l-1)/2;
    while(t)
    {
      ptr=ptr->next;
      t--;
    }
    return ptr;
} 
 /*              
bool checkpalin(node *ptr)
{
     int l=length(ptr);
     if(l==1) return true;
     node* mid=findmid(ptr,l);
     reverse(mid->next);
     //cout<<"length"<<l<<" mid-data "<<mid->data<<endl;
     node *fh,*sh;
     fh=ptr;
     sh=mid->next;
     //cout<<"HERE "<<sh->data;
     bool ans=false;
     for(int i=0;i<l/2;i++)
     {
       ans=(fh->data==sh->data);
       if(!ans)  return ans;
       fh=fh->next;
       sh=sh->next;
     }
     return ans;
}
  */   
int main()
{
    start=NULL;
    insert('r');
    insert('a');
    insert('d');
    //insert('a');
    insert('r');
    //print(start);
    //cout<<checkpalin(start);
    cout<<sizeof("string");
    system("pause");
    return 0;
}
    
