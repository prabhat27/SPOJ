#include<iostream>
using namespace std;
int maxcontinuous(int arr[],int n)
{
	int maxsofar=arr[0];
	int maxtillhere=arr[0];
	int s,e;
	for(int i=1;i<n;i++)
	{
	maxtillhere=max(arr[i],maxtillhere+arr[i]);
	maxsofar=max(maxsofar,maxtillhere);
	if(maxsofar==maxtillhere)
     {
	    if(maxtillhere==arr[i])  s=i;
        e=i;
	 } 
	}
	cout<<"start"<<s<<" end"<<e<<endl;
	return maxsofar;
}
int main()
{
	int arr[]={-2, -3, 5, -1, -2, -1, 9, -3};
	int n=sizeof(arr)/sizeof(int);
	cout<<maxcontinuous(arr,n);
	return 0;
}
