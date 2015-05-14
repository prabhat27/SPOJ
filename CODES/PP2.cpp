/*
Given a string, find the minimum number of characters to be inserted to convert it to palindrome.
*/

#include<iostream>
#include<cstdio>
#include<string.h>
using namespace std;
string str;

int find(int l,int h)
{
    //cout<<"RAM";
    if(l>=h)
     return 0;
    
    if(str[l]==str[h])
     return find(l+1,h-1);
    
    return 1+min(find(l+1,h),find(l,h-1));
} 
int main()
{
    //cout<<int('a');
    
   while(1)  { 
    cin>>str;
    int l=str.length();
    cout<<find(0,l-1)<<endl;
    
             }
             
    system("pause");
    return 0;
}
