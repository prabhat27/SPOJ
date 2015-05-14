/*
Find the Increasing subsequence of length three with maximum product
*/
#include<iostream>
using namespace std;
int insert_left_max(int arr[],int i,int key)
{
	int ans=0;
	for(int j=i-1;j>=0;j--)
	if(arr[j]<key)
	ans=max(ans,arr[j]);
	
    return ans;
}
int insert_right_max(int arr[],int i,int key,int n)
{
	int ans=0;
	for(int j=i+1;j<n;j++)
	if(arr[j]>key)
	ans=max(ans,arr[j]);
	
	return ans;
}
int f(int arr[],int n)
{
	int LG[n],RG[n];
	LG[0]=arr[0];
	for(int i=1;i<n;i++)
    LG[i]=insert_left_max(arr,i,arr[i]);
	
    RG[n-1]=arr[n-1];
	for(int i=n-2;i>=0;i--)
	RG[i]=insert_right_max(arr,i,arr[i],n);
	/*	
	cout<<"LG : "<<endl;
	for(int i=0;i<n;i++)
	cout<<LG[i]<<" ";
	
	cout<<endl<<"RG : "<<endl;
	for(int i=0;i<n;i++)
	cout<<RG[i]<<" ";
	*/
	int ans=0;
	for(int i=1;i<n-1;i++)
	ans=max(ans,arr[i]*LG[i]*RG[i]);
	return ans;
}
int main()
{
	int arr[] = {2,1,3,7,4,5};
	int n=sizeof(arr)/sizeof(int);
	cout<<f(arr,n);
	return 0;
}
