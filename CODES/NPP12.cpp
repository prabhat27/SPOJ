/*
Tug of WarMarch 13, 2013
Given a set of n integers, divide the set in two subsets of n/2 sizes
each such that the difference of the sum of two subsets is as minimum as
possible. If n is even, then sizes of two subsets must be strictly n/2 and if
n is odd, then size of one subset must be (n-1)/2 and size of other subset must be (n+1)/2.
*/

#include<iostream>
#include<cmath>
using namespace std;
int arr[]={23, 45, -34, 12, 0, 98, -99, 4, 189, -1, 4};//{3, 4, 5, -3, 100, 1, 89, 54, 23, 20};//{3,2,1,-1};
int n=sizeof(arr)/sizeof(int);
int ans=9999;
int ts=0;
bool tsol[100];
bool fsol[100];
void f(int i,int hi,int sum)
{
  if(i>n)
   return ;
  if(hi==n/2)
  {
     int lsum=sum;
     int rsum=ts-sum;
     int dif=abs(lsum-rsum);
     if(dif<ans)
      {
        for(int i=0;i<n;i++)
        {
          //cout<<tsol[i]<<" ";
          fsol[i]=tsol[i];
        }
        ans=dif;
      }
      //cout<<endl<<lsum<<" "<<rsum;
     return;
  }
  tsol[i]=true;
  f(i+1,hi+1,sum+arr[i]);
  tsol[i]=false;
  f(i+1,hi,sum);

  return;
}

int main()
{
  for(int i=0;i<n;i++)
  {
    ts+=arr[i];
    tsol[i]=fsol[i]=false;
  }
  f(0,0,0);
  cout<<ans<<endl;

  for(int i=0;i<n;i++)
  if(fsol[i])
  cout<<arr[i]<<" ";

  system("pause");
  return 0;
}
