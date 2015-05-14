#include<iostream>
using namespace std;
void rotate(int arr[],int n,int k)
{
     int m=gcd(n,k),l;
     
}
       
int main()
{
    int arr[]={2,4,1,3,9,7,6};
    int n=sizeof(arr)/sizeof(int);
    int k=2;
    rotate(arr,n,k);
    
    for(int i=0;i<n;i++)
    cout<<arr[i]<<" ";
    
    system("pause");
}
