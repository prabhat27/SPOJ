 #include<iostream>
using namespace std;

struct node{
       int info;
       node *next;
}*head;

node *cnn(int n)
{
       node *ptr=new node;
       ptr->info=n;
       ptr->next=NULL;
       return ptr;
}

void insert(int n)
{
       node *ptr,*p;
       ptr=cnn(n);
       p=head;
       if(head==NULL)
       head=ptr;
       else
       {
               while(p->next!=NULL)
               p=p->next;
               p->next=ptr;
       }
}

void display(node *p)
{
       while(p!=NULL)
       {
               cout<<p->info<<" ";
               p=p->next;
       }
}

int main()
{
       head=NULL;
       int a,n;
       cin>>a;
       for(int i=0;i<a;i++)
       {
               cin>>n;
               insert(n);
       }
       display(head);
}
