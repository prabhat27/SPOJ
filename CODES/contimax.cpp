#include<iostream>
#include<algorithm>
using namespace std;

int main()
{
    int arr[]={-2, -3,-1};
    int n=sizeof(arr)/sizeof(int);
    
    int c=arr[0],s=0,e=0;
    int t=arr[0];
    
    for(int i=1;i<n;i++)
    {
      c=max(arr[i],c+arr[i]);
      t=max(t,c);
      {
        if(t==c)
         {
           if(c==arr[i])
            { s=i; e=i; }
            else
            e=i;
         }
      }
    }
    
    cout<<t<<" "<<s<<" "<<e<<endl;
    
    system("pause");
}
