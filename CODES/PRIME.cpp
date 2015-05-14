#include<iostream>
#include <cstdio>
#include <string.h>
#include <cmath>
#include <algorithm>
#include<vector>
using namespace std;
bool prime[1000001];
void sieve(int n)
{
   //boolean[] prime=new boolean[n+1];
   //Arrays.fill(prime,true);
   prime[0]=false;
   prime[1]=false;
   int m=(int)sqrt(n);

   for (int i=2; i<=m; i++)
      if (prime[i])
         for (int k=i*i; k<=n; k+=i)
            prime[k]=false;

   return ;
} 
int main()
{
  memset(prime,true,sizeof(prime));
  sieve(100);
  
  for(int i=1;i<=10;i++)
  cout<<prime[i]<<endl;
  
  system("pause");
  return 0;
}
