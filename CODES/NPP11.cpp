/*
Given a NxN matrix with 0s and 1s. now whenever you encounter a 0 make the 
corresponding row and column elements 0. 
Flip 1 to 0 and 0 remains as they are. 
*/
#include<iostream>
using namespace std;
 
void removezero(int arr[][5],int n)
{
      int  rowzero=0;
      int columnzero=0;
      for(int i=0;i<n;i++)
    if(arr[0][i]==0)
      rowzero=1;
   
   for(int i=0;i<n;i++)
    if(arr[i][0]==0)
      columnzero=1;
      
     for(int i=1;i<n;i++)
     for(int j=1;j<n;j++)
     {
         if(arr[i][j]==0)
         {
            arr[0][j]=0;
            arr[i][0]=0;
         }
     }
    
      
    // cout<<rowzero<<" "<< columnzero<<endl;      
  for(int i=0;i<n;i++)
  {
      if(arr[0][i]==0)
      {
         for(int j=1;j<n;j++)
         {
            arr[j][i]=0;
         }
      }
  }
 //cout<<rowzero<<endl;
 if(rowzero)
 for(int i=0;i<n;i++)
 arr[0][i]=0;
 
 for(int i=0;i<n;i++)
  {
      if(arr[i][0]==0)
      {
         for(int j=1;j<n;j++)
         {
            arr[i][j]=0;
         }
      }
  }
   
  if(columnzero)
 for(int i=0;i<n;i++)
 arr[i][0]=0; 
      
}                                  
int main()
{
   int arr[][5]={
         1,1,1,1,1,
         1,1,1,0,0,
         1,1,1,1,1,
         1,1,0,1,1,
         1,1,1,1,1
         };
         
    removezero(arr,5);
    
    for(int i=0;i<5;i++)
     {
        for(int j=0;j<5;j++)
        cout<<arr[i][j]<<" ";
        
        cout<<endl;
     }  
    system("pause");
    return 0;
}     

  
