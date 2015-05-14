#include<iostream>
#include<math.h>
using namespace std;
static int arr[10][2];

int pow(int a,int b)
{
  if(b==0) return 1;
  int s=a;
  for(int i=1;i<b;i++)
  s=s*a;
  
  return s;
}

bool iseven(int a)
{
     if(a%10==0) return true;
     
   int p=1,q=a;
  int m=(int)log10(a);
       while(q)
       {
        int base=(int)pow(10,m);
        int nt=q/base;
        p=p*nt;
        q=q%base;
        m--;
       }
       //cout<<p;
       if(p%2==0)
        return true;
        
        return false;
}
int brute(int a)
{
    int c=0;
  for(int i=1;i<=a;i++)
  if(iseven(i))
  c++;
  
  return c;
}

int find(int a)
{
  int s=0;
  int k=(int)log10(a);
  if(k==0)
  {
    for(int i=1;i<=a;i++)
   {
     if(i%2==0)
     s+=1;
   }
   return s;
 }
  int base=(int)pow(10,k);
  int rem=a%base;
  int nt=a/base;
  s+=arr[k][0];
  int j=1;
  while(j<nt)
  {
    if(j%2==0)
    s+=base;
    else
    s+=arr[k][1];
    j++;
  }
  if(j%2==0)
   s+=rem;  
  else
  {
    a=rem;
    int m=(int)log10(a);
    if(k!=m+1)
     s+=rem;
      else {
    while(m)
    {
      int base=(int)pow(10,m);
      int rem=a%base;
      int nt=a/base;
       j=0;
       while(j<nt)
       {
         if(j%2==0)
         s+=base;
         else
         s+=arr[m][1];
         j++;
       }
       if(j%2==0)
      { s+=rem; a=0; break; }
      else
      {
        a=rem;
        m--;
      }
   }
   for(int i=1;i<=a;i++)
   {
     if(i%2==0)
     s+=1;
   }    }
  }
   
   return s;
       
}

int main()
{
    
    
    arr[1][0]=5; arr[1][1]=5;
    arr[2][0]=70; arr[2][1]=75;
    for(int i=3;i<10;i++)
    {
      //arr[i]=arr[i-1]*6+int(pow(10,i-1))*4;
      arr[i][0]=arr[i-1][0]+arr[i-1][1]*5+int(pow(10,i-1))*4;
      arr[i][1]=arr[i][0]+int(pow(10,i-1))-arr[i-1][0];
    }
    
    //for(int i=1;i<10;i++)
    //cout<<arr[i][0]<<" "<<arr[i][1]<<endl;
    
    int t,a,b;
    //cout<<find(1001);
    
    scanf("%d",&t);
    while(t--)
    {
      scanf("%d%d",&a,&b);
       int ans,t=0;
     
       //cout<<p;
       if(iseven(a))
       t=1;
       
      // int ansb=brute(b)-brute(a)+t;
       ans=find(b)-find(a)+t;
       //printf("%d\n",ans);
      // cout<<iseven(a)<<brute(b)<<" "<<brute(a)<<endl;
       printf("%d\n",ans);
       //printf("%d\n",ansb);
    }
    
    //system("pause");
    return 0;
}
