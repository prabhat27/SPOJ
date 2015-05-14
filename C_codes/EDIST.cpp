/*
Given two strings of size m, n and set of operations replace (R), insert (I) and delete (D) all at equal cost.
 Find minimum number of edits (operations) required to convert one string into another.
*/
#include<iostream>
#include<string.h>
using namespace std;
static int dp[100][100];
int l1,l2;
char str1[100],str2[100];


int f(int i,int j)
{
   if(i>l1-1&&j>l2-1)  return 0;
   
   if(i>l1-1)  return l2-j;
   if(j>l2-1)  return l1-i;
   
   if(dp[i][j]!=-1)  return dp[i][j];
   
   if(str1[i]==str2[j])
     return dp[i][j]=f(i+1,j+1);
   
   return dp[i][j]=min(f(i+1,j+1),min(f(i,j+1),f(i+1,j)))+1;
}
   
int main()
{
    cin>>str1>>str2;
    
    l1=strlen(str1);
    l2=strlen(str2);
    
    for(int i=0;i<l1;i++)
    for(int j=0;j<l2;j++)
    dp[i][j]=-1;
    
    cout<<f(0,0)<<endl;
    
    
    system("pause");
    return 0;
}
