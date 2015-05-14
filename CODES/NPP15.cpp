/*
Modified 2 color sort problem i.e. you are given an array of integers
Containing only 0s and 1s.You have to place all the 0s in even position 
and 1s in odd position. And if suppose, no. of 0s exceed no. of 1s or vice 
versa then keep them untouched. Do that in a single pass and without taking 
extra memory (modify the array in-place). 

*/
#include<iostream>
using namespace std;
void swap(int *a,int *b)
{
     int t=*a;
     *a=*b;
     *b=t;
}
int main()
{
    int arr[]={1,0,1,0,1,0};
    int n=sizeof(arr)/sizeof(int);
    
    int ep=0;
    int op=1;
    
    int i=0;
    while(ep<n&&op<n)
    {
      while(arr[ep]==0)
      ep=ep+2;
      while(arr[op]==1)
      op=op+2;
      
      if(ep<n&&op<n)
       swap(&arr[ep],&arr[op]);
    }
    for(int i=0;i<n;i++)
    cout<<arr[i]<<" ";
    
    system("pause");
    return 0;
}
