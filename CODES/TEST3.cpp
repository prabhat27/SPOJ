#include<iostream>
using namespace std;
int arr[][3]={1,2,3,4,5,6,7,8,9};
int n=sizeof(arr)/sizeof(arr[0]);

void rotate(int l,int h)
{
     if(l>=h)
      return;
      
     int temp[h-l+1];
     int t=0;
     for(int i=h;i>=l;i--)
      {
        temp[t++]=arr[i][h];
        arr[i][h]=arr[l][i];
      }
      
     t=0;
     for(int i=l;i<h;i++)
     {
        int m=arr[h][i];
        arr[h][i]=temp[t];
        temp[t++]=m;
     }
      t=0;
     for(int i=l;i<h;i++)
     {
        int m=arr[i][l];
        arr[i][l]=temp[t];
        temp[t++]=m;
     }
    
     t=0;
     for(int i=h;i>l;i--)
     {
       arr[l][i]=temp[t++];
     }
     
     rotate(l+1,h-1);
         
}
      
int main()
{
   rotate(0,2);
   
  // cout<<"temp: ";
   
   for(int i=0;i<n;i++)
   {
           
      for(int j=0;j<n;j++)
      cout<<arr[i][j]<<" ";
      
      cout<<endl;
   }
   
   system("pause");
   return 0;
}
