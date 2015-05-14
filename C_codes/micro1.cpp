/*
Input: s= “aaabbbaacc”
Output s=”a3b3a2c2”
*/

#include<iostream>
#include<string.h>
using namespace std;
int main()
{
  string str;
  cin>>str;
  int c=1;
  char cur,pre=str[0];
  cout<<str[0];
  for(int i=1;i<str.length();i++)
  {
    if(str[i]==pre)
     {
       c++;
     }
    else
     {
        cout<<c<<str[i];
        c=1;
     }
     pre=str[i];
  }
  cout<<c;     
       
  system("pause");
  return 0;
}
