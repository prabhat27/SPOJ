#include<iostream>
using namespace std;
int arr[100];
void swap(int *a,int *b)
{
	cout<<a<<b<<endl;
	int t=*b;
	*b=*a;
	*a=t;
}
int partition(int l,int h)
{
	int x=arr[h];
	int i=l-1;
	
	for(int j=l;j<h;j++)
	{
	   if(arr[j]<=x)
	    {
	      i++;
	      swap(&arr[i],&arr[j]);
	    }
	}
	swap(&arr[i+1],&arr[h]);
	
	return i+1;
}
void quicksort(int l,int h)
{
  if(l<h)
   {
   	 int p=partition(l,h);
   	 quicksort(l,p-1);
   	 quicksort(p+1,h);
   }
}
int main()
{
  int n;
  /*int a=3,b=6;
  cout<<a<<" "<<b<<endl;
  swap(&a,&b);
  cout<<a<<" "<<b<<endl;
  */
  cin>>n;
  
  for(int i=0;i<n;i++)
  cin>>arr[i];
  
  quicksort(0,n-1);
  
  for(int i=0;i<n;i++)
  cout<<arr[i]<<" ";
  	
}
