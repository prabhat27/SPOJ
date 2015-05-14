#include<iostream>
#include <cmath>
#include <algorithm>
#include<vector>
#include <cstdio>
#include <string.h>
using namespace std;

static unsigned long long ans[1000001];
void createnum()
{
     
  for(int i=2;i<1000000;i++)
  {
   for(int j=i+i;j<1000000;j+=i)
    ans[j]+=i;
    
   ans[i+1]+=ans[i];
  }
}
  
int main()
{
  for(int i=1;i<1000000;i++)
    ans[i]=1;
    
  createnum();
  
  int tc,n;
  scanf("%d",&tc);
    while(tc--)
    {
        scanf("%d",&n);
        printf("%llu\n",ans[n]);
    }
  
    //system("pause");
    return 0;
}  
