/*
Given a dictionary of words and an input string, find the longest prefix of the string which is also a word in dictionary.

Examples:

Let the dictionary contains the following words:
{are, area, base, cat, cater, children, basement}

Below are some input/output examples:
--------------------------------------
Input String            Output
--------------------------------------
caterer                 cater
basemexy                base
child                   < Empty >

*/

#include<iostream>
#include<cstdio>
#include<string.h>
using namespace std;
struct node
{
     int end;
     node *next[26];
}*root;
node *create()
{
     node *ptr;
     ptr=new node;
     ptr->end=0;
    for(int i=0;i<26;i++)
      ptr->next[i]=NULL;
      
      return ptr;
}
void insert(string str)
{
   int l=str.length();
   node *ptr=root;
   for(int i=0;i<l;i++)
   {
       int k=str[i]-'a';  
       if(ptr->next[k]==NULL)
       {
          ptr->next[k]=create();
          ptr=ptr->next[k];
       }
       else
          ptr=ptr->next[k];
   }
   ptr->end=1;
}
        
node* find(string str)
{
    int l=str.length();
   node *ptr=root,*nptr=NULL;
   for(int i=0;i<l;i++)
   {
       int k=str[i]-'a';
       if(ptr->next[k]==NULL)
        return nptr;
       ptr= ptr->next[k];
        if(ptr->end==1)
         nptr=ptr;
   }
    if(ptr->end==1) return ptr;
    
    return NULL;
}       
int main()
{
    root=create();
    //INSERT WORDS INTO THE DICTIONARY
    int n;
    string str;
    cin>>n;
    
    for(int i=0;i<n;i++)
    {
      cin>>str;
      insert(str);
    }
    
    cout<<"NOW TIME TO FIND PREFIX : "<<endl;
    //FINDING PREFIX
    //cin>>n;
    for(int i=0;i<10;i++)
    {
       cin>>str;
       node *ptr= find(str);
       node *temp=root;
       if(ptr!=NULL)
       {
        for(int i=0;i<str.length();i++)
       {
         if(temp==NULL)
          { 
            cout<<"No prefix \n";
             break;
          }
          cout<<str[i];
          temp=temp->next[str[i]-'a'];
          if(temp==ptr) break;
       }
       cout<<endl<<endl;
       }
       else
       cout<<"No prefix \n";
    }
    
    system("pause");
    return 0;
}
    
