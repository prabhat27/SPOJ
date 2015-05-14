#include<iostream>   //3N/2 COMPARISIONS
using namespace std; 
int max(int a,int b)
{
 if(a>b)  return a;
 else   return b;
}
int min(int a,int b)
{
 if(a>b)  return b;
 else   return a;
}
int main()
{
int n;
cin>>n;
int arr[n];
for(int i=0;i<n;i++)
cin>>arr[i];

int mx=-1,mn=100000;

for(int i=0;i<n;)
{
  if(i+1!=n)
   {
     if(arr[i]==max(arr[i],arr[i+1])) 
    {
     mx=max(mx,arr[i]);
     mn=min(mn,arr[i+1]);
    }
     else
    { 
     mx=max(mx,arr[i+1]);
     mn=min(mn,arr[i]);
    }
    i=i+2; 
   }
  else
   {
      mx=max(mx,arr[i]);
      mn=min(mn,arr[i]); 
      i++;
    }
}
cout<<"max :"<<mx;
cout<<"\nmin :"<<mn;
return 0;
}   
