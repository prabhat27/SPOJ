#include<iostream>
#include <cstdio>
#include <string.h>
#include <cmath>
using namespace std;
double arr[1001][2006];
double find(int n,int k)
{
  
if (n == 0)
return k == 0 ? 100 : 0;
if (k <= 0)
return 0;
if (arr[n][k] > -0.5)
return arr[n][k];
return arr[n][k]=(find(n-1,k-1)+find(n-1,k-2)+find(n-1,k-3)+find(n-1,k-4)+find(n-1,k-5)+find(n-1,k-6))/6.0;

} 
  
int main()
{
  int t,n,k;
  scanf("%d",&t);
  int a=sizeof(arr);
  cout<<a;
  memset(arr,-1,sizeof(arr));
  while(t--)
  {
    scanf("%d%d",&n,&k);
    
    if(n>=1001||k>=2002)
     printf("0\n");
      
    
    else 
    {
      int v;
      v=find(n,k);
     printf("%d\n",v);
      
    }
    
  }
  
  system("pause");
  return 0;
} 


