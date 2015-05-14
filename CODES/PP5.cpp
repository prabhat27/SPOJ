/*
Stock Buy Sell to Maximize Profit

*/

#include<iostream>
using namespace std;
int main()
{
    int arr[]={100, 180, 260, 310, 40, 535, 10};
    
    int i=0,j=1,n=sizeof(arr)/sizeof(int);
    int gain=0;
    int ans=0;
    
    while(i<n&&j<n)
    {
       while(arr[j]-arr[i]>gain)
       {
         gain=arr[j]-arr[i];
         j++;
       }
       ans+=gain;
       gain=0;
       i=j;
       j++;
    }
    cout<<ans;
   system("pause");
   return 0;
}
