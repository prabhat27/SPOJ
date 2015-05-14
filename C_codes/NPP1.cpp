/*
You're given an array containing both positive and negative integers and 
required to find the sub-array with the largest sum. You are expected to
give O(N) time solution. Write a routine in C for the above.
*/

#include<iostream>
#include<cstring>
using namespace std;

int main()
{
    int arr[]={-1,3,-1,4};
    int n=sizeof(arr)/sizeof(int);
    int m=0,ans=-999;
    for(int i=0;i<n;i++)
    {
       if(arr[i]<0)
        {
          m=1;
          if(arr[i]>ans)
          ans=arr[i];
        }
       else
       m=0; 
    }
    if(m==1)
    cout<<ans<<endl;
    else
    {
    int sum=0;
    ans=0;
    for(int i=0;i<n;i++)
    {
      sum+=arr[i];
      if(sum<0)
       sum=0;
      if(sum>ans)
       ans=sum;
    } 
    cout<<ans<<endl;
   }
    system("pause");
    return 0;
}
