#include<iostream>
#include<algorithm>
using namespace std;
bool mycomp(int a,int b)
{
     if(a<b) return false;
     return true;
}
bool f(int arr[],int k,int n)
{
      int l=0;
     int h=n-1;
     
     while(l<h)
     {
       if(arr[l]+arr[h]==k) return true;
       if(arr[l]+arr[h]>k) 
       h--;
       else
       l++;
     }
     
     return false;
}
int main()
{
    int arr[]={2,3};
    int n=sizeof(arr)/sizeof(int);
    sort(arr,arr+n);
    
    for(int i=0;i<n;i++)
    cout<<arr[i]<<" ";
    int k;
    while(1) {
    cout<<"enter value of k: ";
    cin>>k;  
    
    cout<<f(arr,k,n);
              }
    
    system("pause");
}
