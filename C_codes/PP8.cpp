/*
SQUAREROOT OF A NUMBER
*/
#include<iostream>
#include<cmath>
using namespace std;

double sqrtt(int n)
{
       if(n<0) return -1;
       
       double start=0,end=n,mid=(start+end)/2,error=0.000001;
       double a=mid*mid-n;
       while(abs(a)>error)
       {
          if(a>0)
           end=mid;
             
          else
            start=mid;
            
          mid=(start+end)/2;
          a=mid*mid-n;
       }
       
       return mid;
}  
             
       
int main()
{
    int n;
    while(1)
    {
      cin>>n;
      cout<<sqrtt(n)<<endl;
      cout<<sqrt(n)<<endl;
    }
    
    system("pause");
    return 0;
}
