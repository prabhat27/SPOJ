#include<iostream>
#include<cstdio>
#include<string.h>
#include<algorithm>
using namespace std;
int gcd(int a,int b)
{
   if(b==0)
     return a;
   else
     return gcd(b, a%b);
} 
void rotate(int arr[],int n,int k)
{
	for(int i=0;i<gcd(n,k);i++)
    {
	int s=i,ni;
	int temp=arr[s];
	while(1)
	{
	//cout<<"here";
	if(s+k<n)
	ni=s+k;
	else
    ni=s+k-n;
	
	int l=arr[ni];
	arr[ni]=temp;
	temp=l;
	s=ni;
	if(s==i) break;
	}
  
    }
}
int main()
{
    int arr[]= {1,2,3,4};
	int n=sizeof(arr)/sizeof(int);
	int k=2;
	//rotate(arr,n,k);
	for(int i=0;i<n;i++)
	cout<<arr[i]<<" ";
	cout<<endl;
	cout<<f(NULL);
    //sort(arr,arr+3,greater<int>());
    
	return 0;
}
