#include<iostream>
using namespace std;
int floor(float a)
{
	return (int)(a);
}

int ceil(float a)
{
	if((a-(int)a)>0) return int(a)+1;
	return int(a);
}

void rotate(int a[][4],int n)
{
int f = floor((float)n/2);
int c = ceil((float)n/2);

  for (int x = 0 ;x<f;x++)
  for (int y = 0 ;y<c;y++)
   {  int temp = a[x][y];
      a[x][y]=a[n-1-y][x];
	  a[n-1-y][x]=a[n-1-x][n-1-y];
	  a[n-1-x][n-1-y]=a[y][n-1-x];
	  a[y][n-1-x]=temp;
   }
}

int main()
{
	int arr[][4]={1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16};
	//int arr[][3]={1,2,3,4,5,6,7,8,9};
	int n=4;
	rotate(arr,n);
	
	for(int i=0;i<n;i++)
	{
	for(int j=0;j<n;j++)
 	cout<<arr[i][j]<<"  ";
    cout<<endl;
    } 
}
