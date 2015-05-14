/*
ROTATE AN ARRAY BY 90 DEGREE
*/
#include<iostream>
using namespace std;
int arr[][2]={1,2,3,4};

void rotate(int sr,int er)
{
  if(sr>=er)  return;
  
  int n=er+1-sr;
  int temp[n];
  int t=0;
  for(int i=er;i>=sr;i--)
  {
    temp[t++]=arr[i][er];
    arr[i][er]=arr[sr][i];
  }
  /*
  for(int i=0;i<t;i++)
  cout<<temp[i]<<" ";
  cout<<endl;
  */
   t=0;
   
  for(int i=sr;i<er;i++)
  {
    int tm=arr[er][i];
    arr[er][i]=temp[t];
    temp[t++]=tm;
  }
  /*
  for(int i=0;i<t;i++)
  cout<<temp[i]<<" ";
  cout<<endl;
  */
  t=0;
  
  for(int i=sr;i<er;i++)
  {
    int tm=arr[i][sr];
    arr[i][sr]=temp[t];
    temp[t++]=tm;
  }
  /*
  for(int i=0;i<t;i++)
  cout<<temp[i]<<" ";
  cout<<endl;
  */
  int m=t-1;
  for(int i=sr+1;i<er;i++)
  {
    arr[sr][i]=temp[m--];
  }
  
  rotate(sr+1,er-1);
}
    
int main()
{
   
   
   rotate(0,1);
   
   for(int i=0;i<2;i++)
   {
    for(int j=0;j<2;j++)
    cout<<arr[i][j]<<" ";
    cout<<endl;
   }
   system("pause");
   return 0;
}
