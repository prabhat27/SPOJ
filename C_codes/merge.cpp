#include<iostream>
#include<time.h>
using namespace std;
void merge(int *arr,int l,int m,int u)
{
 for(int i=l;i<=m;i++)
 {
   int k=m+1;
   if(*(arr+i)>*(arr+k))
    {
      int t=*(arr+i),j;
      *(arr+i)=*(arr+k);
      for(j=k+1;j<=u;j++)
       {
          if(*(arr+j)<t)
            *(arr+j-1)=*(arr+j);
          else
            break;
       }
      *(arr+j-1)=t;
    }
  }
}             
void mergesort(int *arr,int l,int u)
{
 if(l<u)
{ 
  int m;
  m=(l+u)/2;
mergesort(arr,l,m);
mergesort(arr,m+1,u);
merge(arr,l,m,u);
}

}

int main()
{
int n;
clock_t tstart,tstop;
cin>>n;
int arr[n];

for(int i=0;i<n;i++)
cin>>arr[i];
tstart=clock();
mergesort(&arr[0],0,n-1);
tstop=clock();
for(int i=0;i<n;i++)
cout<<arr[i]<<" ";
cout<<"\ntime :"<<tstop-tstart;
return 0;
}
