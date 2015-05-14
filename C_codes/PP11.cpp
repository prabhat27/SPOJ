/*
PRINT A 2D MATRIX IN SPIRAL ORDER
*/
#include<iostream>
using namespace std;
int main()
{
    int arr[][3]={1,2,3,8,9,4,7,6,5,11,12,13};
    int k=0,l=0,m=4,n=3;
    //cout<<arr[1][0]<<endl;
    while(k<m&&l<n)
    {
      //PRINTING FIRST ROW OF THE REMAINING MATRIX 
      for(int i=l;i<n;i++)
      cout<<arr[k][i]<<" ";
      //cout<<endl;
      k++;  
      //PRINTING LAST COLUMN OF THE REMAINING MATRIX
      for(int i=k;i<m;i++)
      cout<<arr[i][n-1]<<" ";
      //cout<<endl;
      n--;
      //PRINTING LAST ROW OF THE REMAINING MATRIX
      for(int i=n-1;i>=l;i--)
      cout<<arr[m-1][i]<<" ";
      //cout<<endl;
      m--;
      //PRINTING FIRST COLUMN OF THE REMAINING MATRIX
      for(int i=m-1;i>=k;i--)
      cout<<arr[i][l]<<" ";
      //cout<<endl;
      l++;
    }
      
         
    system("pause");
    
    return 0;
}
