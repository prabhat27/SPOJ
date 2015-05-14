#include<iostream>
#include<cstdio>
#include<math.h>
using namespace std;

long long popcount(long long n, long long d) 
{
  long long result = 0;
  while (n != 0) {
    result += ((n%10) == d);
    n /= 10;
  }
  return result;
}



long long find(long long n)
{
  long long result=0,b,c,a;
  long long i=1;
  while(1)
  {
    //cout<<"RAM";
    b=n/i;
    c=n%i;
    a=b/10;
    b=b%10;
    
    if (a==0)
     return result;

    if (b==0)
      result=result+((a -1)*i +c+1);
        
    else
      result=result+a*i;

        i*= 10;
   }
}


long long count(long long n, long long d) {
  if (n < 10) return (d > 0 && n >= d);

  if ((n % 10) != 9) return popcount(n, d) + count(n-1, d);

  return 10*count(n/10, d) + (n/10);
}


int main()
{
    int t,a,b;
    
  scanf("%d",&t);
  while(t--)
  {
    scanf("%d%d",&a,&b);
    
    long long ans=find(b)-find(a)+popcount(a,0);
    //long long ans1=count(b,0)-count(a,0)+popcount(a,0);
    printf("%lld\n",ans);
    //printf("%lld\n",ans1);
    
  }
  
  
  //system("pause");
  return 0;
}
