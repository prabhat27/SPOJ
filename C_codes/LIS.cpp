#include<iostream>
using namespace std;
int arr[] = {0, 8, 4, 12, 2, 10, 6, 14, 1, 9, 5, 13, 3, 11, 7, 15};//{ 18, 22, 9, 17, 21, 50, 51};
int n = sizeof(arr)/sizeof(arr[0]);
int dp[100];

int lis(int i)
{
  //cout<<i<<endl;
  if(i>=n) return 0;
  
  if(dp[i]!=-1) return dp[i];
  
  int ans=0;
  
  for(int j=i+1;j<n;j++)
  {
    if(arr[j]>arr[i])
     {
        ans=max(ans,1+lis(j));
     }
  }
  
  return dp[i]=ans;
}

int main()
{
  int ans=0;
  
  for(int i=0;i<n;i++)
  dp[i]=-1;
 
  for(int i=0;i<n;i++)
  {
     cout<<lis(i)<<" ";
     ans=max(ans,1+lis(i));
  }
  
  cout<<endl<<ans<<endl;
  
  //cout<<lis(0);
  system("pause");
  return 0;
} 
