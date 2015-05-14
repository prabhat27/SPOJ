/*
longest increasing subsequence O(nlog(n))
*/

#include<iostream>
using namespace std;
int arr[] ={ 18, 22, 9, 17, 21, 50, 51};// {0, 8, 4, 12, 2, 10, 6, 14, 1, 9, 5, 13, 3, 11, 7, 15};//
int n = sizeof(arr)/sizeof(arr[0]);
int out[100];
int t=1;

int main()
{
   for(int i=1;i<100;i++)
   out[i]=-1;
   
   out[1]=arr[0];
   
   for(int i=1;i<n;i++)
   {
     if(arr[i]>out[t])
      out[++t]=arr[i];
     else if(arr[i]<out[1])
      out[1]=arr[i];  
     else
      {
         int key=arr[i];
         int h=t;
         int l=1;
         while(1)
         {
           int m=(l+h) >> 1;
           if(key>out[m])
            l=m+1;
           else if(key<out[m]&&key>out[m-1])
            {
                out[m]=key;
                break;
            }
            else
             h=m;
          }
        }
     } 
        cout<<t<<endl;
        for(int i=1;i<=t;i++)
        cout<<out[i]<<" ";
        system("pause");
        return 0;
} 
           
           
