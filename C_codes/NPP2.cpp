/*
Binary search to find the rotation point in a rotated sorted list
*/

#include<iostream>
using namespace std;

int arr[]={4,5,1,2,3};
int n=sizeof(arr)/sizeof(int);
   
int find(int low,int high)
{
    while (arr[low] > arr[high]) {
            int mid = (low + high) >> 1;
            if (arr[mid] > arr[high]) {
                low = mid + 1;
            } else {
                high = mid;
            }
        }
        return low;
  
}  
int main()
{

   cout<<find(0,n-1)<<endl;
   
   system("pause");
   return 0;
}
