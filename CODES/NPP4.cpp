/*
Find an element in a sorted rotated integer array.
*/

#include<iostream>
using namespace std;

int arr[]={7,8,2,4,5};
//int arr[]={4,5,1,2,3};
int n=sizeof(arr)/sizeof(int);

int f(int low,int high)
{
    while(arr[low]>arr[high])
    {
       int mid=(low+high) >> 1;
       if(arr[mid]>arr[high])
        low=mid+1;
       else
        high=mid;
    }
    
    return low;
} 
bool find(int low,int high,int a)
{
   int s=f(low,high);
   //cout<<"1 starts at "<<s<<endl;
   //int mid=(low+high) >> 1;
   if(a>arr[high])
    high=s-1;
   else
    low=s;
   
   //cout<<"low "<<low<<" high "<<high<<endl;
   
    
   while(low<high)
   {
      int mid=(low+high) >> 1;
      if(a==arr[mid])
         return true;
      else if(a>arr[mid])
       low=mid+1;
      else
       high=mid;
   }
   if(arr[low]==a) return true;
   
   return false;
}    
   
int main()
{
    int a;
    while(1)
    {
       cin>>a;
       cout<<find(0,n-1,a)<<endl;
    }
   system("pause");
   return 0;
}
