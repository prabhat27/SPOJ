/*
We have two sorted array. Without using additional memory we
 need to merge these two arrays such that the initial numbers are 
 in the 1st array and the remaining numbers are in the second array. 
 
 
 Put the small sized array as arr1;
 complexity=n*n+n*m;  ( n<m )

*/

#include<iostream>
using namespace std;

void merge(int arr1[],int n1,int arr2[],int n2)
{
  int p1=0;
  
  while(p1<n1)
  {
     while(arr1[p1]<arr2[0])
      p1++;
      
     int t=arr1[p1];
     arr1[p1]=arr2[0];
     p1++;
     
     int m=1;
     cout<<"t: "<<t<<" arr2[0]: "<<arr2[0]<<endl;
     while(arr2[m]<t&&m<n2)
     {
        arr2[m-1]=arr2[m];
        m++;
     }
     arr2[m-1]=t;
     
    //cout<<"p1: "<<p1<<" m: "<<m<<endl; 
  }
  
}
     
int main()
{
    int arr1[]={2,3,5,6};
    int arr2[]={1,4};
    int n1=sizeof(arr1)/sizeof(int);
    int n2=sizeof(arr2)/sizeof(int);
    
    merge(arr1,n1,arr2,n2);
    
    for(int i=0;i<n1;i++)
    cout<<arr1[i]<<" ";
    for(int i=0;i<n2;i++)
    cout<<arr2[i]<<" ";
    
    system("pause");
    return 0;
}
    
