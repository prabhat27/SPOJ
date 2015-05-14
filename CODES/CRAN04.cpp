#include<iostream>
#include <cstdio>
#include <string.h>
#include <cmath>
using namespace std;
unsigned long long out[1234567];
int main()
{
  int t,n,k;
  string s;
  
  scanf("%d",&t);
  while(t--)
  {
    scanf("%d%d",&n,&k);
    //cout<<"RAM";
    cin>>s;
    unsigned long long sum=0;
    int ls=0;
    if(k>n)
    cout<<"0"<<endl;
    else
    {
      if(k!=0)
       {
         for(int i=0;i<=n;i++)
          out[i]=0;
          //cout<<"RAM";
          if(s[0]=='0')
           {
             //cout<<"ARAM";
              out[0]++;
              ls=0;
            }
           else
            {
             
              out[1]++;
              ls=1;
            }
            
            for(int i=1;i<n;i++)
             {
               if(s[i]=='0')
                 out[ls]++;
     
               else
                 out[++ls]++;
                 
             }
             
        sum=(unsigned long long)(out[k]+out[k]*out[0]);
        for(int i=k+1;i<=ls;i++)
         sum+=(unsigned long long)(out[i]*out[i-k]);
        }
      else
       {
         unsigned long long cnt=0;
         for(int i=0;i<n;i++)
        {
          //scanf("%c",&ch);
          if(s[i]=='0')
          cnt++;
          else
           {
            sum+=(unsigned long long)((cnt*(cnt+1))/2);
            cnt=0;
           }
          
        }
        sum+=(unsigned long long)((cnt*(cnt+1))/2);
 
        }
        printf("%llu\n",sum);
       }
    }
  
  
  //system("pause");
  return 0;
}

