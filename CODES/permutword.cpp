/*
permutation of a word
*/

#include<iostream>
#include<string.h>
#include<algorithm>
using namespace std;


char *sortstr(char *str)
{
  int l=strlen(str);
  int arr[l];
  for(int i=0;i<l;i++)
  arr[i]=(int)(str[i]);
  
  sort(arr,arr+l);
  
  for(int i=0;i<l;i++)
   str[i]=(char)(arr[i]);
   
   return str;
}

void permutation(char *str,char *ptr)
{
     int l1=strlen(str);
     int l2=strlen(ptr);
     
     if(l1==0)
     cout<<ptr<<endl;
     
     char pre='\0';
     str=sortstr(str);
     for(int i=0;i<l1;i++)
     {
       if(str[i]!=pre)
       {
         char temp[10];
         strcpy(temp,str);
         ptr[l2]=temp[i];
         ptr[l2+1]='\0';
         temp[i]=temp[l1-1];
         temp[l1-1]='\0';
         //cout<<temp<<" "<<ptr<<endl;
         permutation(temp,ptr);
       }
       pre=str[i];
     }
     
}
  
int main()
{
    char str[10],*str2;
    cin>>str;
    cout<<endl;
    
    str2=sortstr(str);
    
    char temp[10];
    temp[0]='\0';
    permutation(str2,temp);
    
    system("pause");
    return 0;
}
