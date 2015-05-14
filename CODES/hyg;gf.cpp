#include<iostream>
using namespace std;
int n=9,r,dp1[100000000],j,l1,l2;
int arr[]={2,5,3,7,11,78,10,13,6};
int f(int i)
{
//cout<<i<<endl;
if(i==n) return 0;
if(dp1[i]!=-1) { return dp1[i]; }

int ans=f(i+1);
int m=0;
for(int j=i+1;j<n;j++)
{
if(arr[j]>=arr[i])
ans=max(ans,f(j)+1);
m=1;
}
if(m==0)
return dp1[i]=1;

return dp1[i]=ans;
}

int main()
{
int i;
memset(dp1,-1,sizeof(dp1));
cout<<f(0)<<endl;
system("pause");
}
