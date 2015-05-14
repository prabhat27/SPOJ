/*
FRACTION TO RATIONAL NUMBER
*/
#include<iostream>
using namespace std;

int gcd(int a,int b)
{
  if(a%b==0)  return b;
  
  return gcd(b,a%b);
}

void rational(double n)
{
   int a=1;

   while((n-(int)(n))>0.0000001)
   {
     //cout<<(n-(int)(n))<<endl;
     a=a*10;
     n=n*10;
   }
   int m=gcd(int(n),a);
   cout<<n/m<<"/"<<a/m<<endl;
   
   return;
}
int main()
{
    //cout<<gcd(125,1000);
    while(1)
    {
     double n;
     cin>>n;
     rational(n);
    }
    system("pause");
    return 0;
}
