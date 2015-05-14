/*
1.Replace all spaces (” “) in a string with \0
*/

#include<iostream>
#include<string.h>
using namespace std;
char ch1[100];
char *replace(char ch[],int l)
{
   int space=0;
   for(int i=0;i<l;i++)
   if(ch[i]==' ')
   space++;
   
   //char ch1[l+space];
   int m=0;
   int t=0;
   
   while(t<l)
   {
     if(ch[t]==' ')
     {
       ch1[m++]='\\';
       ch1[m++]='0';
     }
     else
      ch1[m++]=ch[t];
      
      t++;
   }
  
   ch1[m]='\0';
   //cout<<ch1;
   return ch1;
}
int main()
{

    char ch[] = {'t', 'h', 'e', ' ', 'd', 'o', 'g', ' ', ' ', ' ', ' ', ' ', ' '};
    cout<<endl<<replace(ch,strlen(ch));
    
    system("pause");
    return 0;
}
