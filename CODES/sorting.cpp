#include<iostream>
#include <cstdio>
#include <string.h>
#include <cmath>
using namespace std;

void swap(int *a,int *b)
{
	int t=*b;
	*b=*a;
	*a=t;
}

void bubblesort(int arr[],int n)
{
	//cout<<n<<"Ram";
	for(int i=0;i<n;i++)
	for(int j=0;j<n-i;j++)
	{
	 if(arr[j]>arr[j+1])
	 swap(&arr[j],&arr[j+1]);
    }
}
void selection(int arr[],int n)
{
  for(int i=0;i<n-1;i++)
  for(int j=i+1;j<n;j++)
  if(arr[i]>arr[j])
   swap(&arr[i],&arr[j]);
}
void insertion(int arr[],int n)
{
     for(int i=1;i<n;i++)
     {
       int x=arr[i];
       for(int j=i-1;j>=0;j--)
         if(x<arr[j])
         {
            arr[j+1]=arr[j];
            arr[j]=x;
         }
     }
}
int partition(int arr[],int l,int h)
{
    
    int key=arr[h];
    int last=h;
    while(l<h)
    {
      while(key>arr[l])
       l++;
      while(key<=arr[h])
       h--;
       
       if(l<h)
        swap(&arr[l],&arr[h]);
    } 
    swap(&arr[l],&arr[last]);
    
    return l;
}
void quicksort(int arr[],int l,int h)
{
     if(l<h)
     {
        int p=partition(arr,l,h);
        quicksort(arr,l,p-1);
        quicksort(arr,p+1,h);
     }
}  
int main()
{
	int arr[]={2,5,3,4,1,6,9,23,12,65,14};
	int size=sizeof(arr)/sizeof(int);
    
	//bubblesort(arr,size);
	//selection(arr,size);
	//insertion(arr,size);
	quicksort(arr,0,size-1); 
	
   for(int i=0;i<size;i++)
	cout<<arr[i]<<" ";
	
	system("pause");
	return 0;
}
