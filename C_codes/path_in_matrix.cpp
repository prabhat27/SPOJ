#include<iostream>
using namespace std;

int path(int ar[][4],int i,int j,int n,int m)
{
	if(i==n-1 && j==m-1)
	     return 1;
    int p=0,q=0;
    if(i+1<n && ar[i+1][j]==1)
        p=path(ar,i+1,j,n,m);
    if(j+1<m && ar[i][j+1]==1)
        q=path(ar,i,j+1,n,m);
    
    return p+q;
    
}

int main()
{
	int ar[][4]={1,0,1,1,1,1,1,1,1,0,1,1};
	cout<<path(ar,0,0,3,4);
	system("pause");
	return 0;
}
