#include<iostream>
#include <cstdio>
#include <string.h>
#include <cmath>
using namespace std;

char buff[32];

struct node 
{
    int end;
    node *arr[26];
}*root,*ptr;

void insert(char *str)
{
   int l=strlen(str);
   int j=0;
   ptr=root;
   while(j<l)
     {
       //cout<<str[j];
       int m=str[j]-'a';        
       if(root==NULL)
       { 
        ptr=new node;
        ptr->end=0;
        
        for(int k=0;k<26;k++) 
          ptr->arr[k]=NULL;
          
        ptr->arr[m]=new node;
        root=ptr;
        ptr=ptr->arr[m];
         
        for(int k=0;k<26;k++) 
          ptr->arr[k]=NULL;
          
          ptr->end=0; 
       }
       else
       {
   
         if(ptr->arr[m]!=NULL)
         ptr=ptr->arr[m];
         else{
        if(ptr->end!=1)      
         ptr->end=0;
   
         ptr->arr[m]=new node;
         ptr=ptr->arr[m];
          for(int k=0;k<26;k++) 
          ptr->arr[k]=NULL;
          
          ptr->end=0;
             }
         
       }
       
      j++;
     }
     ptr->end=1;
    
}

node* find(char *str)
{
   int l1=strlen(str);
   int q=0,y=0;
   ptr=root;
   while(q<l1)
   { 
        int m=str[q]-'a';
        if(ptr->arr[m]==NULL)
        {return NULL;}
        else
         { ptr=ptr->arr[m];  y=1;}
         q++;
   }
   //if(ptr->end==1)
    //return ptr;
   //else
    return ptr;
}

int qlen,printed;

void print(node *ptr,int l)
{
  if(ptr->end==1&&l>qlen)
   { 
     buff[l] ='\0';
     puts(buff);  
     printed++;
   }
 for(int i=0;i<26;i++)
  {
      if(ptr->arr[i]!=NULL)
      {
          buff[l]=i+'a';
          print(ptr->arr[i],l+1);
      }
  }  
}

int main()
{
   	int n, i, cs, t, ret;
    char word[32];
    root=NULL;
   	scanf("%d", &n);
    
    for(i = 0; i < n; i++) 
    {
      scanf("%s", word);
      insert(word);
    }
    
   scanf("%d", &t); 
   
   for(int cs=1;cs<=t;cs++)
   {
     scanf("%s", word);
  	 printf("Case #%d:\n", cs);
     node* f=find(word);
     if(f==NULL)
      printf("No match.\n");
     else
      {
         //cout<<ptr->end;
         strcpy(buff, word);
         printed = 0;
         //printf("match.\n");
        print(f,qlen=strlen(word));
        if(!printed) printf("No match.\n");
        
      }
      //strcpy(buff,'\0');
      //memset(buff,'\0',sizeof(buff));
   }
     
   
    
    //system("pause");
    return 0;
}
    
