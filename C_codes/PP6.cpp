/*
Implement a stack having findMiddle operation as well, which returns middle element of stack on O(1) time.
*/
#include<iostream>
using namespace std;
struct node
{
       int data;
       node *l,*r;
       }*start,*mid,*last;
int top=-1;
       
void push(int a)
{
     if(last==NULL)
     {
       node *ptr;
       ptr=new node;
       ptr->data=a;
       ptr->l=ptr->r=NULL;
       start=mid=last=ptr;
       top++;
     }
     else
     {
         node *ptr;
         ptr=new node;
         ptr->data=a;
         ptr->l=last;
         last->r=ptr;
         last=ptr;
         top++;
         if(top%2==0)
          mid=mid->r;
     }
}
void pop()
{
     if(top==-1)
      cout<<"\nSTACK EMPTY\n";
     else
     {
         last=last->l;
         last->r=NULL;
         
         if(top%2==0)
         mid=mid->l;
         
         top--;
     }
}
int getmid()
{
    return mid->data;
}
                           
int main()
{
    int op,a;
    start=mid=last=NULL;
     
     
    do
    {
      cout<<"ENTER YOUR OPERATION\n";
      cout<<"1.PUSH\n2.POP\n3.GET MID\n4.EXIT\n";
      cin>>op;
      switch(op)
      {
        case 1:  cin>>a; push(a); break; 
        case 2: pop(); break;
        case 3: cout<<getmid()<<endl; break;
        case 4:break;
        default : cout<<"\nPlease enter correct option\n"; 
      }
    }while(op!=4);

    system("pause");
    return 0;
}
                          
