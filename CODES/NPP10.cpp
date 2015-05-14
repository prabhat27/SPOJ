/*
Given a sorted, shifted array find the minimum element
*/

#include<iostream>
using namespace std;

int minimum(int arr[],int n)
{
   int low=0,high=n-1;
   int times=0;   
   while(arr[low]>arr[high])
   {
      times++;
      int mid=(low+high)>>1;
      
      if(arr[mid]>arr[high])
       low=mid+1;
      else
       high=mid;
   }
   
   return arr[low];
}   
int main()
{
    int arr[]={11,1,5,7,9,10};
    int n=sizeof(arr)/sizeof(int);
    
    cout<<minimum(arr,n)<<endl;
    
    system("pause");
    return 0;
}
