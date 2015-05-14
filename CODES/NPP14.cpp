#include<iostream>
using namespace std;
int main()
{
    int arr[]={1,2,3,4,5,6,7,4};
    int n=sizeof(arr)/sizeof(int);
    
    int x=0,y=0;
    for(int i=0;i<n;i++)
    {
      x=x^arr[i];
      y=y^(i+1);
    }
    y=y^n;
    cout<<(x^y);
    
    system("pause");
    return 0;
}
    
    
