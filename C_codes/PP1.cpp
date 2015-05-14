#include<iostream>
#include<string.h>
using namespace std;
int arr[100][100];
int dp[100][100];
char path[100][100];
int m,n;

int find(int i,int j)
{
   if(i==m-1&&j==n-1)
   {
   	path[i][j]='S';
    return dp[i][j]=(arr[i][j]==1);
   }
	
   int rt,dn;
   if(dp[i][j]!=-1) return dp[i][j];
   
   if(i==m-1)  // CANNOT GO DOWN;
   {
   	  path[i][j]='R';
      return dp[i][j]=(arr[i][j]==1)+find(i,j+1);
   }
   
   if(j==n-1) //CANNOT GO RIGHT;
   {
   	path[i][j]='D';
    return  dp[i][j]=(arr[i][j]==1)+find(i+1,j);
   }
    
   rt=find(i,j+1);
   dn=find(i+1,j);
   if(rt>dn)
    path[i][j]='R';
   else
    path[i][j]='D'; 
    
   return dp[i][j]=(arr[i][j]==1)+max(rt,dn);
    		
}
int main()
{

  memset(dp,-1,sizeof(dp));	
  cin>>m>>n;
  
  for(int i=0;i<m;i++)
  for(int j=0;j<n;j++)
  cin>>arr[i][j];
  
  cout<<find(0,0)<<endl;
  
 /* 
  for(int i=0;i<m;i++)
  {
   for(int j=0;j<n;j++)
   cout<<path[i][j]<<" ";
   cout<<endl;
  }
  */
  int i=0,j=0;
  while(path[i][j]!='S')
  {
  	cout<<path[i][j]<<" ";
  	if(path[i][j]=='R')
  	 j=j+1;
  	else
	 i=i+1;  
  }
  
}
