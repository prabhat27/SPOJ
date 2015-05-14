#include<iostream>
#include <cmath>
#include <algorithm>
#include<vector>
#include <cstdio>
#include <string.h>
using namespace std;

static int ans[10000001];


bool prime[10000000];
static int primelist[5000000]; 
void sieve(int n)
{
   prime[0]=false;
   prime[1]=false;
   int m=(int)sqrt(n);

   for (int i=2; i<=m; i++)
      if (prime[i])
         for (int k=i*i; k<=n; k+=i)
            prime[k]=false;

   return ;
} 

void createspf()
{
 for(int i=0;i<664579;i++)
 {
  int m=primelist[i];
  for(int j=m;j<10000000;j+=m)
   if(ans[j]==-1)
    ans[j]=m;
 }
}
int main()
{
    memset(prime,true,sizeof(prime));
    sieve(10000000);
    int k=0;
    for(int i=1;i<10000000;i++)
    {
         if(prime[i])
         {
           primelist[k]=i;
           k++;
         }
    }
    //cout<<k;
    
    int tc,n;
    //memset(ans,2,sizeof(ans));
    for(int i=2;i<10000000;i++)
    ans[i]=-1;
    
    ans[1]=1;
    createspf();
   //cout<<ans[999973];
   
    scanf("%d",&tc);
    while(tc--)
    {
        scanf("%d",&n);
        unsigned long long int s=0;
        for(int i=3;i<=n;i+=2)
        {
         s+=ans[i];
        }
        s=s+2*(n/2);
        printf("%llu\n",s);
    }
  /**/
    //system("pause");
    return 0;
}  
            
            
    
