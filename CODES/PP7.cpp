/*
Rotate an array by K
*/
#include<iostream>
using namespace std;
void rotate(int arr[],int n,int k)
{
     int m=arr[0],i=0,t=n;
     while(t)
     {
      int j=i+k;
      if(j>=n)
       j=j-n;
      int v=m;
      m=arr[j];
      arr[j]=v;
      i=j;
      t--;
     }
} 
     
int main()
{
    int arr[]={1,2,3,4};
    rotate(arr,4,2);
    
    for(int i=0;i<4;i++)
    cout<<arr[i]<<" ";
    
    //system("pause");
    return 0;
}
